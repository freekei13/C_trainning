*This repository contains all projects completed as part of the 42 curriculum by [Kaito].*

![42 Logo](https://repository-images.githubusercontent.com/247835136/9eebcd80-40a4-11eb-9ee5-5e432fb15c4f)

---

## Description

This repository serves as the main reference for all projects completed at [42 Lausanne](https://42lausanne.ch/). Each project is stored in its own directory and covers a specific set of concepts in systems programming, algorithms, and software engineering.

The 42 curriculum is project-based and peer-evaluated, with no traditional lectures. Every project is an opportunity to learn by doing — reading documentation, experimenting, and debugging independently.

---

## Projects

| Project | Description | Status |
|---|---|---|
| libft | Custom C standard library reimplementation | ✅ Done |
| ft_printf | Reimplementation of printf | ✅ Done |
| get_next_line | Line-by-line file reader using static variables | ✅ Done |
| born2beroot | System administration and VM configuration | ✅ Done |
| push_swap | Sorting algorithm with a limited instruction set | ✅ Done |
| so_long | 2D game using a graphical library (MLX) | ✅ Done |
| pipex | Unix pipe and process management | ✅ Done (+ bonus) |
| philosophers | Concurrency with threads and mutexes | ✅ Done |
| minishell | Bash-like shell implementation | ✅ Done |
| cub3d | Raycasting engine (Wolfenstein-style 3D renderer) | 🔄 In progress |
| cpp-module | Introduction to C++ (piscine C++) | 🔄 In progress |
---

## Getting Started

Each project has its own directory with a dedicated `Makefile` and `README.md`. Navigate to the relevant folder and run:

```bash
make
```

Refer to the project's own README for specific compilation and execution instructions.

---

## Skills Covered

- **C programming** — memory management, pointers, file descriptors, static/global variables
- **Custom libraries** — reimplementing libc functions (`libft`), variadic functions (`ft_printf`), buffered reading (`get_next_line`)
- **Algorithms & data structures** — sorting with constrained instructions (`push_swap`), linked lists, stacks
- **Unix/Linux processes** — fork, exec, pipes, file descriptor duplication (`pipex`), process synchronization
- **Shell implementation** (`minishell`) — lexing/parsing, tokenization, built-ins, signal handling, redirections, environment variables, readline
- **Concurrency** — threads, mutexes, race condition prevention, deadlock avoidance (`philosophers`)
- **Graphics programming** — event loops, pixel buffers, rendering, keyboard/mouse input (`so_long`, `cub3d`)
- **Raycasting & 3D rendering** (`cub3d`) — DDA algorithm, ray-grid intersection, texture mapping, perspective projection, map parsing and validation
- **C++ fundamentals** (`cpp-module`) — classes, encapsulation, constructors/destructors, orthodox canonical form, references vs pointers, `const` correctness
- **System administration** — virtual machines, networking basics, service configuration (`born2beroot`)