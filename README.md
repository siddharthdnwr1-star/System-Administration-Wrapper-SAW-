# 🖥️ System Tools Dashboard

A lightweight, menu-driven **Windows system utility** written in C that gives you quick access to common system operations — all from a clean terminal interface.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Demo](#demo)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Running the Program](#running-the-program)
- [Usage](#usage)
  - [Main Menu](#main-menu)
  - [Ping Tools Submenu](#ping-tools-submenu)
- [Project Structure](#project-structure)
- [Code Walkthrough](#code-walkthrough)
  - [Headers & Includes](#headers--includes)
  - [flush\_stdin()](#flush_stdin)
  - [display\_header()](#display_header)
  - [is\_valid\_ping\_target()](#is_valid_ping_target)
  - [run\_ping()](#run_ping)
  - [handle\_ping\_options()](#handle_ping_options)
  - [main()](#main)
- [Security Notes](#security-notes)
- [Limitations](#limitations)
- [License](#license)

---

## Overview

**System Tools Dashboard** is a single-file C program (`Project_I.c`) that wraps several Windows system commands into an interactive terminal menu. Instead of remembering and typing individual commands, users can navigate numbered options to run network diagnostics, inspect processes, schedule a shutdown, and more.

It is designed as a learning project demonstrating:
- Structured menu-driven CLI design in C
- Safe use of `system()` with input validation
- Windows API usage (`_kbhit`, `_getch`, `Sleep`)
- Basic input sanitization to prevent command injection

---

## Features

| # | Feature | Description |
|---|---------|-------------|
| 1 | **Network Configuration** | Runs `ipconfig` to display all network adapter details |
| 2 | **Running Processes** | Runs `tasklist` to list all active processes |
| 3 | **System Shutdown** | Schedules a 60-second shutdown with a live countdown and a cancel option (`C` key) |
| 4 | **Ping Tools** | Submenu for loopback test (`127.0.0.1`) or custom IP/hostname ping |
| 5 | **Exit** | Cleanly exits the dashboard |

---

## Demo

```
============================================
        SYSTEM TOOLS DASHBOARD
============================================

Dear User, choose what you want to do:

  [1] Network configuration (ipconfig)
  [2] View running processes (tasklist)
  [3] System shutdown
  [4] Network ping tools
  [5] Exit to dashboard

  Your choice: _
```

**Ping Tools Submenu:**
```
--------------------------------------------
  PING TOOLS
--------------------------------------------
  [1] Internal test    (loopback 127.0.0.1)
  [2] External / target ping  (custom IP or hostname)
  [0] Back to main menu
--------------------------------------------
  Your choice: _
```

---

## Getting Started

### Prerequisites

- **OS:** Windows 7 / 10 / 11
- **Compiler:** MinGW GCC (recommended), MSVC, or any Windows-compatible C compiler
- **Standard:** C99 or later

> ⚠️ This program uses Windows-specific headers (`<windows.h>`, `<conio.h>`) and is **not cross-platform**.

---

### Compilation

**Using GCC (MinGW):**
```bash
gcc -o SystemToolsDashboard Project_I.c -Wall -Wextra -std=c99
```

**Using MSVC (Developer Command Prompt):**
```bash
cl Project_I.c /Fe:SystemToolsDashboard.exe
```

---

### Running the Program

```bash
SystemToolsDashboard.exe
```

> 💡 **Tip:** Run as Administrator if you need full access to system commands like `shutdown`.

---

## Usage

### Main Menu

| Option | Action |
|--------|--------|
| `1` | Displays full network adapter info via `ipconfig` |
| `2` | Lists all running processes via `tasklist` |
| `3` | Initiates a 60-second shutdown timer — press **C** at any time to cancel |
| `4` | Opens the Ping Tools submenu |
| `5` | Exits the program |

After each action, press **any key** to return to the main menu.

---

### Ping Tools Submenu

| Option | Action |
|--------|--------|
| `1` | Pings `127.0.0.1` (loopback) to verify your local TCP/IP stack is healthy |
| `2` | Prompts for a custom IP address or hostname (e.g. `8.8.8.8` or `google.com`) |
| `0` | Returns to the main menu |

**Input Validation for Custom Ping:**  
Only alphanumeric characters and the symbols `.`, `-`, and `_` are accepted in hostnames/IPs. Any other character is rejected to prevent shell injection.

---

## Project Structure

```
Project_I.c
│
├── main()                    — Main event loop and top-level menu
├── display_header()          — Clears screen and prints the dashboard header
├── handle_ping_options()     — Ping submenu logic
├── run_ping()                — Builds and executes the ping command
├── is_valid_ping_target()    — Input sanitizer for IP/hostname strings
└── flush_stdin()             — Clears leftover characters from the input buffer
```

---

## Code Walkthrough

A plain-English breakdown of every part of the source code — ideal for students or anyone learning C.

---

### Headers & Includes

```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
```

| Header | Purpose |
|--------|---------|
| `<stdio.h>` | Standard I/O — `printf`, `scanf`, `getchar`, `fflush` |
| `<stdlib.h>` | Provides `system()` to run shell commands |
| `<conio.h>` | Windows console I/O — `_getch()` (read a key without Enter) and `_kbhit()` (check if a key was pressed) |
| `<windows.h>` | Windows API — provides `Sleep(ms)` for the countdown timer |

> These headers make the program **Windows-only**. There is no Linux/macOS equivalent for `<conio.h>`.

---

### `flush_stdin()`

```c
void flush_stdin(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
```

**What it does:**  
After reading a number with `scanf("%d", ...)`, the newline character (`\n`) that the user pressed stays stuck in the input buffer. If left there, the next `scanf` or `getchar` call would instantly "see" it as input and behave unexpectedly.

`flush_stdin()` eats all leftover characters in the buffer (including `\n`) so the next input read starts clean.

---

### `display_header()`

```c
void display_header(void) {
    system("cls");
    printf("============================================\n");
    printf("        SYSTEM TOOLS DASHBOARD              \n");
    printf("============================================\n\n");
}
```

**What it does:**  
Called at the start of every loop cycle to refresh the terminal. `system("cls")` clears the screen (Windows equivalent of `clear` on Linux), then the header banner is printed. This gives the dashboard a clean, consistent look every time the menu reloads.

---

### `is_valid_ping_target()`

```c
static int is_valid_ping_target(const char *addr) {
    if (addr == NULL || addr[0] == '\0') return 0;

    for (int i = 0; addr[i] != '\0'; i++) {
        char c = addr[i];
        int is_alnum  = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
                        || (c >= '0' && c <= '9');
        int is_symbol = (c == '.' || c == '-' || c == '_');
        if (!is_alnum && !is_symbol) return 0;
    }
    return 1;
}
```

**What it does:**  
This is the **security gatekeeper** for custom ping input. Before passing any user-typed address to `system("ping ...")`, every single character is checked.

- Returns `0` (invalid) if the string is empty or `NULL`.
- Loops through every character and allows only:
  - Letters `a–z`, `A–Z`
  - Digits `0–9`
  - Symbols `.` `-` `_`
- If **any** other character is found (like `;`, `&`, `|`, spaces, or backticks), it immediately returns `0` and the ping is blocked.

**Why this matters:**  
Without this check, a user could type something like `8.8.8.8 & del C:\Windows\System32` and the `system()` call would execute both commands. This function prevents that class of **command injection attack**.

---

### `run_ping()`

```c
static void run_ping(const char *target) {
    char command[200];
    snprintf(command, sizeof(command), "ping %s", target);
    printf("\n");
    system(command);
}
```

**What it does:**  
Constructs and runs the actual ping command.

- `snprintf` safely builds the command string `"ping <target>"` into a 200-byte buffer — the `sizeof(command)` limit prevents buffer overflow.
- `system(command)` hands the string to Windows Command Prompt for execution.
- By the time this function is called, the `target` has already been validated by `is_valid_ping_target()`.

---

### `handle_ping_options()`

```c
void handle_ping_options(void) { ... }
```

**What it does:**  
Displays and manages the **Ping Tools submenu**. It presents three choices and uses a `switch` statement to route the user:

**Case 1 — Loopback Test:**
- Directly calls `run_ping("127.0.0.1")` — no user input needed.
- `127.0.0.1` is the loopback address, meaning it pings your own machine's network stack. If this fails, your TCP/IP stack itself is broken (not just your internet).

**Case 2 — Custom Target:**
- Reads a string with `scanf("%127s", target)` — the `127` cap prevents reading more than 127 chars, protecting the buffer.
- Calls `is_valid_ping_target()` to sanitize input.
- If valid, calls `run_ping(target)` to execute.
- Prints diagnostic hints after the ping (all replies = healthy; timeout = blocked or unreachable).

**Case 0 — Back:**
- Returns to the main menu without doing anything.

---

### `main()`

```c
int main(void) {
    int user_selection;
    while (1) { ... }
    return 0;
}
```

**What it does:**  
The program's core loop. It runs **forever** until the user selects Exit (option 5).

Each iteration:
1. Calls `display_header()` to clear and redraw the screen.
2. Prints the main menu.
3. Reads the user's choice with `scanf`.
4. Runs the matching `switch` case.

**Case-by-case breakdown:**

| Case | What happens |
|------|-------------|
| `1` | Runs `system("ipconfig")` — dumps all network adapter info |
| `2` | Runs `system("tasklist")` — lists every running process with PID and memory usage |
| `3` | Calls `system("shutdown /s /t 60")` to schedule shutdown, then enters a 60-second live countdown loop using `Sleep(1000)` per tick. `_kbhit()` polls for a keypress each second — if `C` is pressed, `system("shutdown /a")` cancels it |
| `4` | Calls `handle_ping_options()` |
| `5` | Prints a goodbye message and `return 0` to exit the program |

**Error handling:**  
If `scanf` fails to read a valid integer (e.g., user types letters), it prints an error, calls `flush_stdin()` to clear the bad input, waits for a keypress, clears the screen, and restarts the loop — preventing an infinite error spiral.

---

## Security Notes

- **Input sanitization:** The custom ping target is validated character-by-character. Only `[a-zA-Z0-9._-]` are allowed, blocking shell metacharacters like `;`, `&`, `|`, `` ` ``, etc.
- **Buffer size:** The target input is limited to 127 characters (`%127s`), preventing buffer overflow.
- **`system()` usage:** While `system()` is generally discouraged in production code, the sanitization layer here significantly reduces injection risk for this educational context.

---

## Limitations

- **Windows only** — uses `<conio.h>`, `<windows.h>`, `_kbhit()`, `_getch()`, and `Sleep()`.
- The shutdown cancel window is exactly 60 seconds; this is hardcoded and non-configurable at runtime.
- `ipconfig` and `tasklist` output is printed directly to the terminal with no parsing or filtering.

---

## License

This project is intended for **educational purposes**. Feel free to use, modify, and learn from it.

---

> Made with C — simple, fast, and close to the metal.
