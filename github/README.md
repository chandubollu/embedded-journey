### GIT BASICS
##### Getting a Git Repository
You typically obtain a Git repository in one of two ways:
1. You can take a local directory that is currently not under
 version control, and turn it into a Git repository,
           or
2. You can clone an existing Git repository from elsewhere.
In either case, you end up with a Git repository on your local
 machine, ready for work.
Here's your text formatted as clean Markdown.

###### Initializing a Git Repository

If you have a project directory that is **not currently under version control** and you want to start managing it with **Git**, you first need to navigate to that project's directory.

The command differs slightly depending on your operating system.

###### Linux

```bash
cd /home/user/my_project
```

###### macOS

```bash
cd /Users/user/my_project
```

###### Windows

```bash
cd /c/user/my_project
```

###### Initialize the Git Repository

Once you are inside the project directory, run:

```bash
git init
```

This command creates a new Git repository in the current directory by generating a hidden `.git` folder, which Git uses to store all version control information.


###### What Happens After `git init`

When you run the following command:

```bash
git init
```

Git creates a new hidden directory named **`.git`** inside your project folder.

The **`.git`** directory contains all the information Git needs to manage your project, including:

* Commit history
* Branch information
* Configuration settings
* References
* Objects (snapshots of your files)

At this point, **none of your project files are being tracked yet**. Only the Git repository has been initialized.

> **Note:** The `.git` directory is the heart of your Git repository. Without it, Git cannot track changes or maintain version history.

---

###### Start Tracking Existing Files

If your project already contains files and you want Git to start tracking them, you need to add them to the **staging area** before making the first commit.

For example:

```bash
git add *.c
```

This command stages all files with the `.c` extension.

```bash
git add LICENSE
```

This command stages the `LICENSE` file.

You can also stage **all files** in the current directory:

```bash
git add .
```

---

###### Create the Initial Commit

After staging the files, create your first commit:

```bash
git commit -m "Initial project version"
```

The `-m` option lets you provide a commit message directly from the command line.

---

###### Complete Example

```bash
git init
git add *.c
git add LICENSE
git commit -m "Initial project version"
```

Or, to stage all files:

```bash
git init
git add .
git commit -m "Initial project version"
```

---

###### What You Have Now

After these commands, your project has:

* ✅ A Git repository (`.git` directory)
* ✅ Tracked project files
* ✅ An initial commit
* ✅ A version history that Git can manage

From this point onward, Git will monitor changes to the tracked files, allowing you to save versions, view history, create branches, and collaborate with others.
###### Cloning an Existing Git Repository

If you want to get a copy of an **existing Git repository** (for example, a project hosted on GitHub that you want to contribute to), use the following command:

```bash
git clone <repository-url>
```

###### What is `git clone`?

The `git clone` command creates a complete copy of an existing Git repository on your local computer.

Unlike some other Version Control Systems (VCS) such as **Subversion (SVN)**, Git does **not** download only the latest version of the project. Instead, it downloads:

* The complete project
* The entire commit history
* All branches (references)
* All tracked files
* The hidden `.git` directory

This means your local copy is a **full Git repository**, not just a working copy.

---

####### Basic Syntax

```bash
git clone <repository-url>
```

 Example

```bash
git clone https://github.com/libgit2/libgit2
```

---

###### What Happens When You Run `git clone`?

Suppose you run:

```bash
git clone https://github.com/libgit2/libgit2
```

Git performs the following steps automatically:

1. Creates a new folder named **`libgit2`**.
2. Creates a hidden **`.git`** directory inside it.
3. Downloads the complete repository history.
4. Downloads all tracked project files.
5. Checks out the latest version of the project.
6. Sets up the remote repository (named `origin`) so you can communicate with the original repository later.

After cloning, your folder structure looks like this:

```text
libgit2/
│
├── .git/
├── README.md
├── LICENSE
├── src/
├── include/
└── ...
```

Now the project is ready for development.

---

###### Clone into a Different Folder Name

By default, Git names the new folder after the repository.

For example:

```bash
git clone https://github.com/libgit2/libgit2
```

creates:

```text
libgit2/
```

If you want a different folder name, specify it as the second argument.

###### Example

```bash
git clone https://github.com/libgit2/libgit2 mylibgit
```

Git creates:

```text
mylibgit/
```

instead of:

```text
libgit2/
```

Everything else remains exactly the same.

---

###### What Does Git Download?

When you clone a repository, Git downloads:

* ✅ Entire commit history
* ✅ All tracked files
* ✅ All commits
* ✅ Branch references
* ✅ Tags
* ✅ The `.git` directory

Because every clone contains the complete history, it can serve as a backup of the repository if the original server becomes unavailable.

---

###### Common Git Clone Examples

Clone a public GitHub repository:

```bash
git clone https://github.com/libgit2/libgit2
```

Clone into a custom directory:

```bash
git clone https://github.com/libgit2/libgit2 mylibgit
```

Clone using SSH:

```bash
git clone git@github.com:libgit2/libgit2.git
```

---

###### Git Transfer Protocols

Git supports several protocols for cloning repositories.

| Protocol | Example                            | Typical Use                                    |
| -------- | ---------------------------------- | ---------------------------------------------- |
| HTTPS    | `https://github.com/user/repo.git` | Most common, easy to use                       |
| SSH      | `git@github.com:user/repo.git`     | Recommended for developers who push frequently |
| Git      | `git://server/repository.git`      | Git protocol (less common today)               |

---

###### Summary

* `git clone` creates a complete local copy of an existing Git repository.
* It downloads the **entire project history**, not just the latest files.
* A hidden `.git` directory is created automatically.
* By default, the repository name becomes the folder name.
* You can choose a different folder name by providing it as a second argument.
* After cloning, you can immediately view, modify, commit, and push changes (if you have permission).

###### Recording Changes to the Repository

After creating or cloning a Git repository, you will start making changes to your project. Git records these changes as **commits**, which act like snapshots of your project at a specific point in time.

The typical Git workflow is:

```text
Create/Edit File
       │
       ▼
Working Directory
       │
git add
       ▼
Staging Area
       │
git commit
       ▼
Git Repository
```

---

###### File States in Git

Every file in your project is in one of two main categories:

###### 1. Tracked Files

Tracked files are files that Git already knows about.

A tracked file can be in one of three states:

* **Unmodified** – The file has not changed since the last commit.
* **Modified** – The file has been changed but not staged.
* **Staged** – The modified version is ready to be committed.

Example:

```text
main.c
```

If `main.c` was committed before, Git considers it a **tracked file**.

---

###### 2. Untracked Files

Untracked files are files that Git has never seen before.

Example:

```text
README.md
notes.txt
image.png
```

Git does not include these files in commits until you explicitly tell it to track them.

---

###### Git File Lifecycle

```text
                git add
Untracked -----------------> Staged
                               │
                               │ git commit
                               ▼
                          Tracked (Unmodified)
                               │
                     Edit the file
                               ▼
                          Modified
                               │
                          git add
                               ▼
                            Staged
                               │
                          git commit
                               ▼
                     Tracked (Unmodified)
```

---

###### Checking File Status

Use:

```bash
git status
```

Example:

```text
On branch main

nothing to commit, working tree clean
```

This means:

* No modified files
* No staged files
* No untracked files

Everything is up to date.

---

###### Creating a New File

Create a file:

```bash
echo "My Project" > README.md
```

Now check the status:

```bash
git status
```

Output:

```text
Untracked files:

README.md
```

Git sees the file but is **not tracking it yet**.

---

###### Start Tracking a New File

Use:

```bash
git add README.md
```

Now check again:

```bash
git status
```

Output:

```text
Changes to be committed:

new file: README.md
```

The file is now:

* Tracked
* Staged
* Ready for commit

---

###### Commit the File

```bash
git commit -m "Add README"
```

After committing:

```bash
git status
```

Output:

```text
nothing to commit, working tree clean
```

---

###### Modifying an Existing File

Suppose you edit:

```text
README.md
```

Now run:

```bash
git status
```

Output:

```text
Changes not staged for commit:

modified: README.md
```

This means:

* Git knows about the file.
* You changed it.
* The changes are **not staged yet**.

---

###### Stage the Modified File

```bash
git add README.md
```

Check again:

```bash
git status
```

Output:

```text
Changes to be committed:

modified: README.md
```

Now the updated version is ready to be committed.

---

###### Modify the File Again

Suppose you edit `README.md` **after** running:

```bash
git add README.md
```

Now check:

```bash
git status
```

Output:

```text
Changes to be committed:

modified: README.md

Changes not staged for commit:

modified: README.md
```

Why does the same file appear twice?

Because Git stores the version of the file **at the moment you ran `git add`**.

After staging it, you edited it again.

Now there are **two versions**:

1. **Staged version** → Ready to commit.
2. **Latest working version** → Not yet staged.

---

###### Stage the Latest Changes

Run:

```bash
git add README.md
```

again.

Now:

```bash
git status
```

shows:

```text
Changes to be committed:

modified: README.md
```

The newest version is now staged.

---

###### Important Rule

> Every time you modify a file **after** running `git add`, you must run `git add` **again** before committing if you want the latest changes included in the commit.

---

###### Common Git Commands

| Command                   | Purpose                                    |
| ------------------------- | ------------------------------------------ |
| `git status`              | Show the current state of files            |
| `git add <file>`          | Start tracking or stage a file             |
| `git add .`               | Stage all changes in the current directory |
| `git commit -m "message"` | Save staged changes as a commit            |
| `git restore <file>`      | Discard unstaged changes (Git 2.23+)       |

---

###### Git Workflow Summary

```text
Create/Edit File
       │
       ▼
git status
       │
       ▼
git add <file>
       │
       ▼
git status
       │
       ▼
git commit -m "Meaningful commit message"
       │
       ▼
Repository Updated
```

---

###### Key Points

* `git status` tells you what has changed.
* `git add` stages files for the next commit.
* `git commit` permanently records the staged changes.
* New files are **untracked** until you use `git add`.
* Modified files must be staged again if you edit them after running `git add`.
* A commit contains **only the changes that are staged**, not every change in your working directory.
Here's the content rewritten into a clean, beginner-friendly Markdown format for your `notes.md`.

