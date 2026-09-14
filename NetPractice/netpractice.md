# NetPractice — Complete Study Guide
*IP addressing, subnetting, and routing for 42 School's NetPractice project*

## Table of Contents
1. [What Is NetPractice?](#1-what-is-netpractice)
2. [IP Addresses — The Basics](#2-ip-addresses--the-basics)
3. [Binary ⇄ Decimal](#3-binary--decimal-the-skill-everything-else-depends-on)
4. [Subnet Masks & CIDR Notation](#4-subnet-masks--cidr-notation)
5. [Network Address, Broadcast Address, Usable Range](#5-network-address-broadcast-address-usable-range)
6. [Subnetting — Dividing a Network](#6-subnetting--dividing-a-network)
7. [VLSM — Variable-Length Subnet Masking](#7-vlsm--variable-length-subnet-masking)
8. [Routers, Gateways & Why They Matter](#8-routers-gateways--why-they-matter)
9. [Routing Tables](#9-routing-tables)
10. [Reading the NetPractice Interface](#10-reading-the-netpractice-interface)
11. [Step-by-Step Method for Any Level](#11-step-by-step-method-for-any-level)
12. [Worked Examples, Level by Level](#12-worked-examples-level-by-level)
13. [Real-Life Examples](#13-real-life-examples)
14. [Common Mistakes](#14-common-mistakes)
15. [Cheat Sheet](#15-cheat-sheet)
16. [Glossary](#16-glossary)

---

## 1. What Is NetPractice?

NetPractice is a 42 School common-core project that teaches IPv4 addressing, subnet masks, and routing through a web-based training interface — no code involved. You're handed a network diagram (PCs, switches, routers, cables) that is **broken**, and you fix it by editing IP addresses, subnet masks, and routing tables until every connection that's supposed to work, does.

**What to expect:**
- The project has **10 levels**, each a different broken topology.
- Difficulty ramps up steadily: Level 1–2 are single-cable, two-device problems. By Level 9–10 you're configuring several routers, full routing tables, and subnets of different sizes (VLSM) at once.
- Every PC and every router *interface* has two editable fields: an **IP address** and a **subnet mask**. Routers additionally have a **routing table** you fill in.
- The interface marks which devices must reach which. Your job is to satisfy every required connection without breaking one that already works.
- Your numbers are randomized per account — nobody gets the exact same level as you. This guide teaches the *method*, not an answer key, so it transfers to whatever numbers you're given.

**Where this sits in networking theory (briefly):** switches operate at Layer 2 and forward traffic using MAC addresses within a single network; routers operate at Layer 3 and forward traffic between different networks using IP addresses. NetPractice is entirely a Layer 3 exercise — you will never touch a MAC address — so everything below is about IP.

---

## 2. IP Addresses — The Basics

An **IPv4 address** is a 32-bit number that identifies a device on a network. To make it human-readable, it's split into four 8-bit chunks called **octets**, each written as a decimal number from 0–255, separated by dots:

```
192 . 168 . 1 . 10
 ↑      ↑    ↑   ↑
octet1 octet2 octet3 octet4   (32 bits total, 8 bits each)
```

Every IP address conceptually has two parts:
- **Network portion** — identifies *which network* the device is on (like a street name).
- **Host portion** — identifies *which device* on that network (like a house number).

Where the split happens between these two parts isn't fixed — it's defined by the **subnet mask** (Section 4). This is the single most important idea in the whole project: **the same IP address means a different network depending on the mask attached to it.** `192.168.1.10` with one mask and `192.168.1.10` with another mask can belong to two completely different networks.

**The one rule that governs every NetPractice level:**
> Two devices can talk directly (no router needed) **only if they compute the same network address** — i.e., their IP + mask combination produces an identical network portion. If a router sits between them, each side just needs to be valid on its *own* local network, and the router needs an interface that belongs to *each* of those networks.

---

## 3. Binary ⇄ Decimal: The Skill Everything Else Depends On

Subnet masks and network boundaries only make sense in binary. Every calculation in this guide reduces to this one skill, so it's worth drilling until it's automatic.

### The 8 place values of one octet

```
128   64   32   16   8   4   2   1
```

These are powers of two (2⁷ down to 2⁰). Any number 0–255 is some combination of these switched "on" (1) or "off" (0).

### Decimal → Binary, step by step

Go left to right through the place values. At each one, ask: *"does this value fit into what's left of my number?"* If yes, write `1` and subtract it. If no, write `0` and move on.

**Example: convert 182**

| Place value | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
|---|---|---|---|---|---|---|---|---|
| Fits? | 182≥128 ✓ | 54≥64 ✗ | 54≥32 ✓ | 22≥16 ✓ | 6≥8 ✗ | 6≥4 ✓ | 2≥2 ✓ | 0≥1 ✗ |
| Bit | **1** | **0** | **1** | **1** | **0** | **1** | **1** | **0** |

Result: `182 = 10110110` (check: 128+32+16+4+2 = 182 ✓)

### Binary → Decimal

Just add up the place values wherever there's a `1`.

`11000000` → 128 + 64 = **192**
`11111111` → 128+64+32+16+8+4+2+1 = **255**
`00000000` → **0**

### Why this matters

A subnet mask like `255.255.255.192` is really `11111111.11111111.11111111.11000000` — and whether two devices are on the same network comes down to comparing bits, not the decimal numbers you see on screen. Once binary feels natural, subnetting stops being mysterious.

---

## 4. Subnet Masks & CIDR Notation

A **subnet mask** marks, bit by bit, which part of an IP address is the network portion and which is the host portion: `1` = network bit, `0` = host bit. It's always written as four octets, same shape as an IP address, e.g. `255.255.255.0`.

**The mask's 1s are always contiguous, starting from the left.** `255.255.255.0` is valid. Something like `255.0.255.0` is never a valid subnet mask — real networking (and NetPractice) doesn't allow gaps.

Because the 1s are always contiguous, a mask can be written more compactly as **CIDR notation**: a slash followed by the *count* of 1-bits. `255.255.255.0` has 24 one-bits, so it's `/24`. This is the notation you'll see constantly — `192.168.1.0/24` means "network `192.168.1.0`, mask `255.255.255.0`."

### Full CIDR reference table

| CIDR | Subnet Mask | Host bits | Total addresses | Usable hosts |
|---|---|---|---|---|
| /8  | 255.0.0.0       | 24 | 16,777,216 | 16,777,214 |
| /16 | 255.255.0.0     | 16 | 65,536     | 65,534 |
| /20 | 255.255.240.0   | 12 | 4,096      | 4,094 |
| /24 | 255.255.255.0   | 8  | 256        | 254 |
| /25 | 255.255.255.128 | 7  | 128        | 126 |
| /26 | 255.255.255.192 | 6  | 64         | 62 |
| /27 | 255.255.255.224 | 5  | 32         | 30 |
| /28 | 255.255.255.240 | 4  | 16         | 14 |
| /29 | 255.255.255.248 | 3  | 8          | 6 |
| /30 | 255.255.255.252 | 2  | 4          | 2 |
| /31 | 255.255.255.254 | 1  | 2          | 0 (or 2, point-to-point only — see note) |
| /32 | 255.255.255.255 | 0  | 1          | single host, not a "network" |

*(Full /1–/32 table is in the [Cheat Sheet](#15-cheat-sheet).)*

**/31 note:** classically a /31 has zero usable hosts (both addresses are "reserved"), but RFC 3021 allows /31 specifically on point-to-point router links, treating both addresses as usable. NetPractice router-to-router links almost always use **/30** instead — clean, unambiguous, 2 usable addresses for exactly 2 routers.

**Formula:** usable hosts = 2^(host bits) − 2. You subtract 2 because the very first address in a block is always the *network address* and the very last is always the *broadcast address* — neither can be assigned to a device (see Section 5).

---

## 5. Network Address, Broadcast Address, Usable Range

Given an IP and a mask, three things fall out of it:

- **Network address** — the IP with all host bits forced to `0`. Identifies the network itself; never assigned to a device.
- **Broadcast address** — the IP with all host bits forced to `1`. Used to send to every device on that network at once; never assigned to a single device.
- **Usable range** — everything strictly between those two.

### Method 1 — from binary (the "why")

Take `192.168.1.130` with mask `/26` (`255.255.255.192`).

Only the last octet matters here since the first three octets are covered by full `255`s.

```
IP octet 4:    130 = 10000010
Mask octet 4:  192 = 11000000
```

**Network address** = IP **AND** mask (bit-by-bit: keep the bit only where the mask has a 1):
```
  10000010
AND 11000000
  ----------
  10000000  = 128
```
→ Network = `192.168.1.128`

**Broadcast address** = network address with every host bit flipped to 1 (equivalently, IP **OR** the *wildcard*, which is the mask inverted):
```
Wildcard = inverted mask = 00111111 (=63)
  10000000
 OR 00111111
  ----------
  10111111  = 191
```
→ Broadcast = `192.168.1.191`

**Usable range** = `192.168.1.129` – `192.168.1.190` (network+1 to broadcast−1)

### Method 2 — the "block size" shortcut (the fast way)

Once you trust Method 1, use this for speed:

> **Block size = 256 − (mask value of the interesting octet)**

The "interesting octet" is the one where the mask stops being `255`. For `/26`, that's `192`, so block size = `256 − 192 = 64`. Networks then land on multiples of the block size: `.0, .64, .128, .192`.

`130` falls between `128` and `192` → network = `.128`, next block starts at `.192`, so broadcast = `.192 − 1 = .191`. Same answer, much faster.

| Value | Result |
|---|---|
| Network address | 192.168.1.128 |
| Broadcast address | 192.168.1.191 |
| Usable range | 192.168.1.129 – 192.168.1.190 |
| Usable hosts | 62 |

---

## 6. Subnetting — Dividing a Network

**Subnetting** is the process of "stealing" bits from the host portion and giving them to the network portion — this turns one large network into several smaller ones. Each bit you borrow doubles the number of subnets and halves the size of each one.

```
Start:  255.255.255.0   = /24  → 1 network  of 256 addresses (254 usable)
Borrow 1 bit: /25        → 2 networks of 128 addresses (126 usable each)
Borrow 2 bits: /26        → 4 networks of 64  addresses (62 usable each)
Borrow 3 bits: /27        → 8 networks of 32  addresses (30 usable each)
```

**Two directions you'll be asked to solve:**

**A) "I need at least N usable hosts on this segment — what mask?"**
Find the smallest host-bit count `h` such that `2^h − 2 ≥ N`.
*Example: need 20 hosts.* `2^5−2=30 ≥ 20` ✓, and `2^4−2=14` is too few. So `h=5` → mask is `/27` (32−5).

**B) "I need to split this block into at least N subnets — what mask?"**
Find the smallest number of borrowed bits `s` such that `2^s ≥ N`.
*Example: split a /24 into 5 subnets.* `2^3=8 ≥ 5` ✓, `2^2=4` is too few. Borrow `s=3` bits → new mask is `/27` (24+3).

Notice both directions use the same table, just read from opposite ends — that's why the CIDR table in Section 4 is worth memorizing.

---

## 7. VLSM — Variable-Length Subnet Masking

Regular subnetting (above) cuts a block into **equal-sized** pieces. But real networks — and NetPractice's later levels — rarely need equal sizes: one LAN might need 25 hosts, another 10, and a router-to-router link only ever needs 2. **VLSM** lets you carve one address block into subnets of *different* sizes, as long as none of them overlap.

**Golden rule: always allocate the biggest requirement first.** If you start with the smallest, you'll fragment the block and the bigger pieces won't fit anymore.

### Worked example

You're given `192.168.10.0/26` (64 addresses total: `.0`–`.63`) and need to fit:
- Segment 1: up to 25 hosts
- Segment 2: up to 10 hosts
- Segment 3: a router-to-router link (2 hosts)

| Step | Requirement | Smallest mask that fits | Block size | Assigned range | Usable |
|---|---|---|---|---|---|
| 1 | 25 hosts | /27 (30 usable) | 32 | 192.168.10.**0**/27 | .1–.30 |
| 2 | 10 hosts | /28 (14 usable) | 16 | 192.168.10.**32**/28 | .33–.46 |
| 3 | 2 hosts (P2P) | /30 (2 usable) | 4 | 192.168.10.**48**/30 | .49–.50 |

Each block starts right where the previous one ended (`.0`→`.32`→`.48`), none overlap, and `.52`–`.63` are left free for future growth — all still inside the original `192.168.10.0/26`. This is exactly the pattern NetPractice's final levels test.

---

## 8. Routers, Gateways & Why They Matter

A switch only connects devices that are *already on the same network*. To reach a **different** network, a device needs a **router** — and it needs to know which router to send traffic to. That's the **default gateway**: the IP address of the router interface a device hands its "not-for-this-network" traffic to.

Two rules that solve most router-related NetPractice bugs:

1. **A router needs one interface per network it connects, and that interface's IP must belong to that network.** A router with two interfaces on two different LANs must have two IPs, each valid for its own side. If both interfaces end up in the *same* network by mistake, that's a broken config — a very common trap.
2. **A host's gateway must be an address inside the host's own subnet** (almost always the router's interface IP on that same LAN). A gateway pointing to an IP outside the host's subnet is unreachable and useless.

```
 [PC-A]-----[Router R]-----[PC-B]
 LAN A        eth0|eth1      LAN B
192.168.30.0/24  .1  .1   192.168.31.0/24
   PC-A gw → 192.168.30.1        PC-B gw → 192.168.31.1
```

---

## 9. Routing Tables

Once you have more than one router, gateways alone aren't enough — a router also needs to know *how to reach networks it isn't directly plugged into*. That's what a **routing table** is for. In NetPractice, each entry has two parts:

| Field | Meaning |
|---|---|
| **Destination** | The target network (with its mask) this rule applies to. `0.0.0.0/0` is the special **default route** — it matches *any* destination not covered by a more specific entry. |
| **Next hop** | The IP address to forward matching packets to. It must be an address the router can reach directly (i.e., on one of its own connected networks) — usually the neighboring router's interface on the link between them. |

### Worked example

```
[PC-A]--[R1 eth0|eth1]=======[R2 eth0|eth1]--[PC-B]
 LAN1        .1     .1            .2    .1        LAN2
10.0.1.0/24      10.0.2.0/30 (P2P link)      10.0.3.0/24
```

| Device | Interface | IP/mask |
|---|---|---|
| PC-A | — | 10.0.1.10/24, gateway 10.0.1.1 |
| R1 | eth0 | 10.0.1.1/24 |
| R1 | eth1 | 10.0.2.1/30 |
| R2 | eth0 | 10.0.2.2/30 |
| R2 | eth1 | 10.0.3.1/24 |
| PC-B | — | 10.0.3.10/24, gateway 10.0.3.1 |

R1 already "knows" `10.0.1.0/24` and `10.0.2.0/30` — they're directly connected to its own interfaces. It does **not** know `10.0.3.0/24` exists unless you tell it:

| Router | Destination | Next hop |
|---|---|---|
| R1 | 10.0.3.0/24 | 10.0.2.2 |
| R2 | 10.0.1.0/24 | 10.0.2.1 |

Note the symmetry: **every multi-router level needs routes in both directions.** It's easy to fix one router and forget the other — the connection will still fail because the reply can't find its way back.

---

## 10. Reading the NetPractice Interface

- Devices (PCs and router interfaces) are drawn as nodes connected by cables. A cable that's drawn but not "working" usually signals a mismatch somewhere on that link.
- Each node has editable **IP** and **mask** fields. Routers show one such pair *per interface*, plus a **routing table** panel (Destination / Next hop rows) once the level introduces multiple routers.
- The level tells you which devices are supposed to reach which (e.g., "A must communicate with B"). Some devices may be **decoys** — already correct, or irrelevant to the requirement — so don't "fix" what isn't asked for.
- There's typically a way to check/validate your configuration, and to export your finished config for submission.
- Levels 1–2 are single-network, two-device problems (fix IP, then fix mask). Levels increase by adding: more devices per segment → routers and gateways → multiple routers and routing tables → VLSM with mixed subnet sizes.

---

## 11. Step-by-Step Method for Any Level

1. **Read the requirement.** Which devices must reach which? Don't touch anything not implicated.
2. **Group devices by physical segment** — everything connected without a router between them must land on the *same* network.
3. **For each segment**, compute each device's network address (IP AND mask, Section 5). If they disagree, that's your bug: either the IP or the mask is wrong on one side.
4. **If a host count is specified**, pick the smallest mask that satisfies it (Section 6) — don't over- or under-allocate.
5. **For every router interface**, confirm its IP belongs to the network on *that* side, and that no two interfaces on the same router share a network.
6. **Set every host's gateway** to the router interface IP on its own segment.
7. **For each router, list the networks NOT directly attached to it.** For each one, add a routing table entry: destination network + next hop = the neighboring router's interface on the link toward that network.
8. **If subnets of different sizes are required (VLSM)**, allocate biggest-to-smallest from the given block (Section 7), keeping ranges non-overlapping.
9. **Re-check everything.** Recompute network addresses on every pair, confirm no two devices on different intended networks accidentally overlap, confirm routing tables are symmetric (both directions covered).

---

## 12. Worked Examples, Level by Level

These mirror the *types* of problems across the 10 levels — your actual numbers will differ, but the diagnosis-and-fix pattern is identical.

### Example A — Level 1 style: same cable, different networks

| Device | IP | Mask | Network address |
|---|---|---|---|
| PC A | 192.168.1.10 | 255.255.255.0 | 192.168.1.0 |
| PC B (before) | 192.168.2.10 | 255.255.255.0 | 192.168.2.0 ❌ mismatch |

**Fix:** change PC B's IP into A's network, keeping a distinct host part.

| Device | IP | Mask | Network address |
|---|---|---|---|
| PC B (after) | 192.168.1.11 | 255.255.255.0 | 192.168.1.0 ✓ |

### Example B — Level 2 style: similar IP, wrong mask

| Device | IP | Mask | Network address |
|---|---|---|---|
| PC C | 192.168.5.10 | 255.255.255.0 (/24) | 192.168.5.0 |
| PC D (before) | 192.168.5.20 | 255.255.0.0 (/16) | 192.168.0.0 ❌ |

The IPs *look* close, but D's /16 mask only keeps the first two octets — so D's network is `192.168.0.0`, not `192.168.5.0`. **Fix:** align the masks.

| Device | IP | Mask | Network address |
|---|---|---|---|
| PC D (after) | 192.168.5.20 | 255.255.255.0 (/24) | 192.168.5.0 ✓ |

### Example C — Level 3 style: size the mask to the segment

A switch needs to fit exactly 6 PCs on one segment, from block `192.168.20.0`.
`2^3−2 = 6` → 3 host bits → mask `/29` (255.255.255.248).

| Field | Value |
|---|---|
| Network | 192.168.20.0/29 |
| Usable range | 192.168.20.1 – 192.168.20.6 |
| PCs assigned | .1, .2, .3, .4, .5, .6 (all 6 fit exactly) |

### Example D — Level 4/5 style: router linking two LANs

**Before (broken):** both router interfaces mistakenly on the same network.

| Device | IP/mask |
|---|---|
| PC-A1 | 192.168.30.10/24 |
| Router eth0 | 192.168.30.1/24 |
| Router eth1 | 192.168.30.2/24 ❌ same network as eth0 |
| PC-B1 | 192.168.31.10/24, gateway 192.168.31.1 (unreachable — nothing there) |

**After (fixed):**

| Device | IP/mask |
|---|---|
| PC-A1 | 192.168.30.10/24, gateway 192.168.30.1 |
| Router eth0 | 192.168.30.1/24 |
| Router eth1 | 192.168.31.1/24 ✓ now on LAN B's network |
| PC-B1 | 192.168.31.10/24, gateway 192.168.31.1 ✓ |

### Example E — Level 6–8 style: routing tables between two routers

See the full worked example in [Section 9](#9-routing-tables) — R1 needs a route to `10.0.3.0/24` via `10.0.2.2`, and R2 needs a route to `10.0.1.0/24` via `10.0.2.1`.

### Example F — Level 9–10 style: VLSM

See the full worked example in [Section 7](#7-vlsm--variable-length-subnet-masking) — splitting `192.168.10.0/26` into a /27, a /28, and a /30 for three differently-sized segments.

---

## 13. Real-Life Examples

- **Postal addresses.** An IP is like a street address: the network portion is the street name (everyone on the street shares it), the host portion is the house number (unique to you). Two houses on different streets can't be "next door" even if their house numbers match.
- **Home Wi-Fi.** Your home router almost always hands out addresses in `192.168.1.0/24` or `192.168.0.0/24` — one of the private ranges reserved for exactly this (see Cheat Sheet). The router itself is usually `192.168.1.1`, which is also every device's default gateway — precisely the gateway concept from Section 8.
- **Office network segmentation.** A company might give HR a `/26` (fits ~60 people), Engineering a `/24` (fits ~250), and a guest Wi-Fi a `/28` (fits ~14) — all carved out of one larger block. That's VLSM, used for exactly the reason NetPractice teaches it: don't waste address space on a segment that doesn't need it.
- **Point-to-point ISP/backbone links.** The `/30` link between two routers in Example E isn't just a classroom trick — it's the standard real-world size for a link that will only ever have exactly two devices on it (one at each end).
- **NAT, one level up.** Homes and offices use private ranges internally (Section 8's cheat-sheet ranges), then a router translates all of that traffic to a single public IP to reach the internet. NetPractice doesn't test NAT directly, but it's *why* the private ranges below exist and get reused in every home on the planet without conflict.

---

## 14. Common Mistakes

| Mistake | Why it breaks things |
|---|---|
| Assigning a device the network or broadcast address | Neither is a valid host address — both are reserved (Section 5) |
| Trusting decimal similarity over computed network address | `192.168.5.10/24` and `192.168.5.20/16` look alike but are on different networks — always compute, don't eyeball |
| Two interfaces on the same router sharing a network | A router needs a distinct network per interface; identical networks make one interface redundant/broken |
| Gateway set outside the host's own subnet | Unreachable — a gateway must be an address inside the host's own network |
| Fixing only one router's routing table | Routes must exist in **both** directions, or replies can't get back |
| Overlapping VLSM blocks | Always allocate biggest requirement first, and let each block start where the previous one ended |
| Wrong direction on the hosts-vs-subnets formula | "Need N hosts" → solve `2^h−2≥N` for host bits. "Need N subnets" → solve `2^s≥N` for borrowed bits. Mixing these up is the #1 source of off-by-one mask errors |

---

## 15. Cheat Sheet

### Full CIDR table

| CIDR | Mask | Usable hosts | | CIDR | Mask | Usable hosts |
|---|---|---|---|---|---|---|
| /1  | 128.0.0.0 | 2,147,483,646 | | /17 | 255.255.128.0 | 32,766 |
| /2  | 192.0.0.0 | 1,073,741,822 | | /18 | 255.255.192.0 | 16,382 |
| /3  | 224.0.0.0 | 536,870,910   | | /19 | 255.255.224.0 | 8,190 |
| /4  | 240.0.0.0 | 268,435,454   | | /20 | 255.255.240.0 | 4,094 |
| /5  | 248.0.0.0 | 134,217,726   | | /21 | 255.255.248.0 | 2,046 |
| /6  | 252.0.0.0 | 67,108,862    | | /22 | 255.255.252.0 | 1,022 |
| /7  | 254.0.0.0 | 33,554,430    | | /23 | 255.255.254.0 | 510 |
| /8  | 255.0.0.0 | 16,777,214    | | /24 | 255.255.255.0 | 254 |
| /9  | 255.128.0.0 | 8,388,606   | | /25 | 255.255.255.128 | 126 |
| /10 | 255.192.0.0 | 4,194,302   | | /26 | 255.255.255.192 | 62 |
| /11 | 255.224.0.0 | 2,097,150   | | /27 | 255.255.255.224 | 30 |
| /12 | 255.240.0.0 | 1,048,574   | | /28 | 255.255.255.240 | 14 |
| /13 | 255.248.0.0 | 524,286     | | /29 | 255.255.255.248 | 6 |
| /14 | 255.252.0.0 | 262,142     | | /30 | 255.255.255.252 | 2 |
| /15 | 255.254.0.0 | 131,070     | | /31 | 255.255.255.254 | 0* |
| /16 | 255.255.0.0 | 65,534      | | /32 | 255.255.255.255 | 1 (host route) |

*/31 = 2 usable only on point-to-point links per RFC 3021; NetPractice typically uses /30 instead.*

### Binary place values (per octet)
```
128   64   32   16   8   4   2   1
```
Mask octet values as bits fill in: `0, 128, 192, 224, 240, 248, 252, 254, 255`

### Reserved / special ranges

| Range | Purpose |
|---|---|
| 10.0.0.0 – 10.255.255.255 (/8) | Private network |
| 172.16.0.0 – 172.31.255.255 (/12) | Private network |
| 192.168.0.0 – 192.168.255.255 (/16) | Private network |
| 127.0.0.0 – 127.255.255.255 (/8) | Loopback (127.0.0.1 = "this machine") |
| 169.254.0.0 – 169.254.255.255 (/16) | Link-local (auto-assigned when DHCP fails) |
| 0.0.0.0 | Unspecified address / default route target |
| 255.255.255.255 | Limited broadcast |

### Classful defaults (legacy, still referenced in some guides)

| Class | Range | Default mask |
|---|---|---|
| A | 0.0.0.0 – 127.255.255.255 | /8 |
| B | 128.0.0.0 – 191.255.255.255 | /16 |
| C | 192.0.0.0 – 223.255.255.255 | /24 |
| D | 224.0.0.0 – 239.255.255.255 | multicast, no hosts |
| E | 240.0.0.0 – 255.255.255.255 | reserved/experimental |

Modern networking (and NetPractice) is **classless** — any mask can pair with any address — but you'll see "Class C" language in older guides, so it's worth recognizing.

### Formulas
```
Usable hosts per subnet   = 2^(host bits) − 2
Number of subnets created = 2^(borrowed bits)
Block size (shortcut)     = 256 − (mask value of interesting octet)
```

---

## 16. Glossary

| Term | Meaning |
|---|---|
| **IP address** | 32-bit address identifying a device on a network |
| **Octet** | One of the four 8-bit segments of an IPv4 address |
| **Subnet mask** | Marks which bits of an IP are network vs. host |
| **CIDR** | `/n` notation for a mask — n = number of network bits |
| **Network address** | First address in a block; identifies the network itself |
| **Broadcast address** | Last address in a block; targets every host on it |
| **Host bits** | The bits of the address left for identifying individual devices |
| **Subnetting** | Splitting a network into smaller networks by borrowing host bits |
| **VLSM** | Subnetting into pieces of *different* sizes from the same block |
| **Gateway** | The router IP a device sends off-network traffic to |
| **Routing table** | List of (destination network → next hop) rules on a router |
| **Next hop** | The directly-reachable IP a router forwards matching traffic to |
| **Default route** | `0.0.0.0/0` — matches any destination with no more specific route |
| **LAN** | Local Area Network — devices on the same network segment |
| **P2P link** | A link with exactly two devices on it (typically a /30) |

---

### Final tips
- Compute, don't eyeball. Decimal similarity is a trap; network address (IP AND mask) is the only thing that matters.
- Work one segment at a time. Complex topologies are just several of the simple problems from Sections 12A–12D chained together.
- When something's "almost" right, check the mask before you touch the IP — a wrong mask is the single most common root cause across all 10 levels.