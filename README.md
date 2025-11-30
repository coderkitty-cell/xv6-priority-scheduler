

# Kernel Priority Scheduling Feature – NUST SEECS OS Assignment

**Course:** Operating Systems – Fall 2025
**Instructor:** Ms. Zahida Kausar
**Student:** MUHAMMAD USMAN HAMED - 474406
             SAJJAD UR REHMAN  -  460525
             MUHAMMADD AWAIS ABDULLLAH  - 456276
             NAFEEL MANNAN - 455323
**Assignment:** 2 – Kernel Feature Implementation

---

## Overview

This repository contains a minimal implementation of a **priority-based scheduler** in the xv6 operating system. The goal is to demonstrate understanding of **process management and scheduling** by implementing, testing, and documenting a kernel feature.

The implementation includes:

* **Priority-based scheduler** with 3 levels: High, Medium, Low
* **Basic functionality test**: Runs one process per priority level
* **Stress test**: Runs multiple processes per priority to demonstrate scheduler behavior under load
* **Edge-case test**: Handles invalid or extreme priority inputs

---

## Repository Contents

| File                     | Description                                                         |
| ------------------------ | ------------------------------------------------------------------- |
| `kernel/proc.c`          | Modified kernel scheduler code to support priority-based scheduling |
| `user/prioritytest.c`    | Basic priority test – 3 processes with High, Medium, Low priority   |
| `user/stress_priority.c` | Stress test – 15 processes (5 per priority level)                   |
| `user/edge_priority.c`   | Edge-case test – invalid and extreme priorities                     |
| `Makefile`               | Compilation instructions for user programs                          |
| `README.md`              | This file, with setup and usage instructions                        |

---

## Build & Run Instructions

1. **Build xv6** in your preferred environment (QEMU/VirtualBox/VMware):

   ```bash
   make clean
   make
   make qemu
   ```
2. **Run tests inside xv6 shell**:

   ```bash
   $ prioritytest        # Basic functionality test
   $ stress_priority     # Stress test
   $ edge_priority       # Edge-case test
   ```
3. Observe the **output showing process interleaving based on priority**. High-priority processes are scheduled more frequently than medium or low-priority ones.

---

## Example Output

**Basic Test (`prioritytest`)**:

```
=== PRIORITY SCHEDULING TEST ===
[tick 1100] HIGH priority | iter 1 | pid 4
[tick 1102] MEDIUM priority | iter 1 | pid 5
[tick 1107] LOW priority | iter 1 | pid 6
...
=== TEST COMPLETE ===
```

**Stress Test (`stress_priority`)**:

```
=== PRIORITY SCHEDULING STRESS TEST ===
Spawning 5 High, 5 Medium, 5 Low priority processes
[tick 2183] HIGH priority | Process 1633 | Iteration 1 | PID=1
[tick 2184] MEDIUM priority | Process 1635 | Iteration 1 | PID=2
...
=== TEST COMPLETE ===
```

**Edge-Case Test (`edge_priority`)**:

```
--- Testing negative priority ---
Correct: Failed to set negative priority
--- Testing extremely high priority ---
Correct: Failed to set too-high priority
=== EDGE-CASE TEST COMPLETE ===
```

---

## Notes

* All modifications are done in **xv6 public kernel**
* Only **minimal changes** required for priority scheduling were made
* Tests demonstrate **scheduler behavior** under normal, stress, and edge conditions


---