##### Short Status in Git

The output of the `git status` command is detailed and easy to understand, but it can become lengthy when many files have changed.

Git provides a **short status** option that displays the same information in a compact format.

###### Command

```bash
git status -s
```

or

```bash
git status --short
```

---

###### Example Output

```text
$ git status -s

M  README.md
MM Rakefile
A  lib/git.rb
M  lib/simplegit.rb
?? LICENSE.txt
```

---

###### Understanding the Output

The short status output has **two columns**.

```text
XY filename
```

* **First column (X)** → Status of the **Staging Area (Index)**.
* **Second column (Y)** → Status of the **Working Directory**.

```text
 X Y  File
 │ │
 │ └── Working Directory
 └──── Staging Area
```

---

###### Common Status Codes

| Code | Meaning                            |
| ---- | ---------------------------------- |
| `??` | Untracked file                     |
| `A`  | New file added to the staging area |
| `M`  | Modified file                      |
| `D`  | Deleted file                       |
| `R`  | Renamed file                       |
| `C`  | Copied file                        |

---

###### Example 1: Untracked File

```text
?? LICENSE.txt
```

Meaning:

* Git sees a new file.
* The file is **not being tracked**.
* It has **not** been staged.

To start tracking it:

```bash
git add LICENSE.txt
```

---

###### Example 2: Added File

```text
A  lib/git.rb
```

Meaning:

* The file is new.
* It has been staged using `git add`.
* It will be included in the next commit.

---

###### Example 3: Modified File (Not Staged)

```text
 M README.md
```

Notice the space before `M`.

This means:

* **Staging Area:** No changes (` `)
* **Working Directory:** Modified (`M`)

The file has been edited but **not staged**.

To stage it:

```bash
git add README.md
```

---

###### Example 4: Modified File (Already Staged)

```text
M  README.md
```

Notice the `M` is in the **first column**.

This means:

* **Staging Area:** Modified (`M`)
* **Working Directory:** No additional changes (` `)

The modified version is already staged and ready to commit.

---

###### Example 5: `MM`

```text
MM Rakefile
```

This is one of the most important status codes.

It means:

* The file was modified.
* You staged those changes using `git add`.
* Then you modified the file **again** before committing.

So there are **two versions** of the file:

* A staged version (ready for commit)
* A newer, unstaged version (still in your working directory)

To include the latest changes in your next commit, stage the file again:

```bash
git add Rakefile
```

---

###### Visual Explanation

```
Original File
      │
      ▼
Edit File
      │
      ▼
Modified
      │
git add
      ▼
Staged
      │
Edit Again
      ▼
MM
```

The first `M` represents the staged changes.

The second `M` represents the new, unstaged changes.

---

###### Quick Reference

| Short Status | Meaning                               |
| ------------ | ------------------------------------- |
| `?? file`    | Untracked file                        |
| `A  file`    | New file staged                       |
| ` M file`    | Modified but not staged               |
| `M  file`    | Modified and staged                   |
| `MM file`    | Modified, staged, then modified again |
| `D  file`    | File deleted and staged               |
| ` D file`    | File deleted but not staged           |

---

###### Summary

* `git status` provides a detailed view of your repository.
* `git status -s` or `git status --short` provides a compact view.
* The **first column** shows the status of the **Staging Area**.
* The **second column** shows the status of the **Working Directory**.
* `??` indicates an untracked file.
* `MM` means the file has staged changes and additional unstaged changes.
* Always run `git add` again after modifying a staged file if you want the latest changes included in the next commit.

A useful way to remember the two columns is:

```text
git status -s

XY filename

X = Staging Area (what will be committed)
Y = Working Directory (latest edits on your computer)
```

Once you remember **X = Staging** and **Y = Working Directory**, interpreting `git status -s` output becomes much easier.
###### Ignoring Files in Git (`.gitignore`)

Sometimes your project contains files that **should not be tracked by Git**.

These files are usually:

* Log files (`.log`)
* Temporary files
* Compiled object files (`.o`)
* Archive files (`.a`)
* Build output folders
* Cache files
* IDE configuration files
* Automatically generated documentation

Instead of tracking these files, Git allows you to ignore them using a special file called **`.gitignore`**.

---

###### What is `.gitignore`?

A **`.gitignore`** file tells Git which files and folders should be ignored.

Ignored files:

* ✅ Are not shown as untracked.
* ✅ Are not added with `git add .`.
* ✅ Are not committed unless they were already tracked before being ignored.

---

###### Example

Create a `.gitignore` file:

```bash
touch .gitignore
```

Open it and add:

```text
*.[oa]
*~
```

####### Explanation

```text
*.[oa]
```

Ignore all files ending with:

* `.o`
* `.a`

Example:

```text
main.o
math.o
library.a
```

These are commonly generated during compilation.

---

```text
*~
```

Ignore files ending with `~`.

Many text editors create backup files like:

```text
notes.txt~
main.c~
README.md~
```

Git will ignore all of them.

---

###### Common `.gitignore`

```text
###### Ignore object files
*.o

###### Ignore archive files
*.a

###### Ignore log files
*.log

###### Ignore temporary files
*.tmp

###### Ignore backup files
*~

###### Ignore build directory
build/

###### Ignore cache directory
.cache/

###### Ignore generated documentation
docs/generated/
```

---

###### Pattern Rules

###### 1. Blank Lines

Blank lines are ignored.

```text

*.log

```

---

###### 2. Comments

Lines starting with `#` are comments.

```text
###### Ignore log files
*.log
```

---

###### 3. `*` (Asterisk)

Matches **zero or more characters**.

```text
*.log
```

Matches:

```text
error.log
server.log
system.log
```

---

###### 4. `?` (Question Mark)

Matches **exactly one character**.

```text
file?.txt
```

Matches:

```text
file1.txt
fileA.txt
fileX.txt
```

Does **not** match:

```text
file10.txt
```

---

###### 5. Character Sets `[ ]`

```text
file[123].txt
```

Matches:

```text
file1.txt
file2.txt
file3.txt
```

---

###### 6. Character Range

```text
file[0-9].txt
```

Matches:

```text
file1.txt
file5.txt
file9.txt
```

---

###### 7. Ignore a Directory

```text
build/
```

Git ignores:

```text
build/
build/main.o
build/output.exe
build/temp/file.txt
```

---

###### 8. Ignore a Specific File

```text
/TODO
```

Only ignores:

```text
TODO
```

It **does not** ignore:

```text
docs/TODO
src/TODO
```

because of the leading `/`.

---

###### 9. Ignore Files in a Folder

```text
doc/*.txt
```

Matches:

```text
doc/readme.txt
doc/notes.txt
```

Does **not** match:

```text
doc/server/readme.txt
```

---

###### 10. Ignore Files in Nested Folders

```text
doc/**/*.pdf
```

Matches:

```text
doc/file.pdf
doc/tutorial/file.pdf
doc/tutorial/week1/file.pdf
```

---

###### 11. `!` (Negation)

The `!` symbol tells Git **not** to ignore a file.

Example:

```text
*.a
!lib.a
```

Meaning:

Ignore:

```text
math.a
network.a
```

But **do track**:

```text
lib.a
```

---

###### Example `.gitignore`

```text
# Ignore object files
*.o

# Ignore archive files
*.a

# Track lib.a
!lib.a

# Ignore TODO only in root
/TODO

# Ignore build directory
build/

# Ignore text files in doc/
doc/*.txt

# Ignore all PDF files inside doc/ and subdirectories
doc/**/*.pdf
```

---

###### Real-World Example (Embedded Systems)

```text
# Build output
build/

# Object files
*.o

# Executables
*.elf
*.bin
*.hex

# Logs
*.log

# Temporary files
*.tmp

# VS Code settings
.vscode/

# macOS files
.DS_Store

# Windows files
Thumbs.db
```

---

###### Important Notes

* `.gitignore` affects **only untracked files**.
* If a file is **already tracked**, adding it to `.gitignore` will **not** stop Git from tracking it.

Example:

```bash
git add config.txt
git commit -m "Add config"
```

Later:

```text
config.txt
```

is added to `.gitignore`.

Git **still tracks** `config.txt`.

To stop tracking it:

```bash
git rm --cached config.txt
```

Then commit the change.

---

###### Create a `.gitignore` File

```bash
touch .gitignore
```

View it:

```bash
cat .gitignore
```

Edit it:

```bash
nano .gitignore
```

---

###### Summary

| Pattern        | Meaning                                               |
| -------------- | ----------------------------------------------------- |
| `*.o`          | Ignore all `.o` files                                 |
| `*.log`        | Ignore all log files                                  |
| `*~`           | Ignore backup files ending with `~`                   |
| `build/`       | Ignore the `build` directory                          |
| `/TODO`        | Ignore only the root `TODO` file                      |
| `doc/*.txt`    | Ignore `.txt` files directly inside `doc/`            |
| `doc/**/*.pdf` | Ignore all PDF files in `doc/` and its subdirectories |
| `!file.txt`    | Do **not** ignore `file.txt`                          |
| `# comment`    | Comment line                                          |
| `?`            | Match exactly one character                           |
| `*`            | Match zero or more characters                         |
| `[0-9]`        | Match any digit from 0 to 9                           |

---

###### Best Practice

Create a `.gitignore` file **before making your first commit**. This prevents unnecessary files (logs, build outputs, temporary files, IDE settings, etc.) from being accidentally committed to your repository.
##### viewing your staged and unstaged changes
Absolutely! This is one of the most confusing topics for beginners. Let's forget the Git book for a moment and learn it **from scratch** with a real-life example.

---

###### The Three Places Git Cares About

Whenever you work with Git, think about **three different places**.

```text
                  Git Repository
                 (Saved History)
                       ▲
                       │
                 git commit
                       │
                 Staging Area
                (Ready to Commit)
                       ▲
                       │
                  git add
                       │
               Working Directory
            (Where you edit files)
```

Think of them like this:

| Git Term          | Real-life Example                  |
| ----------------- | ---------------------------------- |
| Working Directory | Your notebook where you're writing |
| Staging Area      | Final draft ready to submit        |
| Repository        | Teacher's record book              |

