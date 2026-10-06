# How Routers and Switches Actually Work
*The device-level deep dive — a companion to `netpractice.md` and `netpractice2.md`*

The other two guides teach you how to *solve* NetPractice levels. This one explains what the boxes in the diagram are physically doing when a packet flies through them — including the one thing almost no beginner guide explains: **what happens to MAC addresses along the way**.

**Contents**
1. [Two devices, two jobs](#1-two-devices-two-jobs)
2. [The switch: a smart repeater with a memory](#2-the-switch-a-smart-repeater-with-a-memory)
3. [The router: a translator between networks](#3-the-router-a-translator-between-networks)
4. [The journey of a packet — hop by hop](#4-the-journey-of-a-packet--hop-by-hop)
5. [ARP: how an IP finds its MAC](#5-arp-how-an-ip-finds-its-mac)
6. [Broadcast domains vs collision domains](#6-broadcast-domains-vs-collision-domains)
7. [Switch vs router: the comparison table](#7-switch-vs-router-the-comparison-table)
8. [What this means for NetPractice](#8-what-this-means-for-netpractice)
9. [Common misconceptions](#9-common-misconceptions)

---

## 1. Two devices, two jobs

Both devices sit in the middle of cables and forward traffic. That's where the similarity ends.

```
              ┌──────────────────────────────┐
              │                              │
  Layer 2 ────│  SWITCH  (thinks in MACs)    │  connects devices
              │                              │  within ONE network
              └──────────────────────────────┘

              ┌──────────────────────────────┐
              │                              │
  Layer 3 ────│  ROUTER  (thinks in IPs)     │  connects DIFFERENT
              │                              │  networks together
              └──────────────────────────────┘
```

| Question | Switch | Router |
|---|---|---|
| What does it read? | MAC address (hardware, burned into the NIC) | IP address (logical, assigned by you) |
| What does it forward on? | "Which of my ports leads to this MAC?" | "Which next hop leads to this network?" |
| Where does it operate? | Inside one network | Between networks |
| Does it have its own IP? | No (unmanaged switch — invisible to IP) | Yes, **one per interface** |
| Appears in a traceroute? | Never | Yes, once per hop |

> **Analogy:** a switch is the mailroom clerk in your office building — it delivers internal mail to the right desk without ever reading the street address. A router is the post office — it only cares about the city/street part, and hands mail off to the next post office.

---

## 2. The switch: a smart repeater with a memory

A switch has no configuration to speak of (in NetPractice it has *zero* fields to edit). It works by **learning**. Here's the whole algorithm:

1. **Receive** a frame on some port.
2. **Read the destination MAC** from the frame header.
3. **Look in its MAC address table**: *"port 3 ↔ MAC AA:BB:CC:11"* etc.
   - **Found** → forward the frame out that one port only.
   - **Not found** → flood it out every port except the one it came in on (the right machine will answer, and the switch will learn).
4. **Learn**: while it's at it, note the *source* MAC of the frame and which port it arrived on. Store it in the table.

The MAC address table builds itself within seconds of the network starting:

```
Frame arrives on port 2, from MAC AA:BB:CC:11
  → switch learns:  AA:BB:CC:11  =  port 2   (table updated)

Frame for MAC 12:34:56:99? Look in table...
  → hit:  forward out port 5 only
  → miss: flood out all ports (except the arrival port)
```

### The three properties that make a switch a switch

- **Transparent.** PCs have no idea it's there. Two PCs connected through a switch behave *exactly* as if they were connected by a single cable — which is why in NetPractice a switch changes nothing about your IP configuration. Same cable or same switch = same network (Rule 1 in `netpractice2.md`).
- **One big broadcast domain.** A broadcast frame (destination MAC `FF:FF:FF:FF:FF:FF`) is always flooded to *everyone* on the switch. A switch **never** stops a broadcast.
- **Fast and dumb about IP.** The switch never looks at the IP header. It can forward IPv4, IPv6, ARP, anything — it only ever sees Ethernet.

> This is why NetPractice can't test your switch knowledge: the simulator's `sim.js` literally does "on switch: pass to all connections." There is nothing to configure.

---

## 3. The router: a translator between networks

A router is a machine with **several interfaces** (eth0, eth1, ...), each plugged into a *different* network, each with **its own IP address**. Its job: receive packets on one network and forward them toward another.

### What it checks for every packet

1. **Is this packet for me?** (destination IP = one of my own interfaces) → deliver locally, done.
2. **Otherwise, look up the destination IP in the routing table.** Not "which machine" — "which *network* does it live in?"
3. **Forward** the packet to the next hop, decrement **TTL** by 1. If TTL hits 0, the packet is dropped (this is what stops routing loops from circulating packets forever).

### The routing table and longest-prefix match

Each row says *"to reach network X, hand to next hop Y"*. When several rows match, the **most specific (longest) prefix wins**:

| Destination | Next hop |
|---|---|
| `10.0.3.0/24` | 10.0.2.2 |
| `10.0.0.0/8` | 10.0.4.9 |
| `0.0.0.0/0` (default) | 203.0.113.1 |

A packet for `10.0.3.7` matches all three rows — `/24` is the most specific, so it goes to `10.0.2.2`. The default route (`0.0.0.0/0`) is the catch-all: "if you know nothing better, send it this way."

### What the router already knows for free

Every network directly attached to one of its interfaces is automatically in the table (a **connected route**). You only add entries for networks the router *can't see* — exactly why Rule 3 in `netpractice2.md` exists.

### The gateway, restated

From a host's point of view, the router is invisible until the host needs it. A PC checks: *"Is the destination IP in my own network (my IP AND my mask)?"*
- **Yes** → deliver directly via the switch (ARP for the destination, send).
- **No** → hand the frame to the **gateway** — the router's interface IP *on the host's own network*. This is why a gateway must be in the host's own subnet: the host must be able to reach it *directly*, without any router in between.

---

## 4. The journey of a packet — hop by hop

Here's the part that ties everything together, and the bit the other two guides skip.

**The golden rule:**

> ### The destination IP never changes. The destination MAC changes at every hop.

The IP header is *end-to-end* (PC → final destination). The MAC header is *hop-to-hop* (only good for the next leg). Each router **strips off the old MAC header and writes a brand-new one** for the next hop.

Setup: PC-A wants to reach PC-B, one switch and two routers in between.

```
 [PC-A]──[Switch]──[R1]──────────────[R2]──[PC-B]
  10.0.1.10/24     │                  │    10.0.3.10/24
            10.0.1.1│10.0.2.1 10.0.2.2│10.0.3.1
```

What's on the wire at each stage (MACs shortened):

| Leg | Src MAC | Dst MAC | Src IP | Dst IP |
|---|---|---|---|---|
| PC-A → Switch | `aa` | **`r1a`** (R1's eth0) | 10.0.1.10 | 10.0.3.10 |
| R1 → R2 | `r1b` | **`r2a`** (R2's eth0) | 10.0.1.10 | 10.0.3.10 |
| R2 → PC-B | `r2b` | **`bb`** (PC-B's NIC) | 10.0.1.10 | 10.0.3.10 |

Notice:

- The **IP columns never change** — PC-B always sees the real sender.
- Each leg uses a different destination MAC, but the switch only ever saw *one* of those frames (leg 1) — the routers' legs bypass it entirely, because R1→R2 is a point-to-point link with no switch needed.
- The switch in this picture forwards based on `r1a` — a MAC *inside its own network*. It never has a clue that 10.0.3.10 exists.

**And the return trip?** Every step happens in reverse — which is why routing tables are needed in *both* directions. A one-way route gives you sent packets and lost replies.

---

## 5. ARP: how an IP finds its MAC

One loose end: the PC wants to reach IP `10.0.3.10` via gateway `10.0.1.1` — but Ethernet frames need a *MAC*. Where does it come from?

**ARP (Address Resolution Protocol)** — a two-message shout:

1. **Broadcast:** *"Who has 10.0.1.1? Tell 10.0.1.10!"* — sent to MAC `FF:FF:FF:FF:FF:FF`, so the switch floods it to everyone.
2. **Reply (unicast):** *"10.0.1.1 is at MAC r1a."* — the switch learns this MAC too, and the PC caches the answer.

Each host and each router interface runs ARP for every next hop it needs — PC-A ARPs for its gateway, R1 ARPs for R2's interface on the link, and so on. Results are cached, so it only happens occasionally.

This is the one place Layer 2 and Layer 3 visibly shake hands: **ARP translates the IP you care about into the MAC the hardware needs.** It's also why the switch — pure Layer 2 — participates in an IP world without ever understanding an IP packet.

---

## 6. Broadcast domains vs collision domains

Two "domains" people confuse, defined by which device stops what:

```
 [PC] [PC] [PC]
   │    │    │
  ─┴────┴────┴─  SWITCH          [SWITCH]──[ROUTER]──[SWITCH]
        │                                                     │
   broadcast domain #1 ◄── router stops broadcasts here ──► broadcast domain #2
        │
   (modern switched LANs: no collision domains inside)
```

| Boundary | Stopped by |
|---|---|
| **Broadcast domain** (where "shout to everyone" reaches) | **Router only** — every router interface is a wall |
| **Collision domain** (who can "talk over" whom) | **Switch** (one per port, on modern switches) |

This is the deepest job of a router: it doesn't just *move* packets between networks — it **defines** where networks end. One network = one broadcast domain = one subnet = one side of a router interface. That's the theory-level reason behind NetPractice Rule 2 (*a router interface's IP must belong to the network on its side*).

---

## 7. Switch vs router: the comparison table

| | **Switch** | **Router** |
|---|---|---|
| OSI layer | Layer 2 (data link) | Layer 3 (network) |
| Address it reads | MAC (48-bit, `aa:bb:cc:11:22:33`) | IP (32-bit, `10.0.1.10`) |
| Table it uses | MAC table (learned automatically) | Routing table (configured / exchanged) |
| Own IP address | No | Yes — one per interface |
| Connects | Devices **within** a network | **Different networks** to each other |
| Config in NetPractice | None — invisible | IP + mask per interface, plus routing table |
| Stops broadcasts? | No — floods them | Yes — that's the point |
| Default route concept | N/A | `0.0.0.0/0` |
| Real-world example | The 8-port box under your desk | Your home Wi-Fi box (it's a router + more) |

> **Home Wi-Fi box trivia:** the "router" in your home is actually a router + switch + Wi-Fi access point + NAT firewall in one plastic shell. The 4 LAN ports are a switch (same network as your PCs); the WAN port is the router side facing your ISP's network.

---

## 8. What this means for NetPractice

NetPractice hides the entire Layer 2 world — no MACs, no ARP, no switch config. It is a pure Layer 3 game. So the mapping is:

| Concept in this doc | In NetPractice you... |
|---|---|
| Switch learning MACs | Nothing — the switch is a black box that "just works" |
| MAC rewriting at each hop | Nothing — invisible; only IP matters |
| Router = one IP per interface | Configure **every router interface**: IP + mask, each in the network on its side |
| Connected routes are automatic | Only add routing-table rows for networks the router **isn't** plugged into |
| Longest-prefix match | Rarely matters — use specific routes or `0.0.0.0/0` default |
| Gateway must be reachable directly | Host's gateway = the router interface IP **in the host's own subnet** |
| Routes needed in both directions | Check the **return path** — the #1 forgotten fix |

**The mental model for any level:** a switch is a room where everyone can talk to everyone; a router is a door between rooms, and it needs a mouth (interface IP) on each side and a signpost (routing table) for rooms it can't see.

---

## 9. Common misconceptions

1. **"The switch assigns the IPs."** No — nothing assigns anything in NetPractice; *you* type the IPs. And a switch has no idea what an IP is anyway.
2. **"A router needs a switch to work."** No. A router forwards between its own interfaces. A switch is only needed when you want to plug *several* devices into one router interface (one network).
3. **"The destination MAC is the final destination's MAC."** Only on the *last* hop. On every earlier hop, the destination MAC is the **next router's** interface. (This is the classic exam trap.)
4. **"Two devices on the same switch are automatically on the same network."** They *can* be — but the network is decided by IP + mask, not by the switch. Two hosts on one switch with mismatched masks can still fail to talk. The switch delivers frames; correctness is your Layer 3 job.
5. **"A router interface can share a subnet with its other interface."** Never — Rule 2. Each interface *is* the boundary of a different network.
6. **"The routing table needs an entry for every device."** No — entries are per **network** (destination + mask), not per host. One `/24` row covers 254 machines.
7. **"If the packet gets there, the connection works."** No — replies must find their way back. Every route you add needs a mirror on the way back.

---

*For the solving method and worked levels, see `netpractice.md` (the complete guide) and `netpractice2.md` (the simple version).*
