# Routing Tables, Explained Simply
*NetPractice edition. The part that confuses most people.*

If you can already find a network address from an IP and a mask, you have all the math you need. Routing tables are **not** math. They are a logic puzzle: *"who do I ask to get there?"* This guide teaches a repeatable method so you never have to guess.

**Contents**
1. [The one idea behind routing tables](#1-the-one-idea-behind-routing-tables)
2. [Anatomy of one entry](#2-anatomy-of-one-entry)
3. [What a router does with a packet](#3-what-a-router-does-with-a-packet)
4. [How to find the next hop (the hand-on-the-cable trick)](#4-how-to-find-the-next-hop-the-hand-on-the-cable-trick)
5. [The method: the "who knows what" grid](#5-the-method-the-who-knows-what-grid)
6. [Example 1: two routers](#6-example-1-two-routers)
7. [Example 2: one router in the middle, three spokes](#7-example-2-one-router-in-the-middle-three-spokes)
8. [The default route `0.0.0.0/0`](#8-the-default-route-0000)
9. [Example 3: a LAN, a router, and the Internet](#9-example-3-a-lan-a-router-and-the-internet)
10. [When two entries match: most specific wins](#10-when-two-entries-match-most-specific-wins)
11. [Routing tables on PCs](#11-routing-tables-on-pcs)
12. [The 7 classic mistakes](#12-the-7-classic-mistakes)
13. [Practice exercises](#13-practice-exercises)
14. [Answers](#14-answers)
15. [Cheat card](#15-cheat-card)

---

## 1. The one idea behind routing tables

A router is like a person at a **crossroads**. People walk up and say: *"I need to get to Street X."*

The router can only answer two ways:

1. **"Street X is right here, one of my own streets."** → deliver it directly.
2. **"Street X isn't mine, but go ask my neighbor over there. They'll know."** → hand it to the neighbor.

A **routing table** is just the list of answers of type 2.

> **A router automatically knows the networks it is plugged into. You only write entries for networks it can NOT see directly.**

If you remember nothing else, remember that sentence. It tells you most of the table is *not* yours to write.

---

## 2. Anatomy of one entry

Every entry has two fields (NetPractice shows them as columns):

| Destination | Next hop |
|---|---|
| `10.0.3.0/24` | `10.0.2.2` |

Read it out loud as a sentence:

> **"For anything going to `10.0.3.0/24`, hand the packet to `10.0.2.2`."**

### Destination
- It is a **network**, written as `network address / mask`.
- It is the *far-away* place you want to reach, **not** a router and not a single PC.
- It must be a real **network address** (see your block-size trick). `10.0.3.0/24` ✅. `10.0.3.10/24` ❌ (that's a host inside the network, not the network's name).

### Next hop
- It is the **IP address of a neighboring router** (or device) that is on the way.
- It must be an address your router can **reach directly**, meaning it lies inside one of the networks your router is plugged into (usually the shared link between the two routers).
- It is **never** one of your own router's IPs, and **never** an address on a network that is far away.

---

## 3. What a router does with a packet

Every time a packet arrives, the router runs this tiny algorithm:

```
1. Is the destination inside one of MY directly attached networks?
      YES → deliver it directly. Done.

2. Otherwise, look through my routing table.
   Which entries's Destination contains the target IP?
      one match    → send to that Next hop.
      several      → use the most specific one (longest mask).  (Section 10)
      none         → throw the packet away. (The connection fails.)
```

Step 2's "none" is what happens when you forgot an entry. The packet doesn't wander, it just dies.

---

## 4. How to find the next hop (the hand-on-the-cable trick)

Say you're configuring **R1** and you need a route toward some far network.

1. Put your finger on R1.
2. Follow the cable that leads **toward** the far network.
3. The first device you hit on the other end is your neighbor.
4. **Next hop = that neighbor's IP address on the cable you just followed.**

```
   [R1] eth1 ─────────── eth0 [R2]
       10.0.2.1           10.0.2.2
                                \
  R1 wants to go "that way" →   next hop = 10.0.2.2
```

Two things people get wrong:

- Using the neighbor's IP on the **wrong** side (e.g. `10.0.3.1`, R2's far-side address). R1 can't reach that directly, so it's invalid. Use the IP on the **shared cable**.
- Using R1's own address (`10.0.2.1`). A router can't send to itself.

---

## 5. The method: the "who knows what" grid

This is the technique that turns routing from guesswork into bookkeeping.

**Step 1.** List **every network** in the diagram (every LAN and every router-to-router link).
**Step 2.** Make a grid: one row per network, one column per router.
**Step 3.** For each cell, write:
 - **direct**, if that router has an interface in that network (no entry needed), or
 - **via X**, where X is the next hop toward it (this is your routing table entry).

Then the routing table of each router is just *its column*, minus the "direct" cells.

You'll see this in action in the next two sections.

---

## 6. Example 1: two routers

```
 [PC-A] ── eth0 [R1] eth1 ═════ eth0 [R2] eth1 ── [PC-B]
  10.0.1.10      .1     .1        .2     .1        10.0.3.10
  └ 10.0.1.0/24 ┘ └ 10.0.2.0/30 ┘ └ 10.0.3.0/24 ┘
```

| Interface | IP |
|---|---|
| R1 eth0 | 10.0.1.1 (/24) |
| R1 eth1 | 10.0.2.1 (/30) |
| R2 eth0 | 10.0.2.2 (/30) |
| R2 eth1 | 10.0.3.1 (/24) |

### The grid

| Network | R1 | R2 |
|---|---|---|
| `10.0.1.0/24` (PC-A's LAN) | direct | **via `10.0.2.1`** |
| `10.0.2.0/30` (the link) | direct | direct |
| `10.0.3.0/24` (PC-B's LAN) | **via `10.0.2.2`** | direct |

### The tables (just the "via" cells)

**R1**
| Destination | Next hop |
|---|---|
| 10.0.3.0/24 | 10.0.2.2 |

**R2**
| Destination | Next hop |
|---|---|
| 10.0.1.0/24 | 10.0.2.1 |

### Why both are needed
- PC-A → PC-B: R1 needs "how to reach `10.0.3.0/24`" ✅ (R1's entry).
- PC-B's **reply** → PC-A: R2 needs "how to reach `10.0.1.0/24`" ✅ (R2's entry).

Forget one, and the request arrives but the reply never returns. It looks like "nothing works".

---

## 7. Example 2: one router in the middle, three spokes

A "hub" router (R1) connected to two other routers, plus its own LAN.

```
                 [R2] ── LAN 2: 10.2.0.0/24
                  │ eth0 = 10.0.0.2
                  │ (link 10.0.0.0/30)
                  │ eth1 = 10.0.0.1
 LAN 1 ──────── [ R1 ]
 10.1.0.0/24      │ eth2 = 10.0.0.5
                  │ (link 10.0.0.4/30)
                  │ eth0 = 10.0.0.6
                 [R3] ── LAN 3: 10.3.0.0/24
```

(R1's LAN-side interface is `10.1.0.1`.)

### The grid

| Network | R1 | R2 | R3 |
|---|---|---|---|
| LAN 1 `10.1.0.0/24` | direct | via `10.0.0.1` | via `10.0.0.5` |
| LAN 2 `10.2.0.0/24` | via `10.0.0.2` | direct | via `10.0.0.5` |
| LAN 3 `10.3.0.0/24` | via `10.0.0.6` | via `10.0.0.1` | direct |
| Link `10.0.0.0/30` | direct | direct | via `10.0.0.5` |
| Link `10.0.0.4/30` | direct | via `10.0.0.1` | direct |

### Reading the pattern
- **R1** (the hub) needs a *different* next hop for each spoke: LAN 2 goes left, LAN 3 goes right.
- **R2** and **R3** (the spokes) have only **one** way out: back through R1. Their "via" cells all say the same thing. That means they can use a single **default route** instead of listing everything (Section 8).

### The tables

**R1**
| Destination | Next hop |
|---|---|
| 10.2.0.0/24 | 10.0.0.2 |
| 10.3.0.0/24 | 10.0.0.6 |

**R2** (long version)
| Destination | Next hop |
|---|---|
| 10.1.0.0/24 | 10.0.0.1 |
| 10.3.0.0/24 | 10.0.0.1 |
| 10.0.0.4/30 | 10.0.0.1 |

**R2** (short version using a default route)
| Destination | Next hop |
|---|---|
| 0.0.0.0/0 | 10.0.0.1 |

**R3** (short version)
| Destination | Next hop |
|---|---|
| 0.0.0.0/0 | 10.0.0.5 |

> The links themselves (`10.0.0.0/30`, `10.0.0.4/30`) only matter if some device must talk to an address *on* a link. If the level only needs PCs to reach each other, you can leave them out. When in doubt, including them does no harm.

---

## 8. The default route `0.0.0.0/0`

`0.0.0.0/0` means **"every possible address"**. A mask of `/0` has zero network bits, so everything matches.

It acts as the **fallback**:

> *"If none of my specific entries match, send it this way."*

### When to use it
- A router that has **only one way out** (like R2 and R3 above), so you don't have to list everything behind that exit.
- A router facing **the Internet** (the Internet is "everything else").

### When NOT to use it
- On a router with **several** ways out. A default route can only point one way, so the other directions need specific entries (like R1 above).

### Where it sits in the decision
It's checked **last**. Any more specific entry beats it (Section 10).

---

## 9. Example 3: a LAN, a router, and the Internet

```
 [PC] ── eth0 [R1] eth1 ───── [ INTERNET ]
 192.168.5.10   .5.1  203.0.113.2    203.0.113.1
 └ 192.168.5.0/24 ┘ └─ 203.0.113.0/30 ─┘
```

R1 knows both of its own networks. Everything else on Earth is "the Internet", so one default route does it:

**R1**
| Destination | Next hop |
|---|---|
| 0.0.0.0/0 | 203.0.113.1 |

Note: the next hop `203.0.113.1` is on the **shared link**, as always.

The Internet side also needs a path *back* to your LAN. In NetPractice this is usually already handled for you. If it isn't, that's one more entry: `192.168.5.0/24 → 203.0.113.2`.

---

## 10. When two entries match: most specific wins

Sometimes a destination matches more than one entry. The router picks the one with the **longest mask** (the most specific). This is called *longest prefix match*.

### Example table

| Destination | Next hop |
|---|---|
| 10.0.0.0/8 | A |
| 10.1.0.0/16 | B |
| 0.0.0.0/0 | C |

| Packet is going to | Matches | Winner | Why |
|---|---|---|---|
| `10.1.5.5` | /8, /16, /0 | **B** | /16 is the most specific |
| `10.9.9.9` | /8, /0 | **A** | /8 beats /0 |
| `8.8.8.8` | /0 only | **C** | only the default matches |

Think of it as: *"specific instructions beat general instructions."* The default route is the most general instruction there is, so it only wins when nothing else applies.

---

## 11. Routing tables on PCs

In some levels, PCs/hosts don't have a "gateway" field but a small routing table. It works exactly the same way:

| Destination | Next hop |
|---|---|
| 0.0.0.0/0 | *(the router's IP on the PC's own LAN)* |

That is the same thing as a gateway: *"anything that isn't on my network, give to the router."*

The next hop must still be an address on the **PC's own network**.

---

## 12. The 7 classic mistakes

| # | Mistake | Fix |
|---|---|---|
| 1 | **Forgetting the return route.** Fixed R1 but not R2. | Routes must exist in *both* directions. Use the grid. |
| 2 | **Next hop is not directly reachable.** E.g. using a far-side IP of the neighbor. | Next hop must be inside a network your router is plugged into (the shared link). |
| 3 | **Next hop is the router's own IP.** | Use the **neighbor's** IP. |
| 4 | **Destination is a host IP, not a network address.** `10.0.3.10/24` | Write the network address: `10.0.3.0/24`. |
| 5 | **Wrong mask in the destination.** | Same mask as the real network uses. |
| 6 | **Adding routes for directly attached networks.** | Not needed; the router already knows them. |
| 7 | **Routing loop with default routes.** R1 default → R2 *and* R2 default → R1. | A packet for an unknown network bounces forever. Only one side should default toward the other, or use specific entries. |

### A closer look at mistake 7 (loops)

```
 R1 default → R2          R2 default → R1
```
A packet for network X (which neither knows) goes R1 → R2 → R1 → R2 → ... The packet never gets anywhere. Make sure that for every destination, following the arrows **ends** at the router that owns it.

---

## 13. Practice exercises

### Exercise 1: LAN → R1 → R2 → Internet

```
 [PC] ─ eth0 [R1] eth1 ═ eth0 [R2] eth1 ─ [INTERNET]
 192.168.5.0/24 │ 10.0.0.0/30 │ 203.0.113.0/30
 R1 eth0 = 192.168.5.1     R2 eth0 = 10.0.0.2
 R1 eth1 = 10.0.0.1        R2 eth1 = 203.0.113.2
                           Internet = 203.0.113.1
```
Write the routing tables for R1 and R2 so the PC can reach the Internet **and** replies can come back.

### Exercise 2: Spot the invalid next hop

R1 has interfaces `10.0.0.1/30` and `10.1.0.1/24`. Its table says:

| Destination | Next hop |
|---|---|
| 10.3.0.0/24 | 10.2.0.5 |

What's wrong?

### Exercise 3: Spot the loop

```
 [R1] ═══ [R2]
 R1: 0.0.0.0/0 → R2        R2: 0.0.0.0/0 → R1
 LAN X (10.9.0.0/24) hangs off R2.
```
A PC behind R1 pings `10.9.0.5`. Does it work? What about a ping to `10.50.0.5` (a network that exists nowhere)?

### Exercise 4: Which entry wins?

| Destination | Next hop |
|---|---|
| 172.16.0.0/16 | X |
| 172.16.8.0/24 | Y |
| 0.0.0.0/0 | Z |

Where do packets for (a) `172.16.8.20`, (b) `172.16.200.1`, (c) `1.1.1.1` go?

### Exercise 5: Write all three tables (chain with LANs)

```
 LAN A ─ [R1] ═══ [R2] ═══ [R3] ─ LAN C
 10.1.0.0/24  │      │      │   10.3.0.0/24
              │   LAN B     │
              │ 10.2.0.0/24 │
         172.16.0.0/30  172.16.0.4/30

 R1 eth1 = 172.16.0.1     R2 eth0 = 172.16.0.2
 R2 eth1 = 172.16.0.5     R3 eth0 = 172.16.0.6
```
(LAN B hangs off R2 on its own interface.) Write the tables so A, B and C can all reach each other.

---

## 14. Answers

### Exercise 1
**R1** (one exit only → default route)
| Destination | Next hop |
|---|---|
| 0.0.0.0/0 | 10.0.0.2 |

**R2** (needs a way back to the PC *and* a way out)
| Destination | Next hop |
|---|---|
| 192.168.5.0/24 | 10.0.0.1 |
| 0.0.0.0/0 | 203.0.113.1 |

R2 can't use only a default route, because "the Internet" and "back to R1" are two **different directions**.

### Exercise 2
The next hop `10.2.0.5` isn't inside either network R1 is attached to (`10.0.0.0/30` or `10.1.0.0/24`). R1 can't reach it directly, so the entry is invalid. The next hop must be a neighbor's IP on `10.0.0.0/30` (probably `10.0.0.2`) or on `10.1.0.0/24`.

### Exercise 3
- **Ping to `10.9.0.5`:** works. R1 has no specific entry, so it uses its default → R2. R2 owns `10.9.0.0/24` directly and delivers it. ✅ (Assuming replies are also routed back, which the default route handles.)
- **Ping to `10.50.0.5`:** **loops.** R1 sends to R2 (default), R2 doesn't own it and sends back to R1 (default), and so on until the packet expires. ❌

Lesson: with defaults pointing at each other, any unknown destination bounces.

### Exercise 4
(a) `172.16.8.20` → matches /16, /24, /0 → **Y** (/24 is most specific).
(b) `172.16.200.1` → matches /16 and /0 → **X**.
(c) `1.1.1.1` → only /0 → **Z**.

### Exercise 5

First the grid:

| Network | R1 | R2 | R3 |
|---|---|---|---|
| LAN A `10.1.0.0/24` | direct | via `172.16.0.1` | via `172.16.0.5` |
| LAN B `10.2.0.0/24` | via `172.16.0.2` | direct | via `172.16.0.5` |
| LAN C `10.3.0.0/24` | via `172.16.0.2` | via `172.16.0.6` | direct |
| Link `172.16.0.0/30` | direct | direct | via `172.16.0.5` |
| Link `172.16.0.4/30` | via `172.16.0.2` | direct | direct |

**R1**
| Destination | Next hop |
|---|---|
| 10.2.0.0/24 | 172.16.0.2 |
| 10.3.0.0/24 | 172.16.0.2 |
| 172.16.0.4/30 | 172.16.0.2 |

(or simply `0.0.0.0/0 → 172.16.0.2`, since R1 has only one way out)

**R2** (the middle router: two directions, so specific entries)
| Destination | Next hop |
|---|---|
| 10.1.0.0/24 | 172.16.0.1 |
| 10.3.0.0/24 | 172.16.0.6 |

**R3**
| Destination | Next hop |
|---|---|
| 10.1.0.0/24 | 172.16.0.5 |
| 10.2.0.0/24 | 172.16.0.5 |
| 172.16.0.0/30 | 172.16.0.5 |

(or simply `0.0.0.0/0 → 172.16.0.5`)

---

## 15. Cheat card

```
┌──────────────────────────────────────────────────────────────┐
│  ROUTING TABLE = "to reach [DESTINATION], ask [NEXT HOP]"    │
│                                                              │
│  • Directly attached networks → already known, NO entry.     │
│  • Destination = a NETWORK address + mask (never a host IP). │
│  • Next hop = neighbor's IP on the SHARED cable.             │
│  • Next hop must be reachable directly. Never your own IP.   │
│  • Write routes in BOTH directions (request + reply).        │
│  • Only one way out? Use 0.0.0.0/0.                          │
│  • Several ways out? Specific entries for each direction.    │
│  • Two matches? Longest mask wins; default is last.          │
│  • Unsure? Build the "who knows what" grid.                  │
└──────────────────────────────────────────────────────────────┘
```

**Quick self-test for any entry you wrote:**
1. Is the destination a real *network* address? ✔
2. Is the next hop inside a network *this* router is plugged into? ✔
3. Is the next hop *not* this router's own IP? ✔
4. Does the other side have the matching return route? ✔

If all four are yes, the entry is correct.