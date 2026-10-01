# NetPractice, Explained Simply
*The "I read the guide and still don't get it" version*

This guide throws away most of the theory and keeps only what you need to solve the levels. Read it in order. Every section builds on the one before.

**Contents**
1. [The big picture (60 seconds)](#1-the-big-picture-60-seconds)
2. [The 3 rules that solve everything](#2-the-3-rules-that-solve-everything)
3. [Reading a mask without binary](#3-reading-a-mask-without-binary-the-block-trick)
4. [Finding the network, broadcast and usable range](#4-finding-the-network-broadcast-and-usable-range)
5. [Are two devices on the same network?](#5-are-two-devices-on-the-same-network)
6. [Routers: why they exist and what a gateway is](#6-routers-why-they-exist-and-what-a-gateway-is)
7. [Routing tables in plain words](#7-routing-tables-in-plain-words)
8. [A packet's journey (why it all fits together)](#8-a-packets-journey-why-it-all-fits-together)
9. [Full walkthrough: fixing a broken level](#9-full-walkthrough-fixing-a-broken-level)
10. [Your checklist for any level](#10-your-checklist-for-any-level)
11. [Practice exercises](#11-practice-exercises)
12. [Answers](#12-answers)
13. [Things that confuse everyone](#13-things-that-confuse-everyone)

---

## 1. The big picture (60 seconds)

Imagine a city.

- An **IP address** is a full address: *"Baker Street, house 12"*.
- The **subnet mask** says where the street name ends and the house number begins.
- A **network** is one street. Everyone on the street can walk to each other's door directly.
- A **router** is a crossroads connecting two streets. If you want to visit someone on another street, you walk to the crossroads first, and it sends you down the right street.
- A **gateway** is just "the crossroads on my street". It's the address of the router on *your* street.
- A **routing table** is a signpost at the crossroads: *"to reach Street X, go this way."*

That's all NetPractice is. Your job is to make sure:
1. People who should be on the same street really are on the same street.
2. Every crossroads is on the streets it connects.
3. Every crossroads has signposts for streets it can't see directly.

---

## 2. The 3 rules that solve everything

### Rule 1: Same cable or same switch = same network
Everything connected **without a router in between** must be on the **same network** and must use the **same mask**.

### Rule 2: A router has one address per network it touches
Each router interface (eth0, eth1, ...) sits on a **different** network, and its IP must belong to the network on its side. Two interfaces of one router can **never** be on the same network.

### Rule 3: A router only knows its own neighbors
A router automatically knows networks plugged directly into it. For every other network, you must write a routing table entry: *"to reach network X, send to router Y."*

**Almost every NetPractice bug breaks one of these three rules.** When you're stuck, ask yourself which one is broken.

---

## 3. Reading a mask without binary (the "block trick")

You *can* do everything in binary, but there's a shortcut. A mask tells you the **block size**, which is how many addresses fit in one network.

### The only table you need to memorize

| Mask | Short form | Block size | Usable hosts |
|---|---|---|---|
| 255.255.255.0   | /24 | 256 | 254 |
| 255.255.255.128 | /25 | 128 | 126 |
| 255.255.255.192 | /26 | 64  | 62 |
| 255.255.255.224 | /27 | 32  | 30 |
| 255.255.255.240 | /28 | 16  | 14 |
| 255.255.255.248 | /29 | 8   | 6 |
| 255.255.255.252 | /30 | 4   | 2 |

(The `/24` just means "24 bits are the network part". More bits for the network = smaller blocks.)

**Why "usable" is 2 less than block size:** the first address of each block is the network's *name* and the last is the *broadcast* ("shout to everyone"). Neither can be given to a device.

### The pattern to notice
Every time you add 1 to the slash number, the block size **halves**:
`/24 = 256 → /25 = 128 → /26 = 64 → /27 = 32 → /28 = 16 → /29 = 8 → /30 = 4`

### Which number is the "interesting" one?
Look at the mask `255.255.255.192`. The first three `255`s mean "these octets are fully network, ignore them". Only the **last octet (192)** is interesting. That's where the block size applies.

If the mask is `255.255.240.0` (/20), the interesting octet is the **third** one (240), and the block size is `256 − 240 = 16`, counted in the third octet.

> **Block size = 256 − (the interesting mask number)**
> 256 − 192 = 64, 256 − 224 = 32, 256 − 240 = 16, 256 − 248 = 8, 256 − 252 = 4

### Why this works (optional, for the curious)
192 in binary is `11000000`. The two `1`s are network bits, the six `0`s are host bits. Six host bits = 2⁶ = 64 addresses per block. The block trick is just that calculation done for you.

---

## 4. Finding the network, broadcast and usable range

**Recipe** (using the interesting octet only):

1. Compute the block size (256 − mask number).
2. List the multiples of the block size: `0, 64, 128, 192` (for block 64).
3. Find which two multiples your IP falls between. The lower one is the **network address**.
4. The **broadcast** is (next multiple − 1).
5. **Usable** = network + 1 up to broadcast − 1.

### Example 1: `192.168.1.77 /26`

- Block size = 256 − 192 = **64**
- Multiples: 0, 64, 128, 192
- 77 is between 64 and 128

| | |
|---|---|
| Network | 192.168.1.**64** |
| Broadcast | 192.168.1.**127** (128 − 1) |
| Usable | 192.168.1.65 → 192.168.1.126 |

```
.0 ───────── .63 | .64 ───────── .127 | .128 ───────── .191 | .192 ──── .255
   block 1       |  block 2 ← .77 is here | block 3        | block 4
```

### Example 2: `10.0.0.200 /28`

- Block size = 256 − 240 = **16**
- Multiples: 0, 16, 32, ..., 176, **192**, 208, ...
- 200 is between 192 and 208

| | |
|---|---|
| Network | 10.0.0.**192** |
| Broadcast | 10.0.0.**207** |
| Usable | 10.0.0.193 → 10.0.0.206 |

### Example 3 (a trap!): `172.16.5.100 /30`

- Block size = **4**
- Multiples of 4: ..., 96, **100**, 104, ...
- 100 *is* a multiple of 4, so it's the **start of a block**.

| | |
|---|---|
| Network | 172.16.5.**100** ← the IP you were given! |
| Broadcast | 172.16.5.103 |
| Usable | 172.16.5.101 and 172.16.5.102 only |

So `172.16.5.100/30` is **not a valid device address**, because it's the network's own name. NetPractice loves this trap.

### Example 4 (interesting octet is the third): `10.1.37.5 /20`

Mask `255.255.240.0` → interesting octet is the 3rd, block size 16.
Multiples: 0, 16, 32, 48 ... and 37 is between 32 and 48.

| | |
|---|---|
| Network | 10.1.**32**.0 |
| Broadcast | 10.1.**47**.255 |
| Usable | 10.1.32.1 → 10.1.47.254 |

(Octets *after* the interesting one go to all-zeros for the network, all-255 for the broadcast.)

---

## 5. Are two devices on the same network?

**Compute the network address of each one. If they match, same network. If not, different.** Never judge by "the numbers look similar".

### Example: three PCs, all `/26`

| PC | IP/mask | Block | Network |
|---|---|---|---|
| A | 192.168.0.10/26 | 0–63 | 192.168.0.**0** |
| B | 192.168.0.70/26 | 64–127 | 192.168.0.**64** |
| C | 192.168.0.50/26 | 0–63 | 192.168.0.**0** |

- A and C are on the **same** network, so they can talk directly.
- B looks almost identical (`192.168.0.x`) but is in a **different** block. It can't talk to A without a router.

### Same network, but different masks?
`192.168.5.10/24` and `192.168.5.20/16`: the IPs look alike, but one says "my street is `192.168.5.0`" and the other says "my street is `192.168.0.0`". They disagree about where the street even is. **Everyone on a network must use the same mask.**

---

## 6. Routers: why they exist and what a gateway is

A PC can only talk **directly** to devices on its own network. For anything else, it hands the packet to its **gateway** (a router), and says "you deal with it."

```
 PC-A ──── eth0 [ Router ] eth1 ──── PC-B
  192.168.30.10    .30.1    .31.1     192.168.31.10
  └─ network 192.168.30.0/24 ─┘ └─ network 192.168.31.0/24 ─┘
```

Key facts:
- The router has **two** IPs: one on each side. `192.168.30.1` is on PC-A's street, `192.168.31.1` is on PC-B's street.
- PC-A's gateway = **`192.168.30.1`** (the router's address *on PC-A's own street*).
- PC-B's gateway = **`192.168.31.1`**.
- A gateway must always be **inside your own network**. A PC can't "walk" to a gateway on a different street, because it has to reach it directly.

> In some levels hosts don't have a "gateway" field. Instead they have a small routing table where you put a **default route** (see next section) pointing at the router. It's the same idea.

---

## 7. Routing tables in plain words

Each line of a routing table means:

> **"If a packet is going to [Destination network], send it to [Next hop]."**

| Field | What to put |
|---|---|
| **Destination** | A network (like `10.0.3.0/24`), the *far-away* one you want to reach |
| **Next hop** | The IP of the **neighboring router** on the way there. It must be an address you can reach *directly* (on a network the router is plugged into) |

### The default route: `0.0.0.0/0`
This means *"anything I don't have a specific rule for, send it this way"*. Use it when there's one exit (like "the Internet", or one big direction) so you don't need to list every network.

> Think of it as: *"if you don't know where it is, ask that guy."*

### What the router already knows
A router **automatically** knows the networks of its own interfaces. You only write entries for networks it is **not** directly plugged into.

### Example

```
 PC-A ── [R1] ══════ [R2] ── PC-B
  10.0.1.0/24   10.0.2.0/30    10.0.3.0/24
```

R1 is plugged into `10.0.1.0/24` and `10.0.2.0/30`. It has **no idea** `10.0.3.0/24` exists. So:

| Router | Destination | Next hop | Meaning |
|---|---|---|---|
| R1 | 10.0.3.0/24 | 10.0.2.2 | "To reach PC-B's network, ask R2" |
| R2 | 10.0.1.0/24 | 10.0.2.1 | "To reach PC-A's network, ask R1" |

You need **both** lines. Without R2's line, PC-A's message arrives but PC-B's *reply* gets lost, so the connection still fails.

---

## 8. A packet's journey (why it all fits together)

Let's follow PC-A (`10.0.1.10`) pinging PC-B (`10.0.3.10`) in the example above.

1. **PC-A thinks:** "Is `10.0.3.10` on my network (`10.0.1.0/24`)? No. So I send it to my gateway `10.0.1.1`." → *needs the correct gateway.*
2. **R1 receives it.** R1 checks its table: "`10.0.3.0/24`? That's not directly attached, but I have a rule: next hop `10.0.2.2`." → *needs the route.*
3. **R2 receives it** (R1 could reach `10.0.2.2` directly because they share the `10.0.2.0/30` link). R2 thinks: "`10.0.3.10`? That's on my eth1 network! I deliver directly." → *needs R2's eth1 to be on `10.0.3.0/24`.*
4. **PC-B receives it.** Now it replies, and the same journey happens backwards: PC-B → R2 → (route to `10.0.1.0/24` via `10.0.2.1`) → R1 → PC-A.

If **any** of those steps is wrong, the ping dies. That's why the checklist is so strict: it's a chain, and a single broken link breaks everything.

---

## 9. Full walkthrough: fixing a broken level

Here's a made-up "level" so you can see the whole process.

**Goal:** PC1 must reach PC2.

```
 [PC1] ── eth0 [R1] eth1 ═══ eth0 [R2] eth1 ── [PC2]
```

### The broken configuration

| Device | IP | Mask | Gateway |
|---|---|---|---|
| PC1 | 172.16.0.10 | /24 | 172.16.0.1 |
| R1 eth0 | 172.16.0.1 | /24 | |
| R1 eth1 | 10.10.10.1 | /30 | |
| R2 eth0 | 10.10.10.5 | /30 | |
| R2 eth1 | 172.16.1.1 | /24 | |
| PC2 | 172.16.1.10 | /24 | 172.16.1.1 |

Routing tables: both empty.

### Step 1: Group by segment (Rule 1)

There are three segments:
- **Segment A:** PC1 + R1 eth0
- **Segment B (the link):** R1 eth1 + R2 eth0
- **Segment C:** R2 eth1 + PC2

### Step 2: Check each segment's network addresses

**Segment A:** PC1 `172.16.0.10/24` → network `172.16.0.0`. R1 eth0 `172.16.0.1/24` → network `172.16.0.0`. ✅ Same.

**Segment C:** R2 eth1 `172.16.1.1/24` → `172.16.1.0`. PC2 `172.16.1.10/24` → `172.16.1.0`. ✅ Same.

**Segment B (the link, /30, block size 4):**
- R1 eth1 `10.10.10.1`: multiples of 4 → 0, 4, 8... → 1 is in block **0–3** → network `10.10.10.0`
- R2 eth0 `10.10.10.5`: 5 is in block **4–7** → network `10.10.10.4`

❌ **Different networks!** That's the bug. They're plugged into the same cable but disagree on which street they're on.

### Step 3: Fix it

Put R2 eth0 in the same block as R1 eth1: block `10.10.10.0–3` has usable addresses `.1` and `.2`. R1 already uses `.1`, so:

**R2 eth0 → `10.10.10.2/30`** ✅

### Step 4: Gateways

PC1's gateway `172.16.0.1` is inside its own network ✅. PC2's gateway `172.16.1.1` ✅.

### Step 5: Routing tables (Rule 3)

R1 knows: `172.16.0.0/24` and `10.10.10.0/30`. Missing: `172.16.1.0/24`.
R2 knows: `10.10.10.0/30` and `172.16.1.0/24`. Missing: `172.16.0.0/24`.

| Router | Destination | Next hop |
|---|---|---|
| R1 | 172.16.1.0/24 | 10.10.10.2 |
| R2 | 172.16.0.0/24 | 10.10.10.1 |

### Step 6: Re-check

Walk the packet journey from Section 8 once more, both directions. ✅ Done.

---

## 10. Your checklist for any level

Do this **in order**, every time:

1. ☐ **Read the goal.** Who must reach whom? Don't touch irrelevant stuff.
2. ☐ **Draw the segments.** Everything joined without a router = one segment.
3. ☐ **Per segment:** compute each device's network address (Section 4). All must match, with the same mask.
4. ☐ **No device uses its network address or broadcast address** (watch out for `/30`, `/29`, `/28`!).
5. ☐ **Router interfaces:** each one is on the network of its own side, and no two interfaces of the same router share a network.
6. ☐ **Gateways:** each host's gateway is the router's IP *on the host's own network*.
7. ☐ **Routing tables:** for every network a router is *not* directly plugged into, add `destination → next hop`. Do it in **both directions**.
8. ☐ **Size check:** if a segment needs N hosts, is the mask big enough? (Not too small, and not far too big.)
9. ☐ **Final trace:** walk a packet from source to destination and back.

**Debugging tip:** if something is *almost* right, check the **mask** before you touch the IP. A wrong mask is the most common hidden bug.

---

## 11. Practice exercises

Try these on paper first. Answers are in the next section.

### Exercise 1: Network, broadcast, usable range
a) `192.168.1.200 /27`
b) `10.0.0.45 /29`
c) `172.16.3.130 /25`
d) `192.168.9.64 /30`. Is this a valid device address?

### Exercise 2: Same network?
For each pair, say yes or no:
a) `192.168.1.10/24` and `192.168.1.200/24`
b) `192.168.1.10/26` and `192.168.1.100/26`
c) `10.0.0.5/28` and `10.0.0.20/28`
d) `10.0.0.5/28` and `10.0.0.14/28`

### Exercise 3: Which mask?
What's the smallest block (biggest slash number) that fits:
a) 12 hosts
b) 50 hosts
c) 2 hosts (a router-to-router link)
d) 6 hosts

### Exercise 4: Spot the bug
```
 [PC1] ── [R1] eth1 ════ eth0 [R2] ── [PC2]

 R1 eth1: 10.0.0.1/30
 R2 eth0: 10.0.0.6/30
```
What's wrong, and what's a valid fix?

### Exercise 5: Write the routing tables
```
 [PC-A] ─ [R1] ═════ [R2] ═════ [R3] ─ [PC-C]
  192.168.1.0/24  10.0.0.0/30  10.0.0.4/30  192.168.3.0/24

 R1 eth1 = 10.0.0.1     R2 eth0 = 10.0.0.2
 R2 eth1 = 10.0.0.5     R3 eth0 = 10.0.0.6
```
R2 is in the middle. What does each router's table need so PC-A and PC-C can talk?

---

## 12. Answers

### Exercise 1
**a) `192.168.1.200 /27`**: block 32, multiples ... 192, 224. 200 is in 192–223.
Network `192.168.1.192`, broadcast `192.168.1.223`, usable `.193 – .222`.

**b) `10.0.0.45 /29`**: block 8, multiples ... 40, 48. 45 is in 40–47.
Network `10.0.0.40`, broadcast `10.0.0.47`, usable `.41 – .46`.

**c) `172.16.3.130 /25`**: block 128, multiples 0, 128. 130 is in 128–255.
Network `172.16.3.128`, broadcast `172.16.3.255`, usable `.129 – .254`.

**d) `192.168.9.64 /30`**: block 4, and 64 is a multiple of 4, so it is the **network address**. ❌ **Not valid** for a device. Valid addresses in that block: `.65` and `.66`.

### Exercise 2
a) **Yes.** Both in `192.168.1.0/24`.
b) **No.** `.10` is in 0–63, `.100` is in 64–127.
c) **No.** `.5` is in block 0–15, `.20` is in block 16–31.
d) **Yes.** `.5` and `.14` are both in 0–15 (and `.14` is the last usable address; `.15` is the broadcast).

### Exercise 3
a) 12 hosts → `/28` (14 usable). A `/29` only gives 6.
b) 50 hosts → `/26` (62 usable). A `/27` only gives 30.
c) 2 hosts → `/30`.
d) 6 hosts → `/29` (exactly 6 usable).

### Exercise 4
R1 eth1 `10.0.0.1/30` is in block 0–3 (network `10.0.0.0`). R2 eth0 `10.0.0.6/30` is in block 4–7 (network `10.0.0.4`). They're on the same cable but different networks.
**Fix:** `R2 eth0 → 10.0.0.2/30` (the other usable address in R1's block).

### Exercise 5
Each router needs a route to every network it isn't directly attached to.

| Router | Destination | Next hop | Why |
|---|---|---|---|
| R1 | 10.0.0.4/30 | 10.0.0.2 | the R2–R3 link, via R2 |
| R1 | 192.168.3.0/24 | 10.0.0.2 | PC-C's LAN, via R2 |
| R2 | 192.168.1.0/24 | 10.0.0.1 | PC-A's LAN, via R1 |
| R2 | 192.168.3.0/24 | 10.0.0.6 | PC-C's LAN, via R3 |
| R3 | 10.0.0.0/30 | 10.0.0.5 | the R1–R2 link, via R2 |
| R3 | 192.168.1.0/24 | 10.0.0.5 | PC-A's LAN, via R2 |

**Shortcut:** R1 and R3 are at the "ends", so each of them could use a single default route instead:
- R1: `0.0.0.0/0 → 10.0.0.2`
- R3: `0.0.0.0/0 → 10.0.0.5`

R2 is in the middle and needs two specific routes because it has to choose between two directions.

---

## 13. Things that confuse everyone

**"Why can't I use the first and last address?"**
The first is the network's name (like the street name itself) and the last is the broadcast ("shout to the whole street"). Neither belongs to a single house.

**"The IPs look similar, why don't they connect?"**
Looking similar means nothing. Only the *computed network address* matters. `192.168.0.10/26` and `192.168.0.70/26` are on different networks.

**"Do I put the router's own IP as the next hop?"**
No. The next hop is the **other** router's IP (the neighbor you're sending to), and it must be on a network you share with that neighbor.

**"Why do I need routes in both directions?"**
Because communication is a conversation. The request needs a path there, and the reply needs a path back.

**"What's the difference between gateway and next hop?"**
Same idea, different place. A *gateway* is what a **host** uses to leave its network. A *next hop* is what a **router** uses in its routing table. Both mean "the address to hand the packet to next."

**"My level has an Internet cloud. What do I do?"**
The Internet is just "everything else". Give the router facing it a **default route** (`0.0.0.0/0`) pointing toward the Internet side, so anything it doesn't know goes out there.

**"I fixed one thing and another connection broke."**
Normal. Re-run the checklist for the segment you just touched. Often you changed a mask and forgot that the other devices on that segment need the same mask.

---

### One-sentence summary
> *Put things that share a cable on the same network (same mask), give each router one address per side, and tell each router how to reach the networks it can't see.*

Good luck! 🍀