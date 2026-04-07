*This project has been created as part of the 42 curriculum by kemontei.*

## Description
**Philosophers** is an implementation of the classic *Dining Philosophers* concurrency problem.

**Goal:** simulate philosophers that repeatedly think, take two forks (mutexes), eat, and sleep, while avoiding data races and correctly detecting when a philosopher dies (doesn’t eat within `time_to_die`).

This project uses **POSIX threads** (`pthread`) and **mutexes** to coordinate access to forks and shared state, and a dedicated **monitor thread** to detect death / completion conditions.

## Instructions

### Requirements
- Linux/macOS
- `cc` (or compatible C compiler)
- `make`
- `pthread`

### Build
```bash
make
```
This produces the `philo` executable.

Other useful targets:
```bash
make clean
make fclean
make re
```

### Run
```bash
./philo philosophers time_to_die time_to_eat time_to_sleep [meals_required]
```

- All arguments must be **positive integers**.
- Times are in **milliseconds**.
- `philosophers` must be **<= 200**.
- The last argument is **optional**; when provided, the program stops once every philosopher has eaten at least that many times.

Example:
```bash
./philo 5 800 200 200 7
```

### Output
The program prints timestamped status lines:

- `has taken a fork`
- `is eating`
- `is sleeping`
- `is thinking`
- `died`

(Colored output is used by default.)

## Resources

### References
- 42 subject PDF (included): `subject/en.subject.pdf`

### AI usage disclosure
- **GitHub Copilot Chat** (model: **GPT-5.2**) was used to draft this `README.md` based on the existing codebase (binary name, CLI arguments, and constraints).
