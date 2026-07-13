# A1. Which command tails the LAST 50 lines of a log file and keeps showing new lines?

### **Correct Answer:** ✅ **(b)**

```bash
tail -n 50 -f log.txt
```

## Simple Explanation

This command:

- **`tail`** → Shows the last lines of a file.
- **`-n 50`** → Displays the last **50 lines**.
- **`-f`** → Continuously shows **new lines** as they are added.
- **`log.txt`** → The log file to monitor.

### Example

```bash
tail -n 50 -f log.txt
```

This command shows the **last 50 lines** of `log.txt` and keeps updating the screen whenever new log messages are written.

## Why the Other Options Are Wrong

- ❌ **(a)** `cat` shows the whole file.
- ❌ **(c)** `head` shows the first 50 lines.
- ❌ **(d)** `less` only lets you view a file; it doesn't continuously show new lines.

### Summary

Use:

```bash
tail -n 50 -f log.txt
```

to **view the last 50 lines of a log file and monitor new log entries in real time.**
````markdown id="zw0l31"
# A2. Which is the modern, faster alternative to grep for recursive code search?

### **Correct Answer:** ✅ **(b) `rg` (ripgrep)**

## Simple Explanation

**`rg` (ripgrep)** is a fast tool used to search for text inside files and folders.

It automatically searches **all files and subfolders** (recursive search) and is much faster than `grep`.

### Example

```bash
rg "main"
```

This searches for the word **"main"** in all files inside the current folder and its subfolders.

## Why the Other Options Are Wrong

- ❌ **(a)** `ack` is an older search tool.
- ❌ **(c)** `sed` is used to edit and replace text.
- ❌ **(d)** `awk` is used for text processing and data manipulation.

### Summary

Use **`rg` (ripgrep)** for **fast recursive code searching** in projects.
````

````markdown id="g5v4k8"
# A3. `Ctrl + C` in a terminal sends which signal to the foreground process?

### **Correct Answer:** ✅ **(c) SIGINT**

## Simple Explanation

Pressing **`Ctrl + C`** sends the **SIGINT (Interrupt Signal)** to the currently running program.

It tells the program to **stop running**.

### Example

Suppose you run:

```bash
ping google.com
```

It keeps running continuously.

Press:

```text
Ctrl + C
```

The program stops immediately.

## Why the Other Options Are Wrong

- ❌ **(a) SIGTERM** – Requests a program to terminate gracefully, but it is **not** sent by `Ctrl + C`.
- ❌ **(b) SIGKILL** – Forcefully kills a program and cannot be ignored. It is **not** sent by `Ctrl + C`.
- ❌ **(d) SIGSTOP** – Pauses (stops) a program without terminating it. It is **not** sent by `Ctrl + C`.

### Summary

**`Ctrl + C` sends the `SIGINT` signal to interrupt and stop the currently running program.**
````
````markdown id="ccu6gq"
# A4. `Ctrl + Z` does what, and how do you resume?

### **Correct Answer:** ✅ **(b)**

> **Suspends the foreground process (SIGTSTP); resume with `fg`.**

## Simple Explanation

Pressing **`Ctrl + Z`** **pauses (suspends)** the currently running program. It does **not** stop or kill the program.

To continue running the paused program, use:

```bash
fg
```

This brings the program back to the foreground.

### Example

Run:

```bash
ping google.com
```

Press:

```text
Ctrl + Z
```

Output:

```text
[1]+ Stopped ping google.com
```

To continue:

```bash
fg
```

The `ping` command starts running again.

## Why the Other Options Are Wrong

- ❌ **(a)** It does not close the terminal.
- ❌ **(c)** It does not kill the process.
- ❌ **(d)** It does not save the file.

### Summary

- **`Ctrl + Z`** → Suspends (pauses) the current program.
- **`fg`** → Resumes the suspended program in the foreground.
````

