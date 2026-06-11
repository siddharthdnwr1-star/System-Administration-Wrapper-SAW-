# 📄 Project Description — System Tools Dashboard

> *A complete guide covering what this project is, who it is for, why it was built, how to get it running, and the story behind its creation — written for beginners and professionals alike.*

---

## 📌 Table of Contents

1. [What Is This Project?](#1-what-is-this-project)
2. [Why This Was Built](#2-why-this-was-built)
3. [Who Is This Project For?](#3-who-is-this-project-for)
4. [What Problems Does It Solve?](#4-what-problems-does-it-solve)
5. [How to Set Up and Run](#5-how-to-set-up-and-run)
   - [Step A — Download the Code](#-step-a--download-the-code)
   - [Method 1 — Code::Blocks](#-method-1--codeblocks--best-for-beginners)
   - [Method 2 — Dev-C++](#-method-2--dev-c--lightest-option)
   - [Method 3 — Visual Studio Code](#-method-3--visual-studio-code--lightweight--modern)
   - [Method 4 — Visual Studio Community](#-method-4--visual-studio-community--full-ide)
   - [Method 5 — Command Prompt Only](#-method-5--command-prompt-only--no-ide-needed)
   - [Running the Dashboard](#️-running-the-dashboard)
6. [Feature Guide — What Each Option Does](#6-feature-guide--what-each-option-does)
7. [About the Developer](#7-about-the-developer)
8. [How This Project Was Built](#8-how-this-project-was-built)
9. [Why C Was Chosen](#9-why-c-was-chosen)
10. [What This Project Teaches](#10-what-this-project-teaches)
11. [Future Improvements](#11-future-improvements)

---

## 1. What Is This Project?

**System Tools Dashboard** is a Windows utility program written in the **C programming language**. It runs in a terminal window and gives you a simple numbered menu to perform five common system tasks — all without needing to open Command Prompt manually or remember any commands.

Instead of typing `ipconfig` or `tasklist` yourself, you just press `1` or `2` and the program handles everything.

The entire project is one file — `Saw.c` — roughly **200 lines of well-structured, commented C code**. It is easy to open, read, compile, and modify.

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

---

## 2. Why This Was Built

Most students learning C for the first time build the same types of programs — a calculator, a number guessing game, or a basic menu that prints text. These programs teach syntax, but they do not show how a real C program actually interacts with a computer's operating system.

At the same time, everyday Windows users — students, office workers, IT staff — often need quick access to network information, process lists, or system diagnostics, but do not always remember the exact commands to type.

This project was built to solve both problems at once:

- For **students**: a complete, real-world C program that demonstrates how C communicates with the Windows operating system — covering input handling, memory safety, security, and modular code design.
- For **everyday users and professionals**: a ready-to-use tool that wraps common Windows commands into a clean, guided menu — no Command Prompt knowledge required.

---

## 3. Who Is This Project For?

### 🎓 BCA / CS Students — Learn by Reading Real Code

If you are studying BCA, Computer Science, IT, or any related field, this project is written specifically with you in mind. Every concept covered in a first-year C programming course appears somewhere in this code — and it is all put together in a program that actually does something useful.

You can use this project to:
- Study how a complete C program is structured from top to bottom.
- See how `scanf`, `switch`, `while` loops, and functions work together in practice.
- Understand how C programs call system-level commands using `system()`.
- Learn about input validation and why it matters for security.
- Use it as a reference or starting point for your own project submissions.

| C Concept You Are Learning | Where It Appears in This Code |
|---|---|
| Functions and modular design | `flush_stdin()`, `display_header()`, `run_ping()` — each does one job |
| Loops and infinite loop with exit | `while(1)` loop in `main()` that runs until the user presses 5 |
| `switch-case` for menu logic | Used in both `main()` and `handle_ping_options()` |
| User input with `scanf` | Every menu option reads input with `scanf` |
| Input buffer management | `flush_stdin()` clears leftover characters after each `scanf` |
| String validation character by character | `is_valid_ping_target()` checks every character in the user's input |
| Safe string building | `snprintf()` in `run_ping()` builds the command safely |
| Windows API functions | `_kbhit()`, `_getch()`, and `Sleep()` from `<windows.h>` and `<conio.h>` |
| Security — preventing command injection | The validator blocks dangerous characters before calling `system()` |
| Security — preventing buffer overflow | `%127s` in `scanf` and `sizeof()` in `snprintf` cap input length |

---

### 💼 IT Professionals and Developers — A Practical Daily Tool

If you work in IT support, network administration, software development, or DevOps, this dashboard gives you a quick-launch utility for the diagnostics you run most often. Rather than opening a new terminal and typing commands one by one, you have a single tool that puts everything one keypress away.

It is also **extensible** — adding a new command to the menu takes only a few lines of C. You can fork the project and add `netstat`, `tracert`, `systeminfo`, or any other command you use regularly.

---

### 🖥️ General Windows Users — No Technical Knowledge Needed

If you use a Windows PC and occasionally need to check your IP address, see what programs are running, or test your internet connection, this tool makes that simple. Download it, run the `.exe`, and press a number. No command memorization, no terminal experience required.

---

## 4. What Problems Does It Solve?

### Problem 1 — Forgetting Command Syntax
Commands like `shutdown /s /t 60` or `ipconfig /all` are easy to forget if you do not use them daily. This dashboard removes that friction entirely.

### Problem 2 — No Practical Beginner Project in C
Most first-year C projects are academic exercises with no real-world application. This project is both a working tool and a learning resource — it teaches real concepts through a program you can actually use.

### Problem 3 — Unsafe Use of `system()` in C
The function `system()` is commonly taught but often used unsafely. This project demonstrates the correct way — validating every character of user input before passing it to the shell, blocking potential command injection attacks.

### Problem 4 — No Countdown or Cancel for Shutdown
Windows' built-in shutdown command gives you no interactive way to cancel it once started. This project adds a live 60-second countdown with a `C` key cancel — making the shutdown feature genuinely safe and practical.

---

## 5. How to Set Up and Run

> 👶 **Never compiled a C program before?** That is completely fine. Pick any one method below and follow it from top to bottom — every step is explained.

---

### 📥 Step A — Download the Code

Before anything else, get the source file onto your computer.

**Option 1 — Download as ZIP (easiest)**

1. On this GitHub page, click the green **`<> Code`** button (top right area).
2. Click **"Download ZIP"** from the dropdown.
3. Go to your **Downloads** folder, right-click the ZIP file, and click **"Extract All"**.
4. Choose where to extract it — for example: `C:\Projects\SystemDashboard\`
5. Open the extracted folder. You will find **`Saw.c`** inside — this is the only file you need.

**Option 2 — Clone with Git (if you have Git installed)**

Open Command Prompt and type:
```bash
git clone https://github.com/YOUR-USERNAME/YOUR-REPO-NAME.git
```
Then `cd` into the folder:
```bash
cd YOUR-REPO-NAME
```

> 💡 **Not sure which option to use?** Use Option 1. It requires no extra software.

---

### 🛠️ Choose Your Method

Pick the one that suits you best — or the one you already have installed:

| Method | IDE / Tool | Best For | Difficulty |
|---|---|---|---|
| [1](#-method-1--codeblocks--best-for-beginners) | Code::Blocks | Beginners, CS students | ⭐ Easiest |
| [2](#-method-2--dev-c--lightest-option) | Dev-C++ | Beginners, fastest install | ⭐ Easiest |
| [3](#-method-3--visual-studio-code--lightweight--modern) | Visual Studio Code | All levels, modern editor | ⭐⭐ Easy |
| [4](#-method-4--visual-studio-community--full-ide) | Visual Studio Community | Advanced users, full IDE | ⭐⭐⭐ Medium |
| [5](#-method-5--command-prompt-only--no-ide-needed) | Command Prompt only | Any level, no IDE at all | ⭐⭐ Easy |

> 👶 **First time?** Start with **Method 1 (Code::Blocks)** or **Method 2 (Dev-C++)** — both include the compiler bundled in and require the fewest setup steps.

---

### 🟦 Method 1 — Code::Blocks *(Best for Beginners)*

**Code::Blocks** is a free IDE built specifically for C and C++ programming. It includes everything you need in one installer — editor, compiler, and build tools. It is the most beginner-friendly choice and is widely used in introductory programming courses.

---

**Step 1 — Download Code::Blocks**

1. Open your browser and go to:
   👉 **https://www.codeblocks.org/downloads/binaries/**

2. Scroll down and look for the file that includes **"mingw"** in its name. It will look like:
   ```
   codeblocks-20.03mingw-setup.exe
   ```
   > ⚠️ **This is critical.** The file with "mingw" in the name includes the GCC compiler. The one without "mingw" does NOT include a compiler — and the project will not build without it. Always download the **mingw** version.

3. Click the download link (use the **FossHub** or **Sourceforge** mirror).

---

**Step 2 — Install Code::Blocks**

1. Run the downloaded `.exe` file.
2. If Windows shows a security warning, click **"Run Anyway"** — this is a safe, well-known application.
3. Click **Next** → **I Agree** → **Next** → **Install**.
4. Wait for the installation to finish, then click **Finish**.
5. When asked *"Do you want to run Code::Blocks now?"* — click **Yes**.

---

**Step 3 — Create a New Project**

1. When Code::Blocks opens, click **File** → **New** → **Project**.
2. A window appears. Select **Console Application** → click **Go**.
3. A wizard opens. Select **C** (not C++) → click **Next**.
4. Fill in the details:
   - **Project title:** `SystemDashboard` (or any name you like)
   - **Folder to create project in:** Browse to `C:\Projects\SystemDashboard\`
5. Click **Next** → **Finish**.

---

**Step 4 — Add `Saw.c` to the Project**

1. Look at the left panel — this is the **Management** panel. You will see a tree with a **Sources** folder inside it.
2. Right-click the **Sources** folder → click **"Add files..."**
3. Browse to where you saved `Saw.c` → select it → click **Open**.
4. Code::Blocks may ask which build targets to add it to — just click **OK**.
5. *(Optional but recommended)* Right-click the default `main.cpp` file that Code::Blocks created → **"Remove file from project"**. Do not delete it — just remove it from the project so it does not conflict.

---

**Step 5 — Build and Run**

1. Press **F9** on your keyboard.
   *(Or click the menu: **Build** → **Build and Run**)*
2. A black terminal window will open — the **System Tools Dashboard** is running!
3. Type a number and press **Enter** to use any feature.

> ✅ **Success looks like:** The terminal shows the dashboard menu with options 1–5.
>
> ❌ **If you see red errors:** You likely downloaded the version of Code::Blocks without "mingw". Go back to Step 1 and re-download the correct version.

---

### 🟩 Method 2 — Dev-C++ *(Lightest Option)*

**Dev-C++** is an extremely lightweight IDE for C — it installs in under a minute and comes with a compiler already bundled. It is ideal if you want something minimal and fast.

---

**Step 1 — Download Dev-C++**

1. Go to:
   👉 **https://sourceforge.net/projects/orwelldevcpp/**
2. Click the green **Download** button.
3. Run the downloaded installer → click **Next** through all steps → click **Finish**.
4. Open Dev-C++ — the compiler is already included. ✅

---

**Step 2 — Open the Source File**

1. In Dev-C++, click **File** → **Open Project or File**.
2. Browse to the folder where you saved `Saw.c`.
3. Select `Saw.c` → click **Open**.
4. The code will appear in the editor.

---

**Step 3 — Compile and Run**

1. Press **F11** on your keyboard.
   *(Or click: **Execute** → **Compile & Run**)*
2. Dev-C++ will compile the code and open a terminal window automatically.
3. The System Tools Dashboard is now running. 🎉

> ✅ It really is that simple with Dev-C++. Three steps and you are done.
>
> ❌ **If you see an error about `<conio.h>` or `<windows.h>`:** Make sure you are on Windows. These headers are Windows-only and will not work on Linux or macOS.

---

### 🟨 Method 3 — Visual Studio Code *(Lightweight & Modern)*

**Visual Studio Code** (VS Code) is a free, lightweight, and highly popular code editor made by Microsoft. It is not a full IDE — it is a smart text editor that you extend with plugins. It is used by millions of developers worldwide and is excellent for C programming once set up. It requires a separate compiler installation, but the setup is straightforward.

> 💡 **VS Code vs Visual Studio Community:** VS Code is light and fast — installs in seconds. Visual Studio Community is heavy and full-featured — installs in 20+ minutes. For most students, VS Code is the better daily editor.

---

**Step 1 — Download and Install VS Code**

1. Go to:
   👉 **https://code.visualstudio.com/**
2. Click the big **"Download for Windows"** button.
3. Run the downloaded installer.
4. During installation, check both of these boxes when you see them:
   - ✅ **"Add 'Open with Code' action to Windows Explorer file context menu"**
   - ✅ **"Add to PATH"**
5. Click **Next** → **Install** → **Finish**.

---

**Step 2 — Install the C/C++ Extension**

VS Code needs a plugin to understand C code (syntax highlighting, error detection, etc.).

1. Open VS Code.
2. Press **Ctrl + Shift + X** — this opens the **Extensions** panel on the left.
3. In the search box at the top, type: `C/C++`
4. Find the extension by **Microsoft** — it will say *"C/C++ IntelliSense, debugging, and code browsing"*.
5. Click **Install**.

---

**Step 3 — Install the GCC Compiler (MinGW)**

VS Code is only an editor — it does not compile code by itself. You must install a C compiler separately.

1. Go to:
   👉 **https://github.com/niXman/mingw-builds-binaries/releases**
2. Find the latest release. Download the file that looks similar to:
   ```
   x86_64-14.2.0-release-win32-seh-msvcrt-rt_v12-rev0.7z
   ```
   *(The exact version numbers may differ — just pick the latest one)*

3. You need **7-Zip** to extract this file. If you do not have it:
   👉 **https://www.7-zip.org/** → Download → Install.

4. Right-click the downloaded `.7z` file → **7-Zip** → **Extract to** → choose the folder `C:\mingw64\`

5. Now tell Windows where to find GCC by adding it to your **PATH**:
   - Press the **Windows key** → type **"environment variables"** → click **"Edit the system environment variables"**.
   - Click the **"Environment Variables..."** button.
   - In the lower box (**System variables**), scroll to find **"Path"** → click it → click **"Edit"**.
   - Click **"New"** → type `C:\mingw64\bin` → click **OK** on every open window.

6. **Verify it worked:** Open a fresh Command Prompt window and type:
   ```bash
   gcc --version
   ```
   If it prints something like `gcc (x86_64-win32-seh) 14.2.0`, you are all set. ✅

> ⚠️ **Important:** You must open a **new** Command Prompt window after editing the PATH — old windows will not see the change.

---

**Step 4 — Open the Project in VS Code**

1. Open VS Code.
2. Click **File** → **Open Folder**.
3. Browse to and select the folder where you saved `Saw.c` (e.g. `C:\Projects\SystemDashboard\`).
4. Click **"Select Folder"**.
5. `Saw.c` will appear in the left **Explorer** panel — click on it to open it in the editor.

---

**Step 5 — Compile and Run**

1. Press **Ctrl + `** (that is the backtick key, to the left of the `1` key) to open VS Code's built-in terminal.
2. In the terminal, type this compile command and press **Enter**:
   ```bash
   gcc -o SystemToolsDashboard Saw.c -Wall -std=c99
   ```
3. If there are no errors, a file called `SystemToolsDashboard.exe` will appear in your folder.
4. Now run it by typing:
   ```bash
   SystemToolsDashboard.exe
   ```
5. The dashboard will launch right inside VS Code's terminal! 🎉

> ✅ **Success looks like:** The terminal shows the main menu with options 1–5.
>
> ❌ **"gcc is not recognized as a command":** The PATH was not set correctly. Go back to Step 3, make sure you opened a **new** terminal after editing PATH, and try again.
>
> ❌ **"No such file or directory":** You are in the wrong folder. Type `cd C:\Projects\SystemDashboard` (or wherever you saved the file) before compiling.

---

### 🟪 Method 4 — Visual Studio Community *(Full IDE)*

**Visual Studio Community** is Microsoft's professional-grade IDE, available completely free for students and individual developers. It is the largest and most feature-rich option here — it takes longer to install but gives you the most powerful development environment available on Windows.

---

**Step 1 — Download Visual Studio Community**

1. Go to:
   👉 **https://visualstudio.microsoft.com/vs/community/**
2. Click **"Download Visual Studio"** — this downloads the installer.
3. Run the installer file.

---

**Step 2 — Choose the Right Workload**

This step is important. Visual Studio is modular — you install only what you need.

1. When the **Workloads** screen appears, check the box for:
   **"Desktop development with C++"**
   *(This includes the MSVC compiler, which is needed to build C programs)*
2. Click **Install** in the bottom right corner.

> ⏳ Installation may take **10 to 30 minutes** depending on your internet speed and computer. This is normal — Visual Studio is a large, professional tool.

---

**Step 3 — Create a New Project**

1. Open Visual Studio.
2. On the start screen, click **"Create a new project"**.
3. In the search bar at the top, type: `Empty Project`
4. Select **"Empty Project"** (the one that shows **C++** in the tags) → click **Next**.
5. Set the **Project name** to `SystemDashboard`.
6. Set the **Location** to wherever you want to save it.
7. Click **Create**.

---

**Step 4 — Add `Saw.c` to the Project**

1. On the right side of the screen, find the **Solution Explorer** panel.
2. Right-click the **Source Files** folder → click **Add** → **Existing Item...**.
3. Browse to where you saved `Saw.c` → select it → click **Add**.

---

**Step 5 — Set Compile Mode to C (Important)**

By default, Visual Studio compiles as C++. Since this is a C file, you must tell it to use C mode:

1. In the **Solution Explorer**, right-click `Saw.c` → click **Properties**.
2. Go to: **C/C++** → **Advanced**
3. Find the setting **"Compile As"** → change it to **"Compile as C Code (/TC)"**.
4. Click **Apply** → **OK**.

---

**Step 6 — Build and Run**

1. Press **Ctrl + F5** (Run Without Debugging).
2. A terminal window opens — the System Tools Dashboard is running!

> 💡 **Tip:** If Visual Studio closes the terminal window immediately after the program ends, go to **Tools** → **Options** → **Debugging** → uncheck **"Automatically close the console when debugging stops"**.

---

### ⬛ Method 5 — Command Prompt Only *(No IDE Needed)*

This method uses just the Windows Command Prompt — no IDE required. It is a great way to understand exactly what compiling a C program actually does, without any buttons or menus in the way.

---

**Step 1 — Install the GCC Compiler (MinGW)**

If you already installed Code::Blocks with the mingw version, GCC is already on your machine — skip to Step 2.

Otherwise, install it manually:

1. Go to:
   👉 **https://github.com/niXman/mingw-builds-binaries/releases**
2. Find the latest release. Download the file that looks like:
   ```
   x86_64-XX.X.X-release-win32-seh-msvcrt-rt_vXX.7z
   ```
3. Extract it using **7-Zip** (free tool at https://www.7-zip.org/) to the folder `C:\mingw64\`

4. Now add GCC to your system PATH so Command Prompt can find it:
   - Press the **Windows key**, type **"Environment Variables"**, and click **"Edit the system environment variables"**.
   - In the window that opens, click the **"Environment Variables..."** button.
   - Under **"System variables"**, scroll to find **"Path"** → click it → click **"Edit"**.
   - Click **"New"** → type `C:\mingw64\bin` → click **OK** on all open windows.

5. Verify it worked: Open a new Command Prompt window and type:
   ```bash
   gcc --version
   ```
   If it prints a version number, GCC is installed correctly. ✅

---

**Step 2 — Navigate to the Project Folder**

1. Press **Windows key + R**, type `cmd`, press **Enter** to open Command Prompt.
2. Navigate to the folder where `Saw.c` is saved using the `cd` command:
   ```bash
   cd C:\Projects\SystemDashboard
   ```
   > 💡 **Tip:** You can also right-click inside the folder in File Explorer while holding **Shift**, then click **"Open PowerShell window here"** or **"Open Command Prompt here"** — this opens the terminal already in the right folder.

---

**Step 3 — Compile the Program**

Type this command exactly and press **Enter**:
```bash
gcc -o SystemToolsDashboard Saw.c -Wall -std=c99
```

**What this command means — explained simply:**

| Part | What it means |
|---|---|
| `gcc` | Run the GCC compiler |
| `-o SystemToolsDashboard` | Name the output file `SystemToolsDashboard.exe` |
| `Saw.c` | This is the source file to compile |
| `-Wall` | Show all warnings (helps catch mistakes) |
| `-std=c99` | Use the C99 version of the C standard |

After running this, a file called `SystemToolsDashboard.exe` will appear in the same folder.

---

**Step 4 — Run the Program**

```bash
SystemToolsDashboard.exe
```

The System Tools Dashboard will launch immediately in the same Command Prompt window.

---

### ▶️ Running the Dashboard

Once the program is running in any of the methods above, you will see the main menu:

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

**How to use it:**

1. Type the number for the feature you want (e.g. `1`) and press **Enter**.
2. The program runs the selected task and shows you the output.
3. When the task is done, press **any key** to return to the main menu.
4. To close the program, type `5` and press **Enter**.

> ⚠️ **Administrator Note:** Option 3 (System Shutdown) requires Administrator privileges.
> To run as Administrator: right-click the `.exe` file (or your IDE shortcut) → **"Run as administrator"**.

---

## 6. Feature Guide — What Each Option Does

### 🔷 Option 1 — Network Configuration

**What happens:** The program runs `ipconfig` and displays all network adapter information for your machine.

**Useful when:**
- You need to find your local IP address quickly (e.g. for sharing files on a network).
- You want to check your gateway or DNS settings.
- You are troubleshooting a network connection and need to see adapter details.

**Sample output:**
```
Wireless LAN adapter Wi-Fi:
   IPv4 Address. . . . . . . . : 192.168.1.15
   Subnet Mask . . . . . . . . : 255.255.255.0
   Default Gateway . . . . . . : 192.168.1.1
```

---

### 🔷 Option 2 — View Running Processes

**What happens:** The program runs `tasklist` and shows every process currently running on your computer, along with its Process ID (PID) and memory usage.

**Useful when:**
- Your PC is running slowly and you want to find what is using resources.
- You want to check if a specific application is open.
- You are studying operating system concepts and want to see processes in real time.

**Sample output:**
```
Image Name                     PID  Session Name     Mem Usage
========================= ======== =============== ============
System Idle Process              0 Services              8 K
chrome.exe                    4512 Console          312,456 K
```

---

### 🔷 Option 3 — System Shutdown

**What happens:** The program schedules a system shutdown in 60 seconds and shows a live countdown in the terminal. You can press `C` at any time during the countdown to cancel it.

**Useful when:**
- You are leaving your desk but want the PC to shut down after a short delay.
- You want a safe, interruptible shutdown — not an instant one.

**Cancelling the shutdown:**
```
 Shutting down in: 38 second(s)...
```
Press `C` →
```
 Shutdown successfully cancelled.
```

> ⚠️ **Do not close the terminal window** to try and cancel the shutdown — that will not work. You must press `C` while the program is running, or open Command Prompt separately and type `shutdown /a`.

---

### 🔷 Option 4 — Network Ping Tools

**What happens:** Opens a submenu with two ping options.

**Submenu:**
```
  [1] Internal test    (loopback 127.0.0.1)
  [2] External / target ping  (custom IP or hostname)
  [0] Back to main menu
```

**Sub-option 1 — Internal Loopback Test**

Pings your own machine at `127.0.0.1`. This tests whether your computer's internal network stack is working — it does not go out to the internet at all.

- If this **succeeds** → your PC's networking software is healthy.
- If this **fails** → the problem is in your Windows networking stack or driver, not your router.
- If this **succeeds but internet does not work** → the problem is your router or ISP.

**Sub-option 2 — Custom Ping**

Lets you type any IP address or website hostname to ping it directly.

```
 Enter target IP address or hostname
 (e.g.  8.8.8.8  or  google.com): google.com
```

> 🔒 **Security note:** For your safety, only letters, numbers, `.`, `-`, and `_` are accepted as input. Any other character is blocked to prevent dangerous commands from being executed.

---

## 7. About the Developer

### 🎓 Academic Background

This project was created by a **first-year BCA (Bachelor of Computer Applications) student** — a beginner developer at the very start of a four-year undergraduate computing degree.

**About the BCA Program:**
BCA is a four-year, eight-semester undergraduate degree structured around both theoretical foundations and practical application. The curriculum is divided into two semesters per year. The first year introduces core computing subjects: C programming, mathematics for computing, digital logic and computer organisation, microprocessor fundamentals, and communication skills. The program is designed to build students from the ground up — starting with the basics of how computers work and how to write structured, functional code.

**Developer Background:**
At the time this project was built, the developer was a first-year BCA student — with no prior professional development experience, no industry internships, and no formal programming background before enrolling. The only foundation was first-year coursework: lectures, lab sessions, and the C programming curriculum covered in year one.

This is a **first-year project** — not a capstone, not a senior submission. It was built at the very beginning of a computing education, by a student still learning the fundamentals.

---

### 📘 About This Assignment

This program was developed and submitted as **Project I** — a first-year practical programming assignment. The purpose of the assignment is to demonstrate mastery of core C programming fundamentals through the design and implementation of a complete, functional program.

Rather than following the most common path — building a calculator or a basic text menu — this first-year BCA student chose to build a **real Windows utility tool** that has genuine everyday value. That choice reflects a mindset that views programming not just as an academic task, but as engineering: identifying a real problem and building a practical solution for it.

---

### 💡 The Developer's Goals

When starting this project, the following goals were set:

- **Build something genuinely useful** — a program that could be opened on any Windows PC and used by a classmate, a teacher, or a working professional.
- **Go beyond first-year theory** — cover not just the syntax taught in class, but also OS-level interaction, Windows API usage, and security-aware input handling.
- **Write professional-quality code** — clean function naming, single-responsibility design, proper comments, and no shortcuts on input validation.
- **Think like an engineer** — approach the assignment as a real problem to solve, not just an exercise to complete.

---

### 🤝 A Note to Fellow Students

If you are a student — anywhere in the world — you are welcome to:

- **Fork this repository** and build on it for your own coursework.
- **Read the code** as a reference for C fundamentals and program structure.
- **Contribute** bug fixes, new features, or improvements via pull request.
- **Ask questions** by opening an issue on GitHub.

The best way to grow as a programmer is to write real programs, share your work, and learn from the code others have written. This repository exists in that spirit.

---

## 8. How This Project Was Built

### Planning

Before writing any code, the core questions were defined:

- Which Windows commands do students and IT users run most frequently?
- What is the minimum interface that makes those commands accessible to anyone?
- What security risks exist when a C program passes user input to the shell — and how should they be handled?

The answers defined the feature set: `ipconfig`, `tasklist`, `ping` (two variants), and a cancellable `shutdown` timer.

### Key Design Decisions

**Single-file architecture:** The entire program lives in `Saw.c`. For a project of this scope, splitting into multiple files would add complexity without benefit. A single file is easy to share, read, compile, and understand.

**Modular functions:** Every distinct responsibility is isolated into its own function. `main()` manages the loop. `handle_ping_options()` manages the ping submenu. `is_valid_ping_target()` handles validation. `run_ping()` handles execution. This separation makes the code readable and easy to extend.

**Deliberate use of `system()` with validation:** The `system()` function is the most straightforward way to run OS commands from C. It is often criticized as unsafe — but the risk is entirely in the input. This project addresses that directly by validating every character before passing anything to the shell.

**Interactive shutdown countdown:** Rather than a blocking `sleep`, the countdown uses `_kbhit()` to poll for keyboard input every second. This makes the cancel feature genuinely responsive and safe.

### Development Stack

| Component | Choice |
|---|---|
| Language | C (C99 standard) |
| Platform | Windows 7 / 10 / 11 |
| Compiler | GCC via MinGW or MSVC |
| IDE | Code::Blocks / Dev-C++ / Visual Studio Code / Visual Studio Community |
| Windows APIs used | `_kbhit()`, `_getch()` from `<conio.h>` · `Sleep()` from `<windows.h>` |

---

## 9. Why C Was Chosen

C was not chosen for convenience. It was the deliberate right tool for this project.

| Reason | Explanation |
|---|---|
| **Direct OS access** | C calls Windows API functions like `Sleep()` and `_kbhit()` directly — no extra libraries or frameworks needed |
| **Manual memory management** | Using `snprintf` with buffer size limits and `%127s` in `scanf` teaches memory safety concepts that are fundamental to CS education |
| **Zero-overhead performance** | The program compiles to a native `.exe` that starts instantly — no runtime, no virtual machine, no interpreter |
| **Industry relevance** | C remains the dominant language for operating systems, embedded systems, and system-level programming worldwide |
| **Academic fit** | C is the primary language taught in CS and IT programs everywhere, making this project directly applicable to coursework and examinations |

---

## 10. What This Project Teaches

Every C concept demonstrated in this project, mapped to where it appears in the code:

| Concept | Where in `Saw.c` |
|---|---|
| `#include` directives and header files | Top four lines |
| Forward declarations | Lines before `main()` |
| `while(1)` infinite loop with controlled exit | `main()` — runs until user presses 5 |
| `switch-case` for multi-branch menu logic | Both `main()` and `handle_ping_options()` |
| `scanf` for reading typed input | Every menu prompt |
| Input buffer flushing after `scanf` | `flush_stdin()` function |
| String validation — character by character | `is_valid_ping_target()` |
| Safe string building with `snprintf` | `run_ping()` |
| Calling OS commands with `system()` | Every feature case |
| Windows Console API | `_kbhit()`, `_getch()`, `Sleep()` |
| Real-time output flushing | `fflush(stdout)` in the shutdown countdown |
| Security — blocking command injection | Character whitelist in `is_valid_ping_target()` |
| Security — preventing buffer overflow | `%127s` and `snprintf` with `sizeof()` |
| Timer implementation with `Sleep()` | Shutdown countdown loop |
| Error recovery when `scanf` fails | `scanf` return value check + `flush_stdin()` + `continue` |
| Modular function design | Entire file structure |

---

## 11. Future Improvements

This project is intentionally kept small and focused. Here are directions it could grow:

- **`netstat` support** — Show active network connections and listening ports, useful for developers and sysadmins.
- **`systeminfo` option** — Display OS version, uptime, installed RAM, CPU, and machine name.
- **Configurable shutdown timer** — Let the user type how many seconds before shutdown, instead of hardcoding 60.
- **Output logging** — Save `ipconfig` or `tasklist` results to a timestamped `.txt` file for later reference.
- **Colour-coded terminal output** — Use Windows Console API colour functions to highlight warnings in red and success in green.
- **`tracert` (traceroute) option** — Trace the network path to any address, useful for diagnosing where a connection is failing.
- **Cross-platform port** — Refactor using POSIX alternatives to `<conio.h>` and `<windows.h>` so the program works on Linux and macOS too.
- **Custom command config file** — Allow users to define their own menu items in a `.cfg` file without modifying the source code.

---

<br>

> *"Good engineering is not about writing the most complex code — it is about solving a real problem simply, safely, and clearly. This project was built with that principle from the first line to the last."*

---

| | |
|---|---|
| **Project** | System Tools Dashboard |
| **Source File** | `Saw.c` |
| **Language** | C (C99) |
| **Platform** | Windows 7 / 10 / 11 |
| **Type** | Systems Utility · Academic Submission (First-Year Project) |
| **Developer** | First-Year BCA Student |