---

###### Step 1: Create a Project

Suppose you have:

```text
project/
│
└── README.md
```

Contents:

```text
Hello World
```

Now save it.

```bash
git add README.md
git commit -m "Initial commit"
```

Current situation:

```text
Working Directory
Hello World

Staging Area
Hello World

Repository
Hello World
```

Everything is identical.

---

###### Step 2: Modify the File

Now change it.

```text
Hello Git
```

Current situation:

```text
Working Directory
Hello Git

Staging Area
Hello World

Repository
Hello World
```

Notice:

Only the **Working Directory** changed.

---

###### What does `git status` show?

Run

```bash
git status
```

Output

```text
modified: README.md
```

Git only says:

> "README.md changed."

It **doesn't show what changed**.

---

###### What does `git diff` show?

Run

```bash
git diff
```

Output

```diff
-Hello World
+Hello Git
```

Meaning

```diff
-Hello World
```

Old line removed.

```diff
+Hello Git
```

New line added.

---

###### What is `git diff` Comparing?

It compares

```text
Working Directory
↓

Staging Area
```

Current situation:

```text
Working Directory

Hello Git
```

versus

```text
Staging Area

Hello World
```

Difference:

```diff
-Hello World
+Hello Git
```

---

###### Step 3: Stage the File

Now run

```bash
git add README.md
```

Current situation

```text
Working Directory

Hello Git

Staging Area

Hello Git

Repository

Hello World
```

Now Working Directory and Staging Area are the same.

---

Run

```bash
git diff
```

Output

```text
(no output)
```

Why?

Because

```text
Working Directory

Hello Git
```

equals

```text
Staging Area

Hello Git
```

No difference.

---

###### Then What Does `git diff --staged` Show?

Run

```bash
git diff --staged
```

Git compares

```text
Repository
↓

Staging Area
```

Repository

```text
Hello World
```

Staging Area

```text
Hello Git
```

Difference

```diff
-Hello World
+Hello Git
```

This means

> These are the changes that will be committed.

---

###### Let's Draw Everything

Initially

```text
Repository

Hello World
        │
        │
Staging Area

Hello World
        │
        │
Working Directory

Hello World
```

Everything is identical.

---

Now edit the file.

```text
Repository

Hello World
        │
        │
Staging Area

Hello World
        │
        │
Working Directory

Hello Git
```

Run

```bash
git diff
```

Git compares

```text
Working Directory

Hello Git

↓

Staging Area

Hello World
```

Difference

```diff
-Hello World
+Hello Git
```

---

Now stage it.

```bash
git add README.md
```

Current situation

```text
Repository

Hello World
        │
        │
Staging Area

Hello Git
        │
        │
Working Directory

Hello Git
```

Now

```bash
git diff
```

shows nothing.

Because

```text
Working Directory

Hello Git
```

equals

```text
Staging Area

Hello Git
```

---

Run

```bash
git diff --staged
```

Git compares

```text
Repository

Hello World

↓

Staging Area

Hello Git
```

Difference

```diff
-Hello World
+Hello Git
```

---

###### Now Comes the Confusing Part

Suppose you do

```bash
git add README.md
```

Everything staged.

Then you edit again.

Now README becomes

```text
Hello Git Version 2
```

Current situation

```text
Repository

Hello World

Staging Area

Hello Git

Working Directory

Hello Git Version 2
```

Now there are THREE different versions.

---

Run

```bash
git status
```

Output

```text
Changes to be committed:

modified: README.md

Changes not staged for commit:

modified: README.md
```

Students usually ask:

> Why is the same file shown twice?

Because Git sees:

Version 1

Repository

```text
Hello World
```

Version 2

Staging Area

```text
Hello Git
```

Version 3

Working Directory

```text
Hello Git Version 2
```

Three different copies exist.

---

Run

```bash
git diff
```

Git compares

```text
Working Directory

Hello Git Version 2

↓

Staging Area

Hello Git
```

Difference

```diff
-Hello Git
+Hello Git Version 2
```

Only the newest change appears.

---

Run

```bash
git diff --staged
```

Git compares

```text
Repository

Hello World

↓

Staging Area

Hello Git
```

Difference

```diff
-Hello World
+Hello Git
```

These are the staged changes.

---

###### Why Doesn't `git diff` Show Everything?

Because

`git diff`

ONLY compares

```text
Working Directory

↓

Staging Area
```

It does **not** compare with the repository.

If everything is staged,

Working Directory

```text
Hello Git
```

equals

Staging Area

```text
Hello Git
```

No difference.

So Git prints nothing.

---

###### Complete Picture

```
                 git diff --staged
Repository  <------------------  Staging Area
      │                               ▲
      │                               │
      │                               │ git add
      ▼                               │
                git diff
Working Directory  --------------------
```

Remember:

* `git diff` → **Working Directory ↔ Staging Area**
* `git diff --staged` → **Staging Area ↔ Last Commit (Repository)**

---

###### Commands You Will Use Every Day

```bash
git status
```

**Question:** Which files changed?

---

```bash
git diff
```

**Question:** What changed that I **haven't staged** yet?

---

```bash
git diff --staged
```

(or `git diff --cached`)

**Question:** What changes **will be committed** if I commit now?

---

###### Easy Memory Trick

Imagine you're writing an assignment:

