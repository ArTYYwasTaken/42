*This project has been created as part of the 42 curriculum by kemontei.*

# NetPractice

## Description

NetPractice is a 42 common-core practical exercise that introduces the basics of computer networking through a web-based simulator. There is **no code to write**: each of the **10 levels** shows a small-scale but *broken* network topology (hosts, switches, routers), and the goal is to fix it by editing the available configuration fields — **IP addresses**, **subnet masks**, and, on routers, the **routing tables** — until every required connection works.

Working through the levels covers the core TCP/IP addressing concepts studied in this project:

- **IPv4 addresses** and the notion of the network portion vs. the host portion.
- **Subnet masks** (in dotted-decimal form) and how they define the boundaries of a network — in particular that two devices can only communicate directly if they compute the same network address.
- **Topologies with routers and switches**, where switches operate at OSI Layer 2 within a single network while routers operate at Layer 3 to route traffic *between* networks.
- The role of the **default gateway** and how routing tables determine the path of a packet across several routers.
- Practical constraints such as network address, broadcast address, usable host range, and classless addressing.

Because the configurations (IPs, masks, routing entries) are **randomized per login**, this repository is evaluated together with the explanation of the method used during the defense, not by a fixed set of answers.

## Instructions

### Requirements

- A machine with `python3` available and a local web browser.

### Running the training interface

1. Unpack the files attached to the project page in a folder of your choice.
2. From that folder, execute:

   ```sh
   ./run.sh
   ```

   This script starts a local web server and opens the NetPractice page in your browser.

   If `run.sh` does not work, start the server manually and browse to the page:

   ```sh
   python3 -m http.server 49242
   # then open http://localhost:49242 in your browser
   ```

3. **Enter your intra login** on the start screen — this is mandatory, as it generates your personal configurations and identifies your exports.

4. Solve each level by editing the unshaded configuration fields, then use **[Check again]** to validate. Green connections = goals reached.

5. **Export every level** with the **[Get my config]** button *before* moving to the next one.

### Repository structure

- `level1.config` … `level10.config` — the 10 exported configuration files, one per level, placed **at the root of this repository**.
- Study notes (`netpractice.md`, `netpractice2.md`, `routing_tables.md`, `routers_and_switches.md`) — method and concept notes used while solving the levels.

### Submission

- The Git repository must contain **10 exported configuration files, one per level**, at the repository root.
- Only the work inside the repository is evaluated during the peer evaluation.
- During the defense, **3 random levels** are drawn from the training platform ("evaluation" tab generates a random configuration) and must be completed within a limited time.
- **No external tools** are allowed during the evaluation; only a simple calculator such as `bc` is tolerated.

## Resources

### Concepts covered

TCP/IP addressing (IPv4), subnet masks and dotted-decimal/CIDR notation, network / broadcast / usable-host addresses, subnetting and VLSM, default gateways, routing tables, routers and switches, OSI layers (Layer 2 vs Layer 3 forwarding), IP packet traversal across multiple routers.

### References

- **TCP/IP fundamentals** — *Computer Networks* by Andrew S. Tanenbaum and David J. Wetherall, chapters on IP addressing and routing.
- **RFC 950** — *Internet Standard Subnetting Procedure*, the original definition of subnetting and subnet masks.
- **RFC 791 / RFC 4632** — *Internet Protocol* and *Classless Inter-domain Routing (CIDR)*, the addressing-notation background used throughout the exercise.
- **The NetPractice subject** (`subject/en.subject.pdf` in this repository) — the official problem statement.
- **subnetting practice articles and CIDR tables** — freely available cheat sheets listing the block sizes `/24 /25 … /30`, their address counts, and their usable-host ranges.
- **42 peer resources** — the internal `net_practice.1.9` training interface attached to the subject, providing the 10 levels and the log panel used to diagnose misconfigurations.

### AI usage

Generative AI was used as a study aid, not to solve the levels:

- **Study material generation** — files explaining IP addressing, binary/decimal conversion, subnet masks, CIDR blocks, network/broadcast/host ranges, default gateways and routing tables in plain language, and walk through the *method* for solving each level generically (since configurations are randomized, no answer key is possible or useful).
- **README writing** — this `README.md` was drafted with AI assistance, then reviewed against the subject requirements.
- **Concept checking** — AI explanations were cross-verified against the log outputs of the training interface and against the actual—"green target reached"—results of solved levels; every rule was validated on real configurations before being trusted.

All configs and solutions in this repository were produced by the author by working through the levels; no AI-generated configuration was submitted as-is.