* 📝 **Working Directory** = Your notebook (you're still editing).
* 📂 **Staging Area** = The final draft you've put into a submission folder.
* 📚 **Repository** = The teacher's official copy.

Then:

* `git diff` = Compare your **notebook** with your **submission folder**.
* `git diff --staged` = Compare your **submission folder** with the **teacher's copy**.
* `git commit` = Submit the contents of the submission folder to the teacher.


##### commiting your changes
This is another **very important Git concept**. Instead of the book's explanation, let's learn it **from scratch** with simple examples.

---

# Committing Your Changes

## What is a Commit?

A **commit** is a **snapshot** of your project at a particular moment.

Think of it like:

* 📷 Taking a photo of your project.
* 💾 Saving a game.
* 📄 Submitting an assignment.

Once you commit, Git remembers exactly how your project looked at that time.

---

# The Three Git Areas

Before understanding `git commit`, remember these three places:

```text
Working Directory
        │
        │ git add
        ▼
Staging Area
        │
        │ git commit
        ▼
Git Repository
```

* **Working Directory** → Where you edit files.
* **Staging Area** → Files ready to be committed.
* **Repository** → Saved history of your project.

---

# Example

Suppose your project contains:

```text
project/
│
├── main.c
└── README.md
```

Contents of `README.md`:

```text
Hello World
```

---

## Step 1: Modify a File

You edit `README.md`:

```text
Hello Git
```

Now Git sees:

```bash
git status
```

Output:

```text
modified: README.md
```

The file is **modified** but **not staged**.

---

## Step 2: Stage the File

```bash
git add README.md
```

Now:

```bash
git status
```

Output:

```text
Changes to be committed:

modified: README.md
```

The file is now in the **Staging Area**.

---

## Step 3: Commit

Run:

```bash
git commit
```

Git opens your default text editor.

Example:

```text
# Please enter the commit message for your changes.
#
# Changes to be committed:
#
# modified: README.md
```

Everything beginning with `#` is a comment.

You simply type your message at the top:

```text
Update README with Git introduction
```

Save and close the editor.

Git creates the commit.

---

# Easier Way (Most Common)

Instead of opening an editor, you can write the message directly:

```bash
git commit -m "Update README with Git introduction"
```

This is the command you'll use most often.

---

# What Happens After Commit?

Suppose:

```text
README.md

Hello Git
```

When you commit:

```bash
git commit -m "Update README"
```

Git saves a snapshot.

```text
Commit 1

README.md

Hello Git
```

Later you edit again:

```text
Hello Git Version 2
```

Commit again:

```bash
git commit -m "Improve README"
```

Git creates another snapshot.

```text
Commit 2

README.md

Hello Git Version 2
```

Git now remembers **both versions**.

---

# Visual Timeline

```text
Commit 1
│
├── main.c
└── README.md

↓

Commit 2
│
├── main.c
└── README.md

↓

Commit 3
│
├── main.c
├── README.md
└── LICENSE
```

Each commit is a snapshot of the entire project.

---

###### Very Important Rule

Only **staged files** are committed.

Example:

Current situation:

```text
Working Directory

README.md  ← modified

main.c     ← modified

LICENSE    ← new
```

You stage only:

```bash
git add README.md
```

Now commit:

```bash
git commit -m "Update README"
```

What gets committed?

✅ `README.md`

What does NOT get committed?

❌ `main.c`

❌ `LICENSE`

They remain in your working directory.

---

###### Example

Suppose

```text
README.md
main.c
```

Both modified.

Run

```bash
git add README.md
```

Then

```bash
git commit -m "Update README"
```

Repository becomes

```text
Repository

README.md  ← Updated

main.c     ← Old Version
```

Because `main.c` was never staged.

---

###### Why Use Commit Messages?

Every commit should explain **what changed**.

Good examples:

```text
Add login feature

Fix UART communication bug

Update README

Remove unused files

Add OLED driver

Improve error handling
```

Bad examples:

```text
update

changes

test

123

abc
```

A good commit message helps you and your teammates understand the project history.

---

###### Commit Output

After committing, Git prints something like:

```text
[main 463dc4f] Update README
2 files changed, 10 insertions(+), 3 deletions(-)
```

Let's understand it.

```text
[main
```

You committed on the **main branch**.

---

```text
463dc4f
```

This is the **commit ID** (a shortened SHA-1 hash).

Every commit has a unique identifier.

Example:

```text
463dc4f

89ab12e

c45f789
```

You can use these IDs later to:

* View a commit
* Compare commits
* Restore an older version

---

```text
2 files changed
```

Git modified two files.

---

```text
10 insertions(+)
```

Ten new lines were added.

---

```text
3 deletions(-)
```

Three lines were removed.

---

###### What If I Forget to Stage a File?

Example:

```text
README.md
main.c
```

Both modified.

You run:

```bash
git add README.md
```

Then:

```bash
git commit -m "Update README"
```

Result:

```text
README.md

Committed
```

```text
main.c

Still Modified
```

Git **does not lose** the changes.

They remain in your working directory.

Later you can run:

```bash
git add main.c
git commit -m "Update main"
```

---

###### Complete Workflow

```text
Edit File
     │
     ▼
Working Directory
     │
git status
     │
     ▼
git add
     │
     ▼
Staging Area
     │
git diff --staged
     │
     ▼
git commit -m "Meaningful message"
     │
     ▼
Repository
```

---

###### Real-Life Analogy

Imagine you're writing a school assignment.

* ✍️ **Working Directory** → You're writing in your notebook.

* 📂 **Staging Area** → You've placed the final pages in a submission folder.

* 🧑‍🏫 **Repository** → The teacher has accepted and recorded your submission.

* `git add` = Put selected pages into the submission folder.

* `git commit` = Hand the submission folder to the teacher.

* The teacher records **only** the pages in the folder—not the unfinished pages still on your desk.

---

###### Summary

| Command                   | Purpose                                      |
| ------------------------- | -------------------------------------------- |
| `git add <file>`          | Stage a file for the next commit             |
| `git commit`              | Open an editor to write a commit message     |
| `git commit -m "message"` | Commit using an inline message (most common) |
| `git status`              | Check what is staged and what is not         |
| `git diff --staged`       | Review exactly what will be committed        |

---

###### Key Points to Remember

* A **commit** is a snapshot of your project.
* Only **staged files** are included in a commit.
* Unstaged changes stay in your working directory.
* Every commit has a unique **commit ID (SHA-1 hash)**.
* Write clear, meaningful commit messages.
* The most commonly used command is:

```bash
git commit -m "Describe what changed"
```

This creates a new snapshot in your Git history that you can review, compare, or restore later.

###### Skipping the Staging Area
This topic confuses many beginners because it introduces a **shortcut**. Let's understand it from scratch.

---

###### Skipping the Staging Area (`git commit -a`)

Normally, Git follows this workflow:

```text
Working Directory
        │
        │ git add
        ▼
Staging Area
        │
        │ git commit
        ▼
Repository
```

So normally you do:

```bash
git add file
git commit -m "message"
```

---

###### Why was the Staging Area created?

Imagine you changed **three files**.

```text
README.md
main.c
notes.md
```

But today you only want to save changes to:

```text
README.md
```

So you stage only that file.

```bash
git add README.md
```

Then commit.

```bash
git commit -m "Update README"
```

Only `README.md` goes into the commit.

This is why the staging area exists.

---

###### Sometimes This Is Too Much Work

Suppose you modified only **one tracked file**.

```
README.md
```

Normally you would type:

```bash
git add README.md
git commit -m "Update README"
```

Git says,

> "Since this file is already tracked, I can save you one step."

That's where `-a` comes in.

---

###### What Does `-a` Mean?

Command:

```bash
git commit -a -m "Update README"
```

Git automatically performs:

```bash
git add README.md
git commit -m "Update README"
```

for **tracked files only**.

---

###### Example

Suppose your repository contains

```text
project/
│
├── README.md
└── main.c
```

Both files have already been committed once.

Now you edit:

```text
README.md
```

Run

```bash
git status
```

Output

```text
modified: README.md
```

Normally:

```bash
git add README.md
git commit -m "Update README"
```

Shortcut:

```bash
git commit -a -m "Update README"
```

Git automatically stages `README.md` and commits it.

---

###### What Happens Internally?

Without `-a`

```text
Working Directory

README Modified
        │
git add
        ▼
Staging Area

README Modified
        │
git commit
        ▼
Repository
```

With `-a`

```text
Working Directory

README Modified
        │
git commit -a
        ▼
Git automatically stages
        │
Automatically commits
        ▼
Repository
```

Git combines the two steps.

---

###### Very Important

`git commit -a` works **ONLY for tracked files**.

It **does NOT add new files**.

---

###### Example

Project

```text
project/
│
├── README.md
└── main.c
```

Both are already tracked.

Create a new file

```text
LICENSE
```

Now

```bash
git status
```

Output

```text
modified: README.md

Untracked files:

LICENSE
```

Run

```bash
git commit -a -m "Update project"
```

What gets committed?

✅ README.md

What does NOT get committed?

❌ LICENSE

Because Git has never seen `LICENSE` before.

---

###### Why?

Git doesn't want to accidentally include files you didn't intend to track.

Imagine you accidentally create:

```text
passwords.txt
```

or

```text
movie.mp4
```

Git will **not** automatically add them.

You must explicitly say:

```bash
git add passwords.txt
```

Only then can Git commit it.

---

###### Example

Suppose:

```text
README.md ← Modified

main.c ← Modified

notes.md ← New File
```

Run

```bash
git commit -a -m "Update project"
```

Result

```text
README.md ✓

main.c ✓

notes.md ✗
```

`notes.md` is still untracked.

---

###### To Commit New Files

You must first do

```bash
git add notes.md
```

Then

```bash
git commit -m "Add notes"
```

---

###### `git status` Before

```text
modified: README.md

modified: main.c

Untracked files:

notes.md
```

---

Run

```bash
git commit -a -m "Update files"
```

After commit

```text
Untracked files:

notes.md
```

Notice

`notes.md` is still there.

---

###### Real-Life Analogy

Imagine you're submitting assignments.

###### Without `-a`

Teacher says:

1. Put the papers into the submission folder.
2. Hand me the folder.

```text
Notebook

↓

Submission Folder

↓

Teacher
```

---

###### With `-a`

Teacher says:

"If you've only edited assignments I've already seen, I'll automatically collect them before recording them."

But if you wrote a **brand-new assignment**, the teacher doesn't know about it.

You must hand it over separately.

That's exactly how `git commit -a` works.

---

###### Difference Between `git commit` and `git commit -a`

###### Normal Way

```bash
git add README.md
git commit -m "Update README"
```

Works for:

* Existing files
* New files

---

###### Shortcut

```bash
git commit -a -m "Update README"
```

Works only for:

* Existing tracked files

Not for:

* New files

---

###### Comparison Table

| Command                  | Stages tracked files automatically? | Adds new files? |
| ------------------------ | ----------------------------------- | --------------- |
| `git commit -m "msg"`    | ❌ No                                | ❌ No            |
| `git add .`              | ✅ Yes                               | ✅ Yes           |
| `git commit -a -m "msg"` | ✅ Yes                               | ❌ No            |

---

###### When Should You Use `git commit -a`?

✅ Good when:

* You only modified files that Git is already tracking.
* You want a quick commit.

❌ Avoid it when:

* You created new files.
* You want to commit only some of your changes (the staging area gives you that control).

---

###### Summary

* `git commit -a -m "message"` is a shortcut.
* It automatically stages **all modified tracked files**.
* It **does not** stage **new untracked files**.
* If you create a new file, you **must** use `git add` first.
* The staging area is still useful when you want to carefully choose what goes into a commit.

###### Memory Trick

Think of `-a` as:

> **`-a` = Automatically stage all tracked files before committing.**

It does **not** mean "add absolutely everything." New files still require an explicit `git add`.

##### Removing and Renaming Files in Git
This is one of the most confusing chapters for beginners because it talks about **three different things**:

1. Deleting a file (`git rm`)
2. Stopping Git from tracking a file (`git rm --cached`)
3. Renaming a file (`git mv`)

Let's learn them **from scratch**, as if you've never used Git before.

---

###### First, Remember the Three Git Areas

Every Git command works with these three places:

```text
            Git Repository
           (Commit History)
                  ▲
                  │
            git commit
                  │
            Staging Area
                  ▲
                  │
             git add
                  │
         Working Directory
```

Suppose your project looks like this:

```text
project/
│
├── main.c
├── README.md
└── notes.txt
```

All three files are already committed.

---

###### Case 1: Delete a File Normally

Suppose you don't need

```text
notes.txt
```

Delete it:

```bash
rm notes.txt
```

Now your folder becomes

```text
project/
│
├── main.c
└── README.md
```

But Git still remembers

```text
notes.txt
```

because it exists in the last commit.

---

Run

```bash
git status
```

Output

```text
Changes not staged for commit:

deleted: notes.txt
```

Student question:

> I already deleted it. Why is Git still showing it?

Because **deleting a file from your computer is NOT the same as telling Git to remove it from version control.**

Git says:

> "I noticed the file disappeared. Is this intentional?"

---

###### Visual Explanation

Before deletion

```text
Repository

notes.txt

↓

Staging Area

notes.txt

↓

Working Directory

notes.txt
```

After

```bash
rm notes.txt
```

becomes

```text
Repository

notes.txt

↓

Staging Area

notes.txt

↓

Working Directory

Deleted
```

Only the working directory changed.

---

###### Stage the Deletion

Now tell Git:

> Yes, I really want to remove it.

Run

```bash
git rm notes.txt
```

Now

```bash
git status
```

shows

```text
Changes to be committed:

deleted: notes.txt
```

Current situation

```text
Repository

notes.txt

↓

Staging Area

Deleted

↓

Working Directory

Deleted
```

Now Git understands.

---

Commit

```bash
git commit -m "Remove notes"
```

Repository becomes

```text
Repository

Deleted

↓

Staging Area

Deleted

↓

Working Directory

Deleted
```

The file is completely gone.

---

###### Easier Way

Instead of

```bash
rm notes.txt
git add notes.txt
```

or

```bash
rm notes.txt
git rm notes.txt
```

just do

```bash
git rm notes.txt
```

Git performs:

* Delete the file.
* Stage the deletion.

in one command.

---

###### Case 2: What is `git rm -f`?

Suppose

```text
README.md
```

contains

```text
Hello World
```

You change it to

```text
Hello Git
```

but haven't committed it yet.

Git thinks

> These changes may be important.

If you type

```bash
git rm README.md
```

Git may refuse.

Why?

Because deleting it would destroy changes that aren't saved in a commit.

So Git protects you.

---

If you are absolutely sure

```bash
git rm -f README.md
```

The `-f` means

**Force**

Git deletes the file even though it contains uncommitted work.

---

###### Why is this safety feature useful?

Imagine you spent **three hours** writing code.

You accidentally type

```bash
git rm main.c
```

Without protection,

everything would disappear.

Git stops you.

---

###### Case 3: What is `git rm --cached`?

This is where most beginners get confused.

Suppose your project is

```text
project/

main.c
README.md
app.log
```

You accidentally committed

```text
app.log
```

Later you realize

> I don't want Git to track log files.

You add

```text
*.log
```

to

```text
.gitignore
```

But Git still tracks

```text
app.log
```

Why?

Because

`.gitignore`

only ignores **new untracked files**.

Git already knows about

```text
app.log
```

---

So you run

```bash
git rm --cached app.log
```

Notice

The file is **NOT deleted**.

Current folder

```text
project/

main.c
README.md
app.log
```

The file is still there.

Git simply forgets it.

---

Visual

Before

```text
Repository

app.log

↓

Working Directory

app.log
```

After

```bash
git rm --cached app.log
```

becomes

```text
Repository

Deleted

↓

Working Directory

app.log
```

The file stays on your computer.

Git stops tracking it.

---

This is mainly used together with

```text
.gitignore
```

---

##### Case 4: Remove Multiple Files

Suppose

```text
log/

error.log

debug.log

server.log
```

Remove all log files

```bash
git rm log/*.log
```

Result

```text
log/
```

becomes empty.

---

##### Remove Backup Files

```bash
git rm *~
```

Deletes

```text
main.c~

README.md~

notes.txt~
```

Many editors create these temporary backup files.

---

##### Now Let's Learn `git mv`

Suppose

```text
README.md
```

should become

```text
README
```

Run

```bash
git mv README.md README
```

Git status

```text
renamed:

README.md → README
```

Commit

```bash
git commit -m "Rename README"
```

Done.

---

##### What Happens Internally?

Git actually performs

```bash
mv README.md README
git rm README.md
git add README
```

So

```bash
git mv README.md README
```

is simply a shortcut.

---

##### Real-Life Example

Imagine your school notebook.

##### `git rm`

Throw away one page.

```
Notebook

↓

Trash
```

---

##### `git rm --cached`

Teacher removes that page from the school record,

but you still keep it in your bag.

```
School Record

Removed

↓

Your Bag

Page Still Exists
```

---

##### `git mv`

Rename

```
Math Notes
```

to

```
Mathematics Notes
```

The notebook is the same.

Only the label changes.

---

##### Comparison Table

| Command                | Deletes from Computer | Stops Git Tracking                 | Common Use                                          |
| ---------------------- | --------------------- | ---------------------------------- | --------------------------------------------------- |
| `rm file`              | ✅ Yes                 | ❌ Not yet (until staged/committed) | Normal OS delete                                    |
| `git rm file`          | ✅ Yes                 | ✅ Yes (after commit)               | Delete a tracked file from the project              |
| `git rm -f file`       | ✅ Yes                 | ✅ Yes                              | Force delete even if there are uncommitted changes  |
| `git rm --cached file` | ❌ No                  | ✅ Yes                              | Keep the file locally but stop Git from tracking it |
| `git mv old new`       | ❌ No                  | ❌ No (it's still tracked)          | Rename a tracked file                               |

##### Easy Memory Trick

Think of the commands like this:

* 🗑️ **`git rm file`** = "Delete this file from both my project folder and Git (once I commit)."
* 📦 **`git rm --cached file`** = "Keep the file on my computer, but remove it from Git's list of tracked files."
* ✏️ **`git mv old new`** = "Rename the file and let Git know about the rename."

##### The most important difference

```
git rm
```

➡️ **File disappears from your computer.**

```
git rm --cached
```

➡️ **File stays on your computer but disappears from Git tracking.**

This distinction is the key idea to remember when working with `.gitignore`, log files, build artifacts, and other generated files.
##### viewing the commit history
Absolutely! This is one of the **most important Git topics** because **`git log` is the command you'll use every day** to understand the history of a project.

Forget the Git book for a while. Let's learn it **from scratch** with a real-life example, just like I would teach a beginner in a classroom.

---

###### Chapter: Viewing the Commit History (`git log`)

---

###### Imagine This Scenario

Suppose you are writing a book.

On Day 1, you write the first chapter.

On Day 2, you add the second chapter.

On Day 3, you fix spelling mistakes.

On Day 4, you add pictures.

Every day you save a copy.

```
Day 1 → Save
Day 2 → Save
Day 3 → Save
Day 4 → Save
```

Now suppose someone asks:

> What changes did you make yesterday?

Or

> When did you add Chapter 2?

Or

> Who made this change?

You look at your saved copies.

Git does exactly the same thing.

Each saved copy is called a **Commit**.

To view all saved copies, Git provides:

```bash
git log
```

---

###### What is `git log`?

`git log` displays the **history of all commits** in a repository.

Think of it as

```
Project Diary
```

Every commit is one diary entry.

---

###### Example Project

Suppose your project history is:

```
Commit 4
Added Login Page

↓

Commit 3
Fixed Login Bug

↓

Commit 2
Added Login Feature

↓

Commit 1
Initial Project
```

When you run

```bash
git log
```

Git displays this history.

---

###### Basic Command

```bash
git log
```

Example output

```text
commit 91b7e8fd25d...

Author: Chandu Bollu

Date: Thu Jul 16 10:25:14

Added Login Page

commit 8f75de92c...

Author: Chandu Bollu

Date: Thu Jul 15

Fixed Login Bug

commit 42abf765a...

Author: Chandu Bollu

Date: Thu Jul 14

Initial Project
```

---

###### Understanding Every Line

###### Line 1

```text
commit 91b7e8fd25d...
```

This is called the

###### Commit Hash

Every commit has a unique ID.

Think of it like

* Aadhaar Number
* Passport Number
* Student Roll Number

No two commits have the same hash.

Example

```
Commit A

91b7e8fd25d...

Commit B

42abf765a...
```

Different commits

Different IDs

---

###### Author

```
Author:
```

The person who originally wrote the code.

Example

```
Author

Chandu Bollu
```

---

###### Date

```
Date:
```

When the commit was created.

Example

```
Thu Jul 16
```

---

###### Commit Message

```
Added Login Page
```

This explains

> What changes were made.

---

###### Why Does Git Show the Newest Commit First?

Suppose you made these commits.

```
1

Initial Project

↓

2

Added Login

↓

3

Bug Fix

↓

4

Logout
```

Git shows

```
4

↓

3

↓

2

↓

1
```

Newest comes first.

This is called

```
Reverse Chronological Order
```

Exactly like WhatsApp chats.

Newest messages appear first.

---

###### Practical Example

Let's create a small repository.

```
mkdir demo
cd demo

git init
```

Create a file

```
README.md

Hello
```

Commit

```bash
git add README.md
git commit -m "Initial commit"
```

Modify

```
Hello Git
```

Commit again

```bash
git add README.md
git commit -m "Updated README"
```

Now

```bash
git log
```

shows

```
Updated README

↓

Initial commit
```

---

###### `git log -2`

Suppose your project has

```
Commit 10

↓

Commit 9

↓

Commit 8

↓

Commit 7

↓

Commit 6
```

You only want the latest two.

Run

```bash
git log -2
```

Output

```
Commit 10

Commit 9
```

Very useful.

---

###### `git log -p`

This is one of the most useful options.

Imagine

Old file

```text
Hello World
```

New file

```text
Hello Git
```

Run

```bash
git log -p
```

Git shows

```diff
-Hello World
+Hello Git
```

Meaning

```
-
```

Old line removed.

```
+
```

New line added.

---

###### Real Example

Old

```c
int speed = 10;
```

New

```c
int speed = 20;
```

Git shows

```diff
-int speed = 10;

+int speed = 20;
```

Now you know exactly what changed.

---

###### `git log -p -2`

Suppose

```
Commit 10

Commit 9

Commit 8
```

Run

```bash
git log -p -2
```

Git shows

```
Commit 10

↓

Actual Code Changes

↓

Commit 9

↓

Actual Code Changes
```

Only two commits

Plus

Their code differences.

---

###### `git log --stat`

Sometimes you don't want every changed line.

You only want statistics.

Run

```bash
git log --stat
```

Example

```
README.md

2 +-

main.c

15 +++++++++++----
```

At bottom

```
2 files changed

15 insertions

4 deletions
```

Meaning

```
README.md

2 lines changed
```

```
main.c

15 lines added

4 removed
```

This is much shorter than `-p`.

---

###### Difference Between `-p` and `--stat`

Suppose

Old

```c
int a = 10;
```

New

```c
int a = 20;
```

###### `git log -p`

Shows

```diff
-int a = 10;

+int a = 20;
```

Exact code.

---

###### `git log --stat`

Shows only

```
main.c

1 insertion

1 deletion
```

No code.

---

###### `git log --pretty=oneline`

Normal

```
Commit

Author

Date

Message
```

Lots of information.

Instead

```bash
git log --pretty=oneline
```

Output

```
91b7e8fd Updated README

8f75de92 Initial Commit
```

Everything on one line.

Developers use this very often.

---

###### Easier Shortcut

Instead of

```bash
git log --pretty=oneline
```

Git provides

```bash
git log --oneline
```

Exactly the same idea, but with the abbreviated commit hash.

Example:

```
91b7e8f Updated README
8f75de9 Initial Commit
```

---

###### `git log --pretty=format`

Sometimes you want to design your own output.

Example

```bash
git log --pretty=format:"%h - %an - %ar : %s"
```

Output

```
91b7e8f - Chandu - 2 hours ago : Updated README

8f75de9 - Chandu - Yesterday : Initial Commit
```

Let's understand each placeholder.

---

###### `%h`

Short Hash

```
91b7e8f
```

---

###### `%H`

Complete Hash

```
91b7e8fd25d78ab34265...
```

---

###### `%an`

Author Name

```
Chandu Bollu
```

---

###### `%ae`

Author Email

```
chandubollu96@gmail.com
```

---

###### `%ad`

Author Date

```
Thu Jul 16
```

---

###### `%ar`

Relative Date

Instead of

```
Thu Jul 16
```

Git prints

```
2 hours ago
```

---

####### `%cn`

Committer Name

Usually same as author.

---

####### `%ce`

Committer Email

---

####### `%cd`

Commit Date

---

####### `%cr`

Relative Commit Date

Example

```
5 minutes ago
```

---

####### `%s`

Subject

The commit message.

Example

```
Updated README
```

---

###### Author vs Committer

This is confusing until you see a real example.

Suppose you contribute to Linux.

You write a bug fix and send it to the maintainer.

```
You

↓

Linux Maintainer

↓

Linux Repository
```

The code was

Written by

```
You
```

Applied by

```
Maintainer
```

So

```
Author

You
```

```
Committer

Maintainer
```

Both get credit.

If you are working alone, **Author** and **Committer** are usually the same person.

---
####### `git log --graph`

Imagine branches.

```
A

↓

B

↓

C
```

Create another branch

```
A

↓

B

 \

  D

   \

    E
```

Merge

```
A

↓

B

|\

| D

| E

|/

C
```

Run

```bash
git log --graph --oneline
```

Output

```
* Merge

|\

| *

| *

|/

*
```

Git draws the branch history using ASCII characters.

You will use this more when you learn **Git branching and merging**.

---

###### Commands You Should Remember

| Command                         | Purpose                          | When to Use            |
| ------------------------------- | -------------------------------- | ---------------------- |
| `git log`                       | Show complete commit history     | View all commits       |
| `git log -2`                    | Show the last 2 commits          | View recent work       |
| `git log -p`                    | Show code changes in each commit | Review code            |
| `git log --stat`                | Show summary of file changes     | Quick overview         |
| `git log --oneline`             | Show one commit per line         | Compact history        |
| `git log --graph --oneline`     | Show branch graph                | Understand branches    |
| `git log --pretty=format:"..."` | Customize log output             | Create your own format |

---

###### Complete Git Log Workflow

```
Write Code
     │
     ▼
git add
     │
     ▼
git commit
     │
     ▼
Repository History
     │
     ▼
git log
     │
     ├── git log --oneline
     ├── git log -p
     ├── git log --stat
     ├── git log -2
     ├── git log --graph
     └── git log --pretty=format
```

###### Which commands should you actually memorize?

If you're just starting Git, these five commands are enough:

```bash
git log
git log --oneline
git log -2
git log -p
git log --stat
```

Once you're comfortable with those, learn:

```bash
git log --graph --oneline
git log --pretty=format:"%h %an %ar %s"
```

These cover almost everything you'll use in day-to-day Git work.

##### limiting log output
Excellent! This is the **last major topic about `git log`**, and it's actually much easier than it looks.

The previous chapter taught you **how to display commit history**.

This chapter teaches you **how to filter commit history**.

Think of it like searching for a contact in your phone.

Without filters:

```text
Contacts

Aarav
Alex
Bob
Chandu
David
John
...
1000 contacts
```

If you only want contacts starting with **C**, you search.

Git does the same thing with commits.

---

# Limiting Log Output

## What does "Limiting" mean?

Normally,

```bash
git log
```

shows **every commit**.

Example

```text
Commit 20

↓

Commit 19

↓

Commit 18

↓

Commit 17

↓

...

↓

Commit 1
```

Sometimes you don't want to see everything.

You only want

* last 5 commits
* commits made yesterday
* commits by Chandu
* commits containing "bug"
* commits affecting `main.c`

That's exactly what **limiting options** do.

---

# 1. Show Last N Commits

Command

```bash
git log -3
```

Output

```text
Commit 20

Commit 19

Commit 18
```

Only three commits.

Similarly,

```bash
git log -10
```

shows

```text
Last 10 commits
```

Think of it like

```text
Instagram Feed

Show only last 5 posts
```

---

# 2. `--since`

Suppose today is

```text
16 July
```

Your commits

```text
16 July

↓

15 July

↓

14 July

↓

10 July

↓

5 July
```

Run

```bash
git log --since="7 days ago"
```

Git shows

```text
16 July

15 July

14 July

10 July
```

It ignores

```text
5 July
```

because it's older than 7 days.

---

## Another Example

```bash
git log --since="2 weeks ago"
```

Shows commits made

```text
Last 14 days
```

---

## Specific Date

Instead of

```text
2 weeks ago
```

you can write

```bash
git log --since="2026-07-01"
```

Meaning

> Show commits after July 1.

---

# 3. `--until`

Opposite of `--since`.

Suppose

```text
16 Jul

15 Jul

14 Jul

10 Jul

5 Jul
```

Run

```bash
git log --until="2026-07-12"
```

Git shows

```text
10 Jul

5 Jul
```

Everything before July 12.

---

# 4. `--since` + `--until`

Suppose

```text
1 Jul

5 Jul

10 Jul

15 Jul

20 Jul
```

Run

```bash
git log --since="2026-07-05" --until="2026-07-15"
```

Output

```text
5 Jul

10 Jul

15 Jul
```

Only commits between those dates.

---

# 5. `--author`

Suppose three people work on the project.

```text
Commit 10

Chandu

↓

Commit 9

Rahul

↓

Commit 8

Chandu

↓

Commit 7

Akhil
```

Run

```bash
git log --author="Chandu"
```

Output

```text
Commit 10

Commit 8
```

Only Chandu's commits.

---

# 6. `--committer`

Remember

Author

↓

Original writer

Committer

↓

Person who actually committed it

Most beginners working alone see

```text
Author

=

Committer
```

because they're the same person.

In large projects they can differ.

---

# 7. `--grep`

Suppose commit messages

```text
Fixed UART bug

Added OLED driver

Fixed WiFi bug

Added MQTT

Updated README
```

Run

```bash
git log --grep="bug"
```

Output

```text
Fixed UART bug

Fixed WiFi bug
```

Git searches inside commit messages.

Very useful.

---

# Example

Suppose commits

```text
Added Login

Fixed Login Bug

Fixed UART

Added LCD

Fixed OLED
```

Run

```bash
git log --grep="Fixed"
```

Git shows

```text
Fixed Login Bug

Fixed UART

Fixed OLED
```

---

# 8. `-S`

This is called

```text
Pickaxe
```

Very useful.

Suppose

Original code

```c
uart_init();
```

Later someone removes

```c
uart_init();
```

Run

```bash
git log -S "uart_init"
```

Git searches every commit.

It tells you

```text
Commit 15

Added uart_init()

↓

Commit 28

Removed uart_init()
```

Very useful when debugging.

---

Example

Suppose

```c
temperature_read();
```

disappears.

You don't know when.

Run

```bash
git log -S "temperature_read"
```

Git finds the commit.

---

# 9. Search by File

Suppose

Project

```text
project/

main.c

wifi.c

oled.c

README.md
```

Run

```bash
git log -- main.c
```

Git ignores every other file.

Shows only commits that changed

```text
main.c
```

Example

```text
Commit 20

Modified main.c

↓

Commit 15

Fixed main.c

↓

Commit 7

Created main.c
```

Nothing else.

---

Notice

```bash
git log -- main.c
```

There are

```text
--
```

before

```text
main.c
```

Why?

Because Git must know

```text
Everything before --

↓

Options

Everything after --

↓

Files/Folders
```

Example

```bash
git log --since="2 weeks ago" -- main.c
```

Git understands

```text
Option

↓

Since

↓

main.c
```

---

# 10. `--no-merges`

You'll learn merging later.

Suppose history

```text
Commit A

↓

Commit B

↓

Merge

↓

Commit C

↓

Merge

↓

Commit D
```

Run

```bash
git log
```

Git shows everything.

Run

```bash
git log --no-merges
```

Git hides

```text
Merge
```

Only normal commits remain.

Much cleaner.

---

# Combining Filters

Suppose

You want

* only Chandu's commits
* last week
* containing "UART"

Run

```bash
git log \
--author="Chandu" \
--since="1 week ago" \
--grep="UART"
```

Git checks

```text
Author

↓

Date

↓

Message
```

Only matching commits appear.

---

# Real-Life Example

Imagine your WhatsApp messages.

You can search

```text
Friend

↓

Date

↓

Keyword
```

Git does exactly the same thing.

Instead of messages,

it searches commits.

---

# Complete Summary

| Command                         | Purpose                                                 | Example                   |
| ------------------------------- | ------------------------------------------------------- | ------------------------- |
| `git log -5`                    | Show last 5 commits                                     | `git log -5`              |
| `git log --since="2 weeks ago"` | Show commits after a date                               | Last 2 weeks              |
| `git log --until="2026-07-01"`  | Show commits before a date                              | Before July 1             |
| `git log --author="Chandu"`     | Show commits by an author                               | Only Chandu's commits     |
| `git log --committer="Rahul"`   | Show commits by the committer                           | Only Rahul's commits      |
| `git log --grep="bug"`          | Search commit messages                                  | Messages containing "bug" |
| `git log -S "uart_init"`        | Find commits that added or removed a string in the code | Search code history       |
| `git log -- main.c`             | Show commits affecting a specific file                  | Only `main.c` history     |
| `git log --no-merges`           | Hide merge commits                                      | Cleaner history           |

---

# Commands Every Beginner Should Learn

Start with these:

```bash
git log -5
git log --since="1 week ago"
git log --author="Your Name"
git log --grep="bug"
git log -- main.c
```

After you become comfortable with Git, add these to your toolkit:

```bash
git log -S "function_name"
git log --no-merges
git log --since="2026-07-01" --until="2026-07-31"
```

These filtering options become especially powerful in large projects with thousands of commits, where scrolling through the entire history isn't practical.


###### Undoing Things in Git

###### Why Do We Need Undo?

Imagine you're writing an assignment.

Sometimes you make mistakes:

* You submitted too early.
* You forgot to include one page.
* You wrote the wrong title.
* You made a spelling mistake.

Git allows you to fix many of these mistakes.

---

###### First, Remember Git's Three Areas

Everything in Git happens in these three places.

```text
              Git Repository
             (Saved Commits)
                    ▲
                    │
              git commit
                    │
              Staging Area
                    ▲
                    │
                git add
                    │
            Working Directory
```

Understanding these three areas makes **undoing changes** much easier.

---

###### The Situation

Suppose you create a project.

```
project/
│
├── main.c
└── README.md
```

Contents of `README.md`

```text
Hello World
```

Commit it.

```bash
git add README.md
git commit -m "Initial commit"
```

Repository

```text
Commit 1

README.md

Hello World
```

---

###### Oops! You Forgot Something

After committing, you realize

> I forgot to add

```text
LICENSE
```

or

```text
notes.md
```

What now?

Should you create another commit?

You **can**, but then history becomes

```text
Commit 1

Initial commit

↓

Commit 2

Forgot LICENSE
```

Looks messy.

Instead,

Git provides

```bash
git commit --amend
```

---

###### What is `git commit --amend`?

Think of it as

> "Replace my last commit with a better version."

It **does not create another commit**.

It **replaces** the previous one.

---

###### Example 1

Suppose

You commit

```bash
git add README.md
git commit -m "Initial commit"
```

Repository

```text
Commit 1

README.md
```

Later you realize

```
LICENSE
```

should also have been included.

---

Stage it

```bash
git add LICENSE
```

Then run

```bash
git commit --amend
```

Git opens the editor.

Current message

```text
Initial commit
```

You may keep it

or

change it to

```text
Initial project
```

Save and exit.

---

Repository now becomes

```text
Commit 1

README.md

LICENSE
```

Notice

There is still

**ONE COMMIT**

not two.

---

###### Visual Explanation

Before

```text
Repository

Commit 1

README.md
```

After

```bash
git add LICENSE

git commit --amend
```

Repository

```text
Commit 1

README.md

LICENSE
```

Git replaced the old commit.

---

###### Example 2

Suppose you only made a typo.

You wrote

```bash
git commit -m "Initail commit"
```

Oops.

Should be

```text
Initial commit
```

Run

```bash
git commit --amend
```

Editor opens

```text
Initail commit
```

Correct it

```text
Initial commit
```

Save.

Now history becomes

```text
Initial commit
```

The typo disappears.

---

###### What if I Didn't Change Any Files?

Suppose

```bash
git commit -m "Initial commit"
```

Immediately afterwards

```bash
git commit --amend
```

without changing anything.

What happens?

Git simply lets you edit

```text
Commit Message
```

The files remain exactly the same.

---

###### Example

Old

```text
Commit Message

Added Login
```

Run

```bash
git commit --amend
```

Change

```text
Added Login Feature
```

Done.

Files stay unchanged.

Only the message changes.

---

###### What Happens Internally?

Many beginners think

```text
Commit 1

↓

Commit 2
```

Wrong.

Actually

Git does this.

Old commit

```text
Commit A
```

↓

Create

```text
Commit B
```

↓

Delete

```text
Commit A
```

So the old commit disappears from normal history.

---

Visual

Before

```text
Repository

Commit A
```

After amend

```text
Repository

Commit B
```

Commit A is no longer part of the visible history.

---

###### Why Does the Commit Hash Change?

Every commit has

```
Commit Hash
```

Suppose

Original

```text
91ab34f
```

After

```bash
git commit --amend
```

New hash

```text
53df128
```

Why?

Because Git created

a completely new commit.

Every new commit gets a new ID.

---

###### Example

Original

```text
Commit

Hash

91ab34f

Message

Initial commit
```

After amend

```text
Commit

Hash

53df128

Message

Initial project
```

Different commit.

Different hash.

---

###### Real-Life Analogy

Imagine you submitted a school assignment.

Teacher hasn't checked it yet.

You say

> "Sir, I forgot one page."

Teacher returns it.

You insert the page.

Teacher replaces the old submission with the new one.

There aren't

```
Assignment 1

Assignment 2
```

There is only

```
Correct Assignment
```

That's exactly

```bash
git commit --amend
```

---

###### Another Example

Suppose

Project

```text
main.c

README.md
```

Commit

```bash
git add main.c
git commit -m "Add main"
```

Oops

Forgot

```text
README.md
```

Run

```bash
git add README.md
git commit --amend
```

Final repository

```text
Commit

main.c

README.md
```

History

```text
Only one commit
```

---

###### Why Use `--amend`?

Without amend

```text
Commit 1

Initial commit

↓

Commit 2

Forgot README

↓

Commit 3

Forgot LICENSE

↓

Commit 4

Fixed typo
```

Messy history.

---

With amend

```text
Commit 1

Perfect Initial Commit
```

Clean history.

---

###### When Should You Use It?

✅ Good

* Forgot a file.
* Commit message typo.
* Forgot small changes.
* Need to improve the last commit.

❌ Avoid

If you've **already pushed** the commit to a shared remote repository and other people may have based work on it. Amending changes the commit ID, so rewriting shared history can cause problems for collaborators. (If it's only in your local repository and hasn't been shared yet, it's generally fine.)

---

###### Commands

###### Change only commit message

```bash
git commit --amend
```

Git opens the editor.

---

###### Forgot a file

```bash
git add forgotten_file
git commit --amend
```

Git replaces the last commit with a new one that includes the forgotten file.

---

###### Change message without opening the editor

```bash
git commit --amend -m "New commit message"
```

This updates the last commit and sets the new message directly.

---

###### Visual Timeline

Normal commits

```text
Commit 1

↓

Commit 2

↓

Commit 3
```

Using amend

```text
Commit 1

↓

Commit 2

↓

Replace Commit 3

↓

New Commit 3
```

Old Commit 3 disappears from the visible history.

---

###### Summary

| Situation                               | Command                                                          |
| --------------------------------------- | ---------------------------------------------------------------- |
| Fix the last commit                     | `git commit --amend`                                             |
| Add a forgotten file to the last commit | `git add file` → `git commit --amend`                            |
| Change only the last commit message     | `git commit --amend` (or `git commit --amend -m "New message"`)  |
| Creates a new commit?                   | ❌ No (it replaces the last commit in history with a new version) |
| Commit hash changes?                    | ✅ Yes                                                            |

---

###### Memory Trick

Think of the last commit as a **Word document** that you just saved.

* **`git commit`** = Save a new version of the document.
* **`git commit --amend`** = Open the most recently saved version, make corrections, and replace it with a corrected version.

From the outside, it looks like the original version never existed, because the corrected version takes its place in the project history.

Excellent! This is one of the most confusing Git concepts for beginners because it introduces the idea of **unstaging**. Don't worry—we'll build it from the beginning with diagrams and examples.

---

#### Unstaging a Staged File

###### What does "Unstage" mean?

Before learning "unstage", let's remember the Git workflow.

```text
               Git Repository
              (Saved History)
                    ▲
                    │ git commit
                    │
              Staging Area
              (Ready to Commit)
                    ▲
                    │ git add
                    │
            Working Directory
           (Where you edit files)
```

Everything starts in the **Working Directory**.

---

###### Example Project

Suppose your project contains:

```text
project/
│
├── README.md
├── main.c
└── CONTRIBUTING.md
```

All files have already been committed.

---

###### Step 1: Modify Two Files

Suppose you edit

```text
README.md
```

and

```text
CONTRIBUTING.md
```

Current situation

```text
Working Directory

README.md         Modified

CONTRIBUTING.md   Modified
```

---

Run

```bash
git status
```

Output

```text
Changes not staged for commit:

modified: README.md
modified: CONTRIBUTING.md
```

Nothing has been staged yet.

---

###### Step 2: Stage Both Files

You accidentally run

```bash
git add *
```

or

```bash
git add .
```

Now

```text
Working Directory

README.md         Modified

CONTRIBUTING.md   Modified

↓

Staging Area

README.md

CONTRIBUTING.md
```

Run

```bash
git status
```

Output

```text
Changes to be committed:

modified: README.md

modified: CONTRIBUTING.md
```

Both files are now ready to commit.

---

#### But You Made a Mistake

Suppose you wanted

```text
README.md
```

to be committed today.

But

```text
CONTRIBUTING.md
```

still needs more work.

You don't want it in this commit.

Question

> How do I remove it from the staging area?

Answer

```bash
git reset HEAD CONTRIBUTING.md
```

---

###### What Does This Command Do?

```bash
git reset HEAD CONTRIBUTING.md
```

It **removes the file from the staging area**.

It **does NOT delete the file**.

It **does NOT remove your changes**.

It simply moves the file back to the **Working Directory**.

---

###### Visual Explanation

Before

```text
Repository

README

CONTRIBUTING

↓

Staging Area

README

CONTRIBUTING

↓

Working Directory

README

CONTRIBUTING
```

Everything staged.

---

Run

```bash
git reset HEAD CONTRIBUTING.md
```

After

```text
Repository

README

CONTRIBUTING

↓

Staging Area

README

↓

Working Directory

README

CONTRIBUTING
```

Notice

Only

```text
CONTRIBUTING.md
```

left the staging area.

Your edits are still there.

---

###### Check Status

Run

```bash
git status
```

Output

```text
Changes to be committed:

README.md
```

and

```text
Changes not staged for commit:

CONTRIBUTING.md
```

Exactly what you wanted.

---

###### Real-Life Example

Imagine you're submitting exam papers.

You have

```text
Math

Science
```

You accidentally place both into the submission folder.

Teacher hasn't collected them yet.

You decide

> I don't want to submit Science today.

You simply remove

```text
Science
```

from the submission folder.

Did you throw away the paper?

❌ No

Did you erase it?

❌ No

You simply removed it from the submission folder.

That's exactly what

```bash
git reset HEAD file
```

does.

---

###### Why "HEAD"?

The command is

```bash
git reset HEAD CONTRIBUTING.md
```

Let's understand each part.

###### `git`

Git program.

---

###### `reset`

Move something back.

---

###### `HEAD`

This is one of Git's important terms.

Think of

```text
HEAD
```

as

> **Your current commit.**

Example

```text
Commit 1

↓

Commit 2

↓

Commit 3

↑

HEAD
```

HEAD points to your latest commit.

When Git says

```bash
git reset HEAD file
```

it means

> Make the staged version of this file match the version in the latest commit.

Your working copy is **not changed**.

---

###### Example

Suppose

Repository

```text
README

Version 1
```

Working Directory

```text
README

Version 2
```

Stage it

```bash
git add README
```

Now

```text
Repository

Version 1

↓

Staging Area

Version 2

↓

Working Directory

Version 2
```

Run

```bash
git reset HEAD README
```

Now

```text
Repository

Version 1

↓

Staging Area

Version 1

↓

Working Directory

Version 2
```

Notice

Working Directory still has

```text
Version 2
```

Nothing was lost.

Only the staging area changed.

---

###### Why Doesn't Git Delete My Work?

Because

```bash
git reset HEAD file
```

only affects

```text
Staging Area
```

It does **not** touch

```text
Working Directory
```

So your changes are safe.

---

###### Before Reset

```text
Working Directory

Modified

↓

Staging Area

Modified
```

---

After Reset

```text
Working Directory

Modified

↓

Staging Area

Original
```

Your work is still there.

---

###### Why Is `git reset` Considered Dangerous?

Because there are different kinds of reset.

Examples

```bash
git reset
```

```bash
git reset --soft
```

```bash
git reset --mixed
```

```bash
git reset --hard
```

Only one is dangerous.

```bash
git reset --hard
```

This command changes **both** the staging area **and** your working directory.

It can permanently remove uncommitted changes.

Example

```bash
git reset --hard
```

Result

```text
Working Directory

↓

Everything goes back to the last commit.
```

Any edits that weren't committed are lost.

**For this reason, beginners should avoid `git reset --hard` unless they fully understand its effect.**

---

###### `git reset HEAD file` vs `git reset --hard`

| Command               | Staging Area | Working Directory | Safe?                           |
| --------------------- | ------------ | ----------------- | ------------------------------- |
| `git reset HEAD file` | Reset        | ❌ Not changed     | ✅ Yes                           |
| `git reset --hard`    | Reset        | Reset             | ⚠️ Can discard uncommitted work |

---

###### Complete Workflow

Suppose

```text
Step 1

Edit README

↓

git add README

↓

README enters Staging Area

↓

Oops!

↓

git reset HEAD README

↓

README leaves Staging Area

↓

Your edits still exist
```

---

###### Practical Demo

Create a file

```bash
echo "Hello" > README.md
```

Stage it

```bash
git add README.md
```

Check

```bash
git status
```

Output

```text
Changes to be committed:

README.md
```

Now unstage

```bash
git reset HEAD README.md
```

Check again

```bash
git status
```

Output

```text
Changes not staged for commit:

README.md
```

Nothing has been deleted.

---

###### Summary

| Command               | Purpose                                                                  |
| --------------------- | ------------------------------------------------------------------------ |
| `git add file`        | Move a file from the Working Directory to the Staging Area               |
| `git reset HEAD file` | Remove a file from the Staging Area but keep your changes                |
| `git commit`          | Save the staged changes in the repository                                |
| `git reset --hard`    | Reset both the Staging Area and the Working Directory (use with caution) |

---

###### Easy Memory Trick

Think of the **Staging Area** as a **submission folder**.

* 📄 `git add file` → Put the paper into the submission folder.
* 📤 `git commit` → Submit the folder.
* ↩️ `git reset HEAD file` → Take one paper **out** of the submission folder, but keep it on your desk.
* ❌ `git reset --hard` → Throw away the papers on your desk and restore everything to the last submitted version.

The key idea is:

> **`git reset HEAD <file>` only unstages a file. It does not delete your work.** That's why it's considered safe for this use case.
Excellent! This is another **very important Git concept**, and it's easy to confuse it with **unstaging**. Let's understand it from **scratch**.

There are **three different operations** that beginners often mix up:

| Operation       | Command                                 | What it does                                                           |
| --------------- | --------------------------------------- | ---------------------------------------------------------------------- |
| Stage a file    | `git add file`                          | Moves changes to the staging area                                      |
| Unstage a file  | `git reset HEAD file`                   | Removes changes from the staging area but keeps your edits             |
| Discard changes | `git checkout -- file` *(older syntax)* | Deletes your edits and restores the file to the last committed version |

Notice that the **third one is completely different**.

---

# First, Understand the Three Git Areas Again

```text
                 Git Repository
              (Last Saved Commit)
                      ▲
                      │ git commit
                      │
                Staging Area
              (Ready to Commit)
                      ▲
                      │ git add
                      │
             Working Directory
          (Where you edit files)
```

This picture explains almost everything in Git.

---

# Suppose You Have This Project

```
project/

README.md
main.c
CONTRIBUTING.md
```

Everything is already committed.

Repository contains

```
README.md

Version 1
```

---

# Step 1: Modify the File

Suppose you open

```
README.md
```

Original

```
Hello World
```

You change it to

```
Hello Git
```

Current situation

```
Repository

Hello World

↓

Working Directory

Hello Git
```

You have **not** run `git add`.

---

Run

```bash
git status
```

Output

```text
Changes not staged for commit:

modified: README.md
```

Git says

> I see that you changed the file.

---

# Suddenly You Change Your Mind

You think

> I don't want these edits anymore.

You want

```
Hello World
```

back.

Git tells you

```text
(use "git checkout -- README.md"
to discard changes)
```

Run

```bash
git checkout -- README.md
```

---

# What Happens?

Git throws away

```
Hello Git
```

and restores

```
Hello World
```

Current situation

```
Repository

Hello World

↓

Working Directory

Hello World
```

Everything becomes exactly like the last commit.

---

# Visual Explanation

Before

```
Repository

Version 1

↓

Working Directory

Version 2
```

Run

```bash
git checkout -- README.md
```

After

```
Repository

Version 1

↓

Working Directory

Version 1
```

Git copied the committed version over your modified file.

---

# Real-Life Example

Imagine you're writing notes.

Original notebook

```
Chapter 1

Networking Basics
```

You start editing.

```
Chapter 1

Networking Basics

OSI Model

TCP/IP

DNS
```

Later you decide

> I don't want these changes.

You erase everything you added.

Back to

```
Chapter 1

Networking Basics
```

That's exactly what

```bash
git checkout -- file
```

does.

---

# Why Is This Dangerous?

Suppose you spent

```
3 hours
```

writing code.

```
main.c

500 new lines
```

You accidentally run

```bash
git checkout -- main.c
```

Git immediately restores

```
main.c
```

to the last commit.

Those **500 lines disappear**.

There is **no undo** if they were never committed.

---

# Example

Original

```c
int speed = 10;
```

You modify

```c
int speed = 50;
```

Git Status

```text
modified: main.c
```

Run

```bash
git checkout -- main.c
```

Now

```c
int speed = 10;
```

again.

The change

```c
int speed = 50;
```

is gone.

---

# Compare with `git reset HEAD`

Many beginners confuse these two.

Suppose

```
README.md
```

is modified.

You stage it.

```bash
git add README.md
```

Current situation

```
Repository

Version 1

↓

Staging Area

Version 2

↓

Working Directory

Version 2
```

Now

```bash
git reset HEAD README.md
```

Result

```
Repository

Version 1

↓

Staging Area

Version 1

↓

Working Directory

Version 2
```

Notice

Your edits still exist.

Nothing is deleted.

---

Now compare

```bash
git checkout -- README.md
```

Result

```
Repository

Version 1

↓

Working Directory

Version 1
```

Your edits disappear.

---

# Very Important Comparison

## `git reset HEAD file`

```
Repository

Version 1

↓

Staging Area

Version 1

↓

Working Directory

Version 2
```

Changes are still on your computer.

---

## `git checkout -- file`

```
Repository

Version 1

↓

Working Directory

Version 1
```

Changes disappear.

---

# Example Workflow

### Step 1

Original

```
Hello
```

---

### Step 2

Modify

```
Hello Git
```

---

### Step 3

Run

```bash
git status
```

```
modified: README.md
```

---

### Step 4

Decide

"I don't want these edits."

Run

```bash
git checkout -- README.md
```

---

### Step 5

Open file

```
Hello
```

again.

Everything you typed is gone.

---

# What If the File Was Staged?

Suppose

```bash
git add README.md
```

already happened.

Current

```
Repository

Version 1

↓

Staging Area

Version 2

↓

Working Directory

Version 2
```

If you run

```bash
git checkout -- README.md
```

the working directory is restored, **but the staged version remains**.

That's why, if your goal is to completely discard a staged change, you typically:

```bash
git reset HEAD README.md
git checkout -- README.md
```

First:

* Remove it from the staging area.

Then:

* Remove your working directory changes.

After both commands:

```
Repository

Version 1

↓

Staging Area

Version 1

↓

Working Directory

Version 1
```

Everything matches the last commit again.

---

# Modern Git (Recommended)

The Git book you're reading uses the older command:

```bash
git checkout -- file
```

Modern Git introduced a clearer command:

```bash
git restore README.md
```

Both commands do the same thing:

```
Restore the file to the last committed version.
```

Most new tutorials and Git documentation recommend `git restore` because it's more descriptive and less confusing than `git checkout`.

---

# Can Git Recover My Deleted Changes?

The Git book says something very important:

## If you committed your work

```
Commit

↓

Deleted later
```

Git can usually recover it.

---

## If you NEVER committed

```
Edit

↓

Delete

↓

Gone
```

Git usually cannot recover it.

That's why developers commit their work frequently.

---

# Summary Table

| Situation                     | Command                | Are your edits kept? |
| ----------------------------- | ---------------------- | -------------------- |
| Stage a file                  | `git add file`         | ✅ Yes                |
| Unstage a file                | `git reset HEAD file`  | ✅ Yes                |
| Discard edits (older syntax)  | `git checkout -- file` | ❌ No                 |
| Discard edits (modern syntax) | `git restore file`     | ❌ No                 |
| Save permanently              | `git commit`           | ✅ Yes                |

---

# Easy Memory Trick

Imagine you're writing on a whiteboard.

* 📝 **`git add`** → Take a **photo** of the current whiteboard (stage it).
* ↩️ **`git reset HEAD file`** → Throw away the **photo**, but leave the writing on the whiteboard.
* 🧽 **`git checkout -- file`** or **`git restore file`** → Erase the whiteboard and restore it to the last saved version.
* 💾 **`git commit`** → Save the photo permanently in your album (the repository).

This analogy helps distinguish the two common "undo" operations:

* **Unstage** = remove from the staging area, keep your edits.
* **Restore/checkout** = remove your edits and go back to the last committed version.
