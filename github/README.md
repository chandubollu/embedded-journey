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
###### showing your remotes

###### Step 1: Imagine You Have a Laptop

Suppose your laptop has a project.

```text
My Laptop

project/
│
├── main.c
├── led.c
├── README.md
└── .git
```

This is called your **Local Repository**.

Everything is stored on **your computer**.

---

###### Step 2: What if Your Laptop Breaks?

Imagine tomorrow your laptop crashes.

```text
Laptop 💻 ❌
```

Your project is gone.

So developers keep another copy on the Internet.

Example:

```text
GitHub

project.git
```

Now there are **two copies**.

```text
        GitHub
      (Remote Repository)
             ▲
             │
             │
             ▼
      Your Laptop
     (Local Repository)
```

---

###### Step 3: What is a Remote?

A **Remote** is simply another Git repository that is stored somewhere else (usually on GitHub).

Think of it like this:

You have

* Your phone

and

* Google Drive

Google Drive stores another copy of your photos.

Similarly,

GitHub stores another copy of your Git repository.

That GitHub repository is called a **Remote Repository**.

---

###### Step 4: Why Do We Need a Name?

Suppose the GitHub repository address is

```text
https://github.com/chandu/project.git
```

That's a long address.

Imagine typing it every time!

Instead, Git stores it with a nickname.

Example

```text
origin
```

Now Git remembers

```text
origin
        ↓
https://github.com/chandu/project.git
```

So instead of using the long URL, Git uses the nickname.

---

###### Think of it Like Contacts in Your Phone

Instead of remembering

```text
9876543210
```

you save

```text
Mom
```

Now

```text
Mom
```

points to

```text
9876543210
```

Git does the same.

```text
origin
```

points to

```text
https://github.com/chandu/project.git
```

---

###### What Happens During `git clone`?

Suppose you type

```bash
git clone https://github.com/schacon/ticgit
```

Git does **five things**.

###### Step 1

Downloads the project.

↓

###### Step 2

Creates a folder.

```text
ticgit/
```

↓

###### Step 3

Creates

```text
.git
```

↓

###### Step 4

Remembers

```text
origin
```

↓

###### Step 5

Links

```text
origin
        ↓
https://github.com/schacon/ticgit
```

---

###### So What Does `git remote` Do?

Run

```bash
git remote
```

Output

```text
origin
```

Many beginners ask

> Why does it only print "origin"?

Because **`git remote` only shows the nicknames**, not the full addresses.

Think of your phone contacts.

If you open Contacts, you see

```text
Mom

Dad

Friend
```

You don't immediately see the phone numbers.

Similarly,

```bash
git remote
```

shows only

```text
origin
```

---

###### What Does `git remote -v` Do?

Now run

```bash
git remote -v
```

Output

```text
origin https://github.com/schacon/ticgit (fetch)

origin https://github.com/schacon/ticgit (push)
```

Now Git shows **more details**.

Let's understand each part.

---

###### Part 1

```text
origin
```

This is the nickname.

---

###### Part 2

```text
https://github.com/schacon/ticgit
```

This is the real address.

---

###### Part 3

```text
(fetch)
```

Means

> Download from this address.

---

###### Part 4

```text
(push)
```

Means

> Upload to this address.

---

###### What is Fetch?

Suppose your friend adds new code to GitHub.

```text
GitHub

↓

New Code
```

You want to download it.

That is called

```text
Fetch
```

Simple meaning:

```text
GitHub

↓

My Laptop
```

Download.

---

###### What is Push?

Suppose you write new code.

```text
My Laptop

↓

New Code
```

Now you upload it.

```text
GitHub
```

That is called

```text
Push
```

Simple meaning:

```text
My Laptop

↓

GitHub
```

Upload.

---

###### Why Are There Two Lines?

Book shows

```text
origin https://github.com/... (fetch)

origin https://github.com/... (push)
```

Many beginners think there are two remotes.

No.

There is **only one remote**.

Git is simply telling you

```text
Fetch URL

↓

https://github.com/...
```

and

```text
Push URL

↓

https://github.com/...
```

Usually both are identical.

---

###### Visual Diagram

```text
             GitHub
      https://github.com/project

          ▲            │
          │            │
      Push │            │ Fetch
          │            ▼

        My Laptop
```

---

###### What If There Are Multiple Remotes?

Now imagine you're working in a company.

There is

```text
Main Project
```

Your friend also has

```text
Friend Project
```

Another teammate has

```text
Testing Project
```

Git can remember all of them.

Example

```bash
git remote -v
```

Output

```text
origin

↓

Main GitHub

friend

↓

Friend GitHub

office

↓

Company GitLab
```

---

So

```text
origin
```

means

Main repository.

```text
friend
```

means

Friend's repository.

```text
office
```

means

Company repository.

---

###### Understanding the Book's Example

The book shows

```text
bakkdoor
```

```text
cho45
```

```text
defunkt
```

```text
koke
```

```text
origin
```

These are **NOT Git commands**.

These are simply **names of different remote repositories**.

Imagine

```text
bakkdoor

↓

Rahul's GitHub
```

```text
cho45

↓

Ravi's GitHub
```

```text
origin

↓

Main Project
```

Git knows all of them.

---

###### Why Would We Have Multiple Remotes?

Suppose four developers are working.

```text
Main Project

↓

Your Laptop

↓

Friend's Project

↓

Testing Server
```

You may want to download code from all of them.

Instead of remembering four URLs,

Git remembers

```text
origin

friend

testing

office
```

Much easier.

---

###### What Does This Sentence Mean?

The book says

> "We can pull contributions from any of these users."

Meaning

If Rahul fixes a bug,

Git can download Rahul's changes.

If Ravi adds a feature,

Git can download Ravi's changes.

That's all it means.

---

###### What About Push?

The book also says

> "We may additionally have permission to push."

This means

Some repositories allow you to upload code.

Some don't.

Example

```text
Friend's Repository

↓

Read Only
```

You can download.

You cannot upload.

But

```text
Your Repository

↓

Read + Write
```

You can both download and upload.

---

###### Easy Real-Life Analogy

Imagine you have cloud storage accounts.

```text
Google Drive

↓

Nickname

drive
```

```text
Dropbox

↓

Nickname

dropbox
```

```text
OneDrive

↓

Nickname

office
```

Now your computer remembers

```text
drive

↓

Google Drive
```

```text
dropbox

↓

Dropbox
```

Git remotes work exactly the same way.

---

###### Final Picture (Everything Together)

```text
                    INTERNET

      GitHub(Main Repo)
      https://github.com/chandu/project
                ▲
                │
         nickname = origin
                │
                │
                ▼

           Your Laptop
         Local Repository
                ▲
                │
      git remote -v

Shows:

origin
https://github.com/chandu/project
(fetch)
(push)
```

---

###### Commands You Should Remember

| Command         | Meaning                                             |
| --------------- | --------------------------------------------------- |
| `git remote`    | Show only the remote names (nicknames)              |
| `git remote -v` | Show remote names and their URLs                    |
| `origin`        | Default nickname for the repository you cloned from |
| `(fetch)`       | Download changes from the remote                    |
| `(push)`        | Upload your commits to the remote                   |

###### The one thing to remember

**A remote is just another Git repository, and `origin` is simply its nickname.**

So when you see:

```text
origin  https://github.com/chandu/project.git (fetch)
origin  https://github.com/chandu/project.git (push)
```

Read it in plain English as:

> **"I have a remote repository named `origin`. Its address is `https://github.com/chandu/project.git`. I use this address both for downloading (fetch) and uploading (push)."**

Once this idea is clear, the next Git commands (`git fetch`, `git pull`, and `git push`) will become much easier to understand.

###### Adding Remote Repositories
###### Adding Remote Repositories (`git remote add`) and Fetching Changes (`git fetch`) - Complete Notes

---

###### Adding Remote Repositories

###### What is a Remote Repository?

A **Remote Repository** is a Git repository stored on another computer or server (usually GitHub, GitLab, or Bitbucket).

It allows you to:

* Backup your code
* Collaborate with other developers
* Share your project
* Download changes made by others

---

###### Local Repository vs Remote Repository

```text
              Internet

      Remote Repository
      (GitHub / GitLab)

              ▲
              │ Push
              │
              │
              ▼ Fetch

      Local Repository
      (Your Computer)
```

---

###### What is a Remote?

A **remote** is simply a **nickname** for another Git repository.

Instead of typing a long URL every time,

```text
https://github.com/chandu/project.git
```

Git lets us use a short name like

```text
origin
```

Example:

```text
origin
      ↓
https://github.com/chandu/project.git
```

---

###### Default Remote

When you clone a repository,

```bash
git clone https://github.com/chandu/project.git
```

Git automatically creates a remote named

```text
origin
```

You can verify it using

```bash
git remote
```

Output

```text
origin
```

---

###### Why Add Another Remote?

Suppose there are two repositories.

```text
Main Repository

↓

https://github.com/chandu/project.git
```

and

```text
Paul's Repository

↓

https://github.com/paulboone/project.git
```

Your local repository can communicate with both.

---

###### Command to Add a Remote

```bash
git remote add <shortname> <url>
```

Example

```bash
git remote add pb https://github.com/paulboone/project.git
```

Here,

* `git` → Git command
* `remote` → Work with remote repositories
* `add` → Add a new remote
* `pb` → Short name (nickname)
* URL → Actual repository address

---

###### Checking the Remote

```bash
git remote
```

Output

```text
origin
pb
```

This means Git now knows two remote repositories.

---

###### View Complete Information

```bash
git remote -v
```

Output

```text
origin https://github.com/chandu/project.git (fetch)

origin https://github.com/chandu/project.git (push)

pb https://github.com/paulboone/project.git (fetch)

pb https://github.com/paulboone/project.git (push)
```

---

###### Meaning of the Output

```text
origin
```

Remote nickname.

```text
https://github.com/chandu/project.git
```

Repository URL.

```text
(fetch)
```

Used when downloading.

```text
(push)
```

Used when uploading.

---

###### Real-Life Analogy

Think of your phone contacts.

```text
Mom
↓

9876543210

Dad
↓

9988776655

Paul
↓

9876501234
```

Instead of remembering phone numbers,

you save names.

Git works the same way.

```text
origin
↓

GitHub Repository

pb
↓

Paul's Repository
```

---

###### What is `git fetch`?

`git fetch` downloads the latest commits and branch information from a remote repository.

It **does NOT change your current project files**.

Syntax

```bash
git fetch <remote-name>
```

Example

```bash
git fetch pb
```

---

###### What Happens During `git fetch pb`?

Git contacts the remote named

```text
pb
```

which points to

```text
https://github.com/paulboone/project.git
```

Git downloads

* New commits
* New branches
* Updated branch information

These are stored inside Git's internal database (`.git`).

---

###### Real-Time Example

Suppose you and Paul are working on the same project.

###### Your Local Repository

```text
Commit A
```

###### Paul's Repository

```text
Commit A

↓

Commit B
```

You don't have Commit B.

---

Run

```bash
git fetch pb
```

Git downloads Commit B.

---

###### Where Does Git Store the Downloaded Commits?

Git stores them inside the hidden

```text
.git
```

directory.

It creates or updates a **remote-tracking branch**.

```text
pb/master

↓

Commit B
```

Your current branch remains unchanged.

---

###### Before Fetch

```text
Working Directory

Commit A

Git Database

master

↓

Commit A
```

---

###### After Fetch

```text
Working Directory

Commit A

Git Database

master

↓

Commit A


pb/master

↓

Commit B
```

Notice:

* Working Directory did NOT change.
* Only Git's database changed.

---

###### Does `git fetch` Modify My Files?

**No.**

Your project files remain exactly the same.

Example

Before fetch

```text
main.c

Version A
```

After

```bash
git fetch pb
```

Still

```text
main.c

Version A
```

Paul's Version B is stored inside Git's database.

---

###### Why Doesn't Git Replace My Files?

Git wants to protect your current work.

It downloads changes first.

Later, you decide whether to use them.

---

###### Real-Life Analogy

Suppose your teacher uploads new notes.

You download them.

The downloaded notes are stored in your **Downloads** folder.

They do **not** automatically replace your notebook.

Git works exactly the same way.

```text
Teacher's Notes

↓

Download

↓

Downloads Folder
```

Similarly,

```text
Paul's Repository

↓

git fetch pb

↓

Git Database (.git)
```

---

###### Then When Do My Files Change?

Only when you explicitly integrate the downloaded commits.

Examples

```bash
git merge pb/master
```

or

```bash
git checkout pb/master
```

or

```bash
git pull
```

(`git pull` performs a `fetch` and then integrates the fetched changes.)

---

###### What is `pb/master`?

`pb/master` is called a **remote-tracking branch**.

It represents Paul's `master` branch on your local machine.

It is **not** your own `master` branch.

Example

```text
master

↓

Your Branch
```

```text
pb/master

↓

Paul's Branch
```

---

###### Complete Workflow

###### Step 1

Clone repository

```bash
git clone https://github.com/chandu/project.git
```

Git automatically creates

```text
origin
```

---

###### Step 2

Add Paul's repository

```bash
git remote add pb https://github.com/paulboone/project.git
```

---

###### Step 3

Verify remotes

```bash
git remote -v
```

---

###### Step 4

Download Paul's latest work

```bash
git fetch pb
```

---

###### Step 5

Git stores downloaded commits

```text
.git

↓

pb/master
```

---

###### Step 6

When ready, integrate Paul's work

```bash
git merge pb/master
```

---

###### Visual Workflow

```text
                    Paul's Repository

                     Commit A
                         │
                         ▼
                     Commit B
                         │
                    git fetch pb
                         │
                         ▼

              Git Database (.git)

                 master

                     │

                 Commit A


               pb/master

                     │

                 Commit B


Working Directory

Still using Commit A
```

---

###### Important Points

* `git remote add` adds a new remote repository.
* A remote is just a nickname for a repository URL.
* `origin` is the default remote created during cloning.
* `git fetch` downloads commits only.
* Downloaded commits are stored inside `.git`.
* `git fetch` never changes your current files.
* `pb/master` is a remote-tracking branch.
* You must merge or check out the fetched branch to use its changes.

---

###### Commands Summary

| Command                   | Description                                                           |
| ------------------------- | --------------------------------------------------------------------- |
| `git remote`              | Show remote names                                                     |
| `git remote -v`           | Show remote names with URLs                                           |
| `git remote add pb <URL>` | Add a new remote repository                                           |
| `git fetch pb`            | Download commits from the `pb` remote                                 |
| `git merge pb/master`     | Merge Paul's downloaded changes into your current branch              |
| `git checkout pb/master`  | View Paul's branch (detached HEAD state unless creating a new branch) |

---

###### Memory Trick

Think of **Git remotes as contacts** and **`git fetch` as downloading files**.

```text
Phone Contacts

Mom
↓

Phone Number

Dad
↓

Phone Number

Paul
↓

Phone Number
```

Git Remotes

```text
origin
↓

Main GitHub Repository

pb
↓

Paul's Repository
```

When you run

```bash
git fetch pb
```

it's like saying:

> "Connect to **Paul's repository**, download the latest updates into Git's storage (`.git`), but **don't change my project files yet**."

This is why `git fetch` is considered a **safe operation**—it downloads first and lets you decide later when and how to use the new changes.

###### fetching,pulling and pushing to your remotes
Excellent! This is one of the **most important Git topics**. Once you understand **`fetch`**, **`pull`**, and **`push`**, you'll know how developers collaborate in real companies.

I'll explain it exactly like I would to a **10th standard student**, using a **real software company example**.

---

###### Scenario: Smart Irrigation Project

Imagine you joined a company called **GreenTech Solutions**.

Your team is building a **Smart Irrigation System** using an ESP32.

There are two developers.

👨‍💻 **You (Chandu)**

👨‍💻 **Paul**

The project is stored on GitHub.

```text
               GitHub (origin)

           Smart Irrigation Project
```

Both of you clone the repository.

```bash
git clone https://github.com/greentech/smart-irrigation.git
```

Now everyone has a copy.

---

###### Initial Situation

```text
              GitHub (origin)

                 Commit A
                     ▲
                     │
          ┌──────────┴──────────┐
          │                     │
          │                     │
      Your Laptop         Paul's Laptop

        Commit A             Commit A
```

Everything is the same.

---

###### Day 1 - Paul Writes New Code

Paul adds MQTT support.

```text
Commit B

"Added MQTT communication"
```

He pushes it.

```bash
git push origin master
```

Now

```text
GitHub

Commit A

↓

Commit B
```

But your laptop still has

```text
Commit A
```

---

###### What Happens if You Run `git fetch origin`?

Command

```bash
git fetch origin
```

Git contacts GitHub.

```text
Your Laptop
      │
      │
      ▼

GitHub (origin)
```

Git downloads

```text
Commit B
```

and stores it inside

```text
.git
```

Now your Git database looks like

```text
master

↓

Commit A


origin/master

↓

Commit A

↓

Commit B
```

Notice

Your project files are **still using Commit A**.

Nothing changes.

---

###### Real-Life Example

Imagine your teacher uploads new notes.

You click

```text
Download
```

The notes go into

```text
Downloads/
```

They do **not** automatically replace your notebook.

`git fetch` works exactly like that.

---

###### Summary of `git fetch`

✔ Downloads latest commits

✔ Stores them inside `.git`

✔ Updates `origin/master`

✔ Does NOT change your project files

---

###### What is `git pull`?

Suppose now you actually want Paul's new MQTT code.

Instead of running

```bash
git fetch origin
```

and then

```bash
git merge origin/master
```

Git provides a shortcut.

```bash
git pull
```

---

###### What Does `git pull` Do?

It performs two steps automatically.

###### Step 1

Downloads new commits

```text
git fetch
```

↓

###### Step 2

Merges them into your branch

```text
git merge
```

↓

Your project files are updated.

---

###### Visual Diagram

Before

```text
GitHub

Commit A

↓

Commit B



Your Laptop

Commit A
```

Run

```bash
git pull
```

After

```text
GitHub

Commit A

↓

Commit B



Your Laptop

Commit A

↓

Commit B
```

Now your files contain Paul's MQTT code.

---

###### Easy Formula

```text
git pull

=

git fetch

+

git merge
```

Remember this forever.

---

###### Real-Life Analogy

Imagine WhatsApp.

Friend sends you

```
Notes.pdf
```

###### `git fetch`

Downloads

```
Notes.pdf
```

into Downloads.

You haven't opened it.

---

###### `git pull`

Downloads

AND

opens it,

replacing your old notes.

---

###### Now Let's Understand `git push`

Suppose you add Wi-Fi support.

Your laptop

```text
Commit A

↓

Commit B

↓

Commit C
```

GitHub

```text
Commit A

↓

Commit B
```

Your Commit C exists only on your laptop.

Nobody else can see it.

---

###### You Run

```bash
git push origin master
```

Git uploads your new commit.

```text
Your Laptop

Commit C

      │
      │ Upload
      ▼

GitHub
```

Now

```text
GitHub

Commit A

↓

Commit B

↓

Commit C
```

Everyone can download it.

---

###### Real-Life Example

Imagine Google Drive.

You edited

```
Project Report.docx
```

It is saved only on your laptop.

When you click

```
Upload
```

Google Drive now contains the new version.

Git Push works exactly the same way.

---

###### Visual Diagram

Before Push

```text
GitHub

Commit A

↓

Commit B



Your Laptop

Commit A

↓

Commit B

↓

Commit C
```

Run

```bash
git push origin master
```

After

```text
GitHub

Commit A

↓

Commit B

↓

Commit C



Your Laptop

Commit A

↓

Commit B

↓

Commit C
```

---

###### What Happens If Someone Else Pushes First?

This is very common in companies.

Suppose

You and Paul both start from

```text
Commit A
```

---

Paul finishes first.

He pushes.

```text
GitHub

Commit A

↓

Commit B
```

---

You don't know about Commit B.

You create

```text
Commit C
```

Now

GitHub

```text
Commit A

↓

Commit B
```

Your Laptop

```text
Commit A

↓

Commit C
```

---

You try

```bash
git push origin master
```

Git says

```text
Rejected!
```

Why?

Because GitHub already has Paul's work that you don't have.

If Git accepted your push, Paul's changes could be overwritten.

Git protects the project.

---

###### What Should You Do?

First

```bash
git fetch origin
```

Download Paul's work.

Then

```bash
git merge origin/master
```

Combine Paul's work with yours.

Now

```text
Commit A

↓

Commit B

↓

Merge Commit

↓

Commit C
```

Finally

```bash
git push origin master
```

Now Git accepts it.

---

###### Company Workflow

```text
Morning

Everyone clones

        │

        ▼

Paul writes code

        │

        ▼

Paul pushes

        │

        ▼

You fetch/pull

        │

        ▼

You continue working

        │

        ▼

You push

        │

        ▼

Everyone pulls
```

This happens every day in software companies.

---

###### Complete Comparison

| Command     | Downloads? | Uploads? | Changes Working Files?                  |
| ----------- | ---------- | -------- | --------------------------------------- |
| `git fetch` | ✅ Yes      | ❌ No     | ❌ No                                    |
| `git pull`  | ✅ Yes      | ❌ No     | ✅ Yes (merges into your current branch) |
| `git push`  | ❌ No       | ✅ Yes    | ❌ No                                    |

---

###### Easy Memory Trick

Think of **GitHub as a cloud drive**.

```
                GitHub (Cloud)

                     ▲
                     │
          git push   │   Upload your work
                     │
                     │
Your Laptop──────────┘


                GitHub (Cloud)

                     │
          git fetch  │   Download only
                     ▼

              Hidden Git Database (.git)


                GitHub (Cloud)

                     │
           git pull  │   Download + update project
                     ▼

            Your Working Files
```

###### Remember These Three Sentences

* **`git fetch`** → **"Download the latest changes, but don't touch my current files."**
* **`git pull`** → **"Download the latest changes and immediately update my current branch."**
* **`git push`** → **"Upload my commits from my local repository to the remote repository."**

These three commands form the foundation of day-to-day collaboration with Git.

##### inspecting,renameing and removing remotes
Excellent! This section is about **managing remote repositories**. It teaches you how to:

1. **Inspect a remote** (`git remote show`)
2. **Rename a remote** (`git remote rename`)
3. **Remove a remote** (`git remote remove` or `git remote rm`)

I'll explain everything using a **real software company example**.

---

###### Managing Remote Repositories

---

###### Real-Time Scenario

Imagine you work at **ABC Technologies**.

Your team is developing an **ESP32 Smart Home System**.

The project is hosted on GitHub.

You have cloned the project.

```bash
git clone https://github.com/company/smart-home.git
```

Git automatically creates

```text
origin
```

Later you also add Paul's repository.

```bash
git remote add pb https://github.com/paul/smart-home.git
```

Now your repository knows two remotes.

```text
origin

pb
```

---

###### Inspecting a Remote

###### Why Do We Need It?

Suppose after a few weeks you forget:

* Which GitHub repository is `origin`?
* Which branch does `git pull` use?
* Which branch does `git push` upload to?
* Which remote branches exist?

Instead of guessing, Git can tell you.

---

###### Command

```bash
git remote show origin
```

This displays detailed information about the remote.

---

###### Example Output

```text
$ git remote show origin

* remote origin

Fetch URL:
https://github.com/company/smart-home.git

Push URL:
https://github.com/company/smart-home.git

HEAD branch:
master

Remote branches:
master tracked
dev tracked

Local branch configured for 'git pull':
master merges with remote master

Local ref configured for 'git push':
master pushes to master
```

Let's understand every line.

---

###### Line 1

```text
remote origin
```

Git is showing information about the remote named

```text
origin
```

---

###### Fetch URL

```text
Fetch URL

https://github.com/company/smart-home.git
```

This is the repository Git contacts when you run

```bash
git fetch origin
```

or

```bash
git pull
```

Think of it as

> "Download address."

---

###### Push URL

```text
Push URL

https://github.com/company/smart-home.git
```

This is where Git uploads commits when you run

```bash
git push
```

Think of it as

> "Upload address."

Sometimes the Fetch URL and Push URL are the same. In advanced setups, they can be different (for example, downloading from a public mirror but pushing to the main repository).

---

###### HEAD Branch

```text
HEAD branch: master
```

This means

The main branch of the remote repository is

```text
master
```

Nowadays many repositories use

```text
main
```

instead.

---

###### Remote Branches

```text
master tracked

dev tracked
```

This means the remote repository contains

```text
master
```

and

```text
dev
```

Git knows about both.

---

Visual

```text
GitHub

master

dev
```

---

###### Local Branch Configured for `git pull`

```text
master merges with remote master
```

This means

When you're on your local

```text
master
```

and run

```bash
git pull
```

Git automatically performs

```bash
git fetch origin
```

followed by

```bash
git merge origin/master
```

You don't have to specify the branch every time.

---

###### Local Branch Configured for `git push`

```text
master pushes to master
```

When you're on

```text
master
```

and type

```bash
git push
```

Git automatically knows

```text
Push local master

↓

Remote master
```

---

###### Real-Life Analogy

Imagine your phone has a contact called

```text
Office
```

If you forget the phone number,

you open the contact details.

```text
Office

Phone:
9876543210

Address:
Hyderabad
```

`git remote show` is exactly like opening the contact details for a remote.

---

###### New Branches

Sometimes you'll see

```text
issue-43 new
```

This means

Someone created a new branch on GitHub.

You haven't downloaded it yet.

The next

```bash
git fetch
```

will download it.

---

###### Stale Branch

Sometimes you'll see

```text
issue-11 stale
```

Meaning

That branch was deleted from GitHub,

but your local repository still remembers it.

It's like a phone contact for someone who no longer works at the company.

---

To remove it

```bash
git remote prune origin
```

Git removes the outdated remote-tracking branches.

---

###### Renaming a Remote

Suppose

You added

```text
pb
```

But later you think

```text
pb
```

isn't a meaningful name.

You want

```text
paul
```

instead.

---

Command

```bash
git remote rename pb paul
```

---

Before

```text
origin

pb
```

---

After

```text
origin

paul
```

Nothing else changes.

Only the nickname changes.

---

###### Real-Life Example

Your phone contact

Before

```text
PB
```

You rename it to

```text
Paul
```

The phone number remains the same.

Only the contact name changes.

Git behaves the same way.

---

###### Remote-Tracking Branches Also Change

Before

```text
pb/master
```

After

```text
paul/master
```

Git updates the names automatically.

---

###### Removing a Remote

Suppose Paul leaves the company.

You no longer need his repository.

Remove it.

```bash
git remote remove paul
```

or

```bash
git remote rm paul
```

Both commands do the same thing.

---

Before

```text
origin

paul
```

---

After

```text
origin
```

Paul's remote has been removed.

---

###### What Else Gets Deleted?

Git also deletes

* `paul/master`
* `paul/dev`
* all remote-tracking branches belonging to `paul`
* configuration related to `paul`

Your local branches and commits remain untouched.

---

###### Visual Diagram

Before

```text
                Your Local Repository

origin ─────────► Company GitHub

paul ───────────► Paul's GitHub
```

Run

```bash
git remote remove paul
```

After

```text
                Your Local Repository

origin ─────────► Company GitHub
```

The connection to Paul's repository is removed.

---

###### Complete Workflow

###### Clone project

```bash
git clone https://github.com/company/project.git
```

Git creates

```text
origin
```

---

###### Add another remote

```bash
git remote add pb https://github.com/paul/project.git
```

---

###### Inspect remote

```bash
git remote show pb
```

Shows

* URL
* branches
* pull configuration
* push configuration

---

###### Rename remote

```bash
git remote rename pb paul
```

---

###### Remove remote

```bash
git remote remove paul
```

---

###### Summary Table

| Command                     | Purpose                                                                  |
| --------------------------- | ------------------------------------------------------------------------ |
| `git remote`                | List all remote names                                                    |
| `git remote -v`             | Show remote names with fetch/push URLs                                   |
| `git remote show origin`    | Display detailed information about a remote                              |
| `git remote rename pb paul` | Rename the remote from `pb` to `paul`                                    |
| `git remote remove paul`    | Remove the remote named `paul`                                           |
| `git remote rm paul`        | Short form of `git remote remove paul`                                   |
| `git remote prune origin`   | Remove stale remote-tracking branches that no longer exist on the remote |

---

###### Memory Trick

Think of **Git remotes as saved contacts** in your phone.

* **`git remote`** → Show your contact names.
* **`git remote -v`** → Show the contact names along with their phone numbers (URLs).
* **`git remote show origin`** → Open a contact and view all its details (URLs, default branch, pull/push settings, tracked branches).
* **`git remote rename pb paul`** → Rename the contact from "PB" to "Paul" without changing the phone number.
* **`git remote remove paul`** → Delete the contact entirely, along with Git's stored tracking information for that remote.

This is exactly how remote management works in day-to-day Git usage.
##### Tagging
Excellent! **Tagging** is one of Git's most useful features, especially in software development. Developers use tags to mark **important versions** like:

* v1.0 (First Release)
* v2.0 (Major Update)
* v3.1 (Bug Fix Release)

Let's understand it from **scratch** with **real-time examples**.

---

###### What is a Tag?

A **tag** is a **label (name)** attached to a specific commit.

Think of it as putting a **sticker** on an important page in a book.

Instead of remembering a long commit ID like:

```text
7d4f91ab0b7c72d55b6d6f0b1b2e9a3c4d5e6f7a
```

you can simply say:

```text
v1.0
```

---

###### Real-Life Example

Imagine you are writing a notebook.

```text
Page 1 → Introduction

Page 2 → Chapter 1

Page 3 → Chapter 2

Page 4 → Final Exam Notes
```

Since **Page 4** is very important, you stick a label on it.

```text
⭐ Final Exam
```

Now you don't have to search through the entire notebook.

You can directly go to

```text
⭐ Final Exam
```

Git Tags work exactly the same way.

---

###### Real Software Company Example

Suppose you're developing an **ESP32 Smart Irrigation System**.

###### Version 1

Features:

* WiFi Connection
* Temperature Sensor

Project released to customers.

You create a tag

```text
v1.0
```

---

After two months,

you add

* MQTT
* OLED Display

Release again.

Tag it

```text
v2.0
```

---

After one week,

you fix one bug.

Release

```text
v2.0.1
```

---

Your history now looks like

```text
Commit A

↓

Commit B

↓

Commit C

↓

Commit D

↓

Commit E
```

Tags

```text
Commit B  ← v1.0

Commit D  ← v2.0

Commit E  ← v2.0.1
```

Notice

A tag simply points to an existing commit.

---

###### Why Do We Need Tags?

Imagine six months later.

Your customer says

> "We want Version 1.0."

Without tags,

you would need to search through hundreds of commits.

With tags,

Git already knows

```text
v1.0

↓

Commit B
```

Very easy.

---

###### Visual Diagram

```text
Commit A

↓

Commit B  ← v1.0

↓

Commit C

↓

Commit D  ← v2.0

↓

Commit E  ← v2.0.1
```

Tags are just names pointing to commits.

---

###### Listing Tags

To see all available tags

```bash
git tag
```

Output

```text
v1.0

v2.0

v2.0.1
```

Git lists all tags.

---

###### Important Note

The tags are displayed in **alphabetical order**, not by the date they were created.

Example

```text
v0.1

v1.3

v2.0
```

This is just a list.

It doesn't mean `v0.1` was created first in the output.

---

###### Searching for Tags

Suppose your project has 500 tags.

You only want to see

```text
v2.0
```

series.

Run

```bash
git tag -l "v2.0*"
```

Output

```text
v2.0

v2.0.1

v2.0.2

v2.0.3
```

Git shows only tags beginning with

```text
v2.0
```

---

###### Understanding the Wildcard (`*`)

The `*` means

> "Match anything after this."

Example

```bash
git tag -l "v1*"
```

matches

```text
v1.0

v1.1

v1.2

v1.3

v1.5
```

---

Another example

```bash
git tag -l "release*"
```

matches

```text
release1

release2

release-final

release-beta
```

---

###### Why Use `-l`?

When listing all tags

```bash
git tag
```

works.

Also

```bash
git tag -l
```

works.

Both produce

```text
v1.0

v2.0

v3.0
```

---

But when searching using wildcards,

Git **requires**

```bash
git tag -l
```

Example

Correct

```bash
git tag -l "v2*"
```

Wrong

```bash
git tag "v2*"
```

Git will not interpret this as a tag search.

---

###### Real-Time Company Example

Imagine your company releases software every month.

```text
January

v1.0

February

v1.1

March

v1.2

April

v2.0

May

v2.1
```

Now your manager asks

> "Show me all Version 2 releases."

Run

```bash
git tag -l "v2*"
```

Output

```text
v2.0

v2.1
```

Git filters the list.

---

###### Think Like a Student

Suppose your exam papers are labeled

```text
Math-1

Math-2

Math-3

Physics-1

Physics-2
```

Teacher asks

> "Show me all Math papers."

You select

```text
Math-1

Math-2

Math-3
```

This is exactly what

```bash
git tag -l "Math*"
```

would do if these were tag names.

---

###### Visual Example

```text
Git History

Commit A

↓

Commit B ← v1.0

↓

Commit C

↓

Commit D ← v2.0

↓

Commit E ← v2.1

↓

Commit F ← v3.0
```

Running

```bash
git tag
```

shows

```text
v1.0

v2.0

v2.1

v3.0
```

Running

```bash
git tag -l "v2*"
```

shows

```text
v2.0

v2.1
```

---

###### Commands Summary

| Command              | Purpose                           |
| -------------------- | --------------------------------- |
| `git tag`            | List all tags                     |
| `git tag -l`         | List all tags (same as `git tag`) |
| `git tag -l "v1*"`   | List tags starting with `v1`      |
| `git tag -l "v2.0*"` | List all `v2.0` series tags       |

---

###### Memory Trick

Think of **Git tags as bookmarks or labels** on important versions.

* 📖 **Commit** = A page in the book.
* 🔖 **Tag** = A bookmark placed on an important page.
* 📋 **`git tag`** = Show all bookmarks.
* 🔍 **`git tag -l "v2*"`** = Show only bookmarks that start with `v2`.

A **tag never creates a new commit**. It simply gives an existing commit a meaningful, easy-to-remember name like `v1.0` or `v2.0.1`. This makes it easy to return to important releases at any time.



##### Creating Tags in Git

Git supports **two types of tags**.

1. **Lightweight Tag**
2. **Annotated Tag**

Both point to a commit, but they store different amounts of information.

---

###### First Understand the Problem

Suppose your company is developing an **ESP32 Smart Home System**.

The project history looks like this:

```text
Commit A
Project Started

↓

Commit B
WiFi Added

↓

Commit C
MQTT Added

↓

Commit D
OLED Added

↓

Commit E
Bug Fixed
```

Now your manager says:

> "Today's version is our first official release."

Instead of remembering

```text
8e4d92fba721ec872d6fd0a98e5c6....
```

you create a tag

```text
v1.0
```

Now everyone knows

```text
v1.0

↓

Commit D
```

---

###### Two Ways to Create a Tag

Git gives two choices.

```text
Tags

├── Lightweight Tag

└── Annotated Tag
```

---

###### 1. Lightweight Tag

Think of it as a **simple label**.

It stores

* Tag name
* Commit reference

Nothing else.

---

###### Real-Life Example

Imagine your notebook.

You put a sticky note.

```text
⭐ Unit Test
```

That's all.

The sticky note doesn't say

* Who attached it
* When it was attached
* Why it was attached

It simply marks a page.

A Lightweight Tag works exactly like this.

---

###### Creating a Lightweight Tag

Command

```bash
git tag v1.0
```

Git simply creates

```text
v1.0

↓

Commit D
```

No extra information is stored.

---

###### Visual Diagram

Before

```text
Commit A

↓

Commit B

↓

Commit C
```

After

```text
Commit A

↓

Commit B ← v1.0

↓

Commit C
```

The tag is just another pointer.

---

###### Viewing It

Run

```bash
git show v1.0
```

Output

```text
commit ca82a6d...

Author:
Scott Chacon

Date:
...

Commit Message
```

Notice

Git only shows the **commit**.

There is **no tag information**.

---

###### Why?

Because Lightweight Tags don't store extra details.

They simply point to a commit.

---

###### Think Like This

Lightweight Tag

```text
Label

↓

Commit
```

Nothing else.

---

###### 2. Annotated Tag

Annotated Tags are much more powerful.

Git stores them as a complete object.

They contain

* Tag name
* Tagger name
* Email
* Date
* Message
* Checksum
* Optional GPG signature

---

###### Real-Life Example

Imagine instead of attaching a small sticky note,

you attach an official release certificate.

```text
Release Version

v1.0

Released By:
Chandu

Date:
15 July 2026

Reason:
First Stable Release
```

Much more information.

---

###### Creating an Annotated Tag

Command

```bash
git tag -a v1.0 -m "First Stable Release"
```

Let's understand every part.

---

###### git

Run Git.

---

###### tag

Create a tag.

---

###### -a

Means

```text
Annotated Tag
```

---

######## v1.0

Tag name.

---

###### -m

Message.

---

###### "First Stable Release"

Description stored with the tag.

---

###### Visual Diagram

```text
Annotated Tag

v1.0

↓

Tag Object

↓

Commit D
```

Notice

Git creates a separate **Tag Object**.

---

###### Why Create a Separate Object?

Because Git wants to store extra information.

Like

```text
Tag Name

v1.0

Tagger

Chandu

Date

15 July 2026

Message

First Stable Release
```

A Lightweight Tag cannot store these.

---

###### Viewing an Annotated Tag

Run

```bash
git show v1.0
```

Output

```text
tag v1.0

Tagger:
Chandu

Date:
15 July 2026

First Stable Release

commit
...

Author
...

Commit Message
```

Notice

Git first displays

```text
Tag Information
```

then

```text
Commit Information
```

---

###### Real-Time Company Example

Suppose you're working in a company.

Today's release

```text
v2.0
```

Manager asks

> "Who created this release?"

Because you used an Annotated Tag,

Git immediately knows.

```text
Tagger

Chandu
```

Manager asks

> "Why was this release created?"

Git shows

```text
Second Stable Release
```

Everything is recorded.

---

###### Lightweight Tag Example

Create

```bash
git tag test-build
```

Now

```text
test-build

↓

Commit D
```

Git stores only

```text
test-build
```

No author.

No date.

No message.

---

###### Annotated Tag Example

Create

```bash
git tag -a v2.0 -m "Production Release"
```

Git stores

```text
Tag

↓

v2.0

↓

Tagger

↓

Date

↓

Message

↓

Commit D
```

Much richer information.

---

###### Visual Comparison

###### Lightweight Tag

```text
v1.0

↓

Commit D
```

---

###### Annotated Tag

```text
v1.0

↓

Tag Object

↓

Tagger

↓

Date

↓

Message

↓

Commit D
```

---

###### Think of ID Cards

###### Lightweight Tag

Like writing

```text
John
```

on a paper.

That's it.

---

###### Annotated Tag

Like an employee ID card.

```text
Employee

John

ID

1234

Department

Embedded

Joining Date

15 July

Signature
```

Much more information.

---

###### Why Does Git Recommend Annotated Tags?

Because official releases should have

* Author
* Date
* Message
* Verification
* History

Large companies almost always use **Annotated Tags** for official releases.

---

###### When Should We Use Lightweight Tags?

Temporary work.

Example

```text
Before Testing

Before Refactoring

Temporary Backup

Debug Version
```

Once finished,

you can delete them.

---

###### When Should We Use Annotated Tags?

Official releases.

Examples

```text
v1.0

v2.0

v3.1

Production Release

Customer Release
```

---

###### Comparison Table

| Feature              | Lightweight Tag   | Annotated Tag     |
| -------------------- | ----------------- | ----------------- |
| Stores tag name      | ✅ Yes             | ✅ Yes             |
| Points to a commit   | ✅ Yes             | ✅ Yes             |
| Tagger name          | ❌ No              | ✅ Yes             |
| Email                | ❌ No              | ✅ Yes             |
| Date                 | ❌ No              | ✅ Yes             |
| Message              | ❌ No              | ✅ Yes             |
| GPG Signature        | ❌ No              | ✅ Yes (optional)  |
| Stored as Git object | ❌ No              | ✅ Yes             |
| Best for             | Temporary markers | Official releases |

---

###### Commands Summary

| Command                                     | Purpose                  |
| ------------------------------------------- | ------------------------ |
| `git tag`                                   | List all tags            |
| `git tag v1.0`                              | Create a lightweight tag |
| `git tag -a v1.0 -m "First Stable Release"` | Create an annotated tag  |
| `git show v1.0`                             | Show details about a tag |

---

###### Memory Trick

Think of tags like labels on a product.

* **Lightweight Tag** = A simple sticker that says **"v1.0"**.
* **Annotated Tag** = A complete product label that includes:

  * Version (`v1.0`)
  * Manufacturer (Tagger)
  * Date of release
  * Description ("First Stable Release")
  * Optional digital signature

Because annotated tags preserve this additional information, they are the standard choice for **official software releases**, while lightweight tags are convenient for **temporary or personal markers** during development.

###### Tagging Later
Excellent! This is a feature you'll use quite often in real projects because **developers sometimes forget to create a tag when they release software**.

Let's understand it from scratch with a **real software company example**.

---

###### What is "Tagging Later"?

Normally, after making a release, you create a tag.

Example:

```text
Commit A

↓

Commit B

↓

Commit C ← v1.0
```

But sometimes developers forget.

Days or weeks later they realize,

> "Oops! Commit C was actually Version 1.0."

Git allows you to **go back in history and add a tag to an old commit**.

This is called **Tagging Later**.

---

###### Real-Time Company Example

Imagine you work at **ABC Technologies**.

You're developing an **ESP32 Smart Home System**.

During one month, you make several commits.

```text
Commit A
Project Created

↓

Commit B
WiFi Added

↓

Commit C
MQTT Added

↓

Commit D
OLED Added

↓

Commit E
Bug Fixed

↓

Commit F
Bluetooth Added
```

---

###### What Actually Happened

When you completed **Commit C**, the software was stable.

The company released it to customers.

That should have been

```text
v1.0
```

But everyone forgot to create the tag.

Development continued.

---

Two weeks later your manager asks:

> "Can you give me Version 1.0?"

You suddenly remember:

> "Version 1.0 was Commit C."

Luckily Git stores the complete history.

So you can still tag it.

---

###### Step 1 - View Commit History

Run

```bash
git log --oneline
```

Example output

```text
a12f345 Added Bluetooth

b34d678 Fixed OLED bug

9fceb02 Added MQTT

5de8901 Added WiFi

234abcd Initial Project
```

Notice

The MQTT commit has

```text
9fceb02
```

This is the commit hash.

---

###### What is a Commit Hash?

Every commit has a unique ID.

Example

```text
Commit

↓

9fceb02d0ae598e95dc970b74767f19372d61af8
```

Usually,

Git allows us to use only the first few characters.

```text
9fceb02
```

This is enough because it is unique.

---

###### Step 2 - Create a Tag on That Commit

Command

```bash
git tag -a v1.0 9fceb02 -m "First Stable Release"
```

Let's understand every part.

---

###### git

Run Git.

---

###### tag

Create a tag.

---

###### -a

Create an Annotated Tag.

---

###### v1.0

Tag name.

---

###### 9fceb02

The commit where the tag should point.

---

###### -m

Tag message.

---

###### Visual Diagram

Before

```text
Commit A

↓

Commit B

↓

Commit C

↓

Commit D

↓

Commit E
```

After

```text
Commit A

↓

Commit B

↓

Commit C ← v1.0

↓

Commit D

↓

Commit E
```

Notice

The latest commit is still

```text
Commit E
```

Nothing moved.

Only a label was added.

---

###### Important Point

Git **does not create a new commit**.

Git simply says

> "Commit C should now also be known as v1.0."

---

###### Think Like a Student

Imagine you finished your notebook.

Later your teacher says

> "Mark Chapter 5 because it's important."

You don't rewrite the notebook.

You simply attach a sticker.

```text
Chapter 5

⭐ Important
```

Git behaves exactly the same way.

---

###### Another Real-Life Example

Suppose you're developing a **Mobile Banking App**.

History

```text
Commit A

Login Screen

↓

Commit B

Money Transfer

↓

Commit C

Bug Fix

↓

Commit D

Dark Theme

↓

Commit E

Fingerprint Login
```

After six months,

Bank manager says

> "Customers are using Version 2.0."

You remember

Version 2.0 was actually

```text
Commit C
```

Run

```bash
git tag -a v2.0 <commit-id> -m "Production Release"
```

Now

```text
Commit C ← v2.0
```

Even though you're currently working on Commit E.

---

###### Viewing the Tag

Run

```bash
git show v1.0
```

Output

```text
Tag

v1.0

Tagger

Chandu

Date

15 July

Message

First Stable Release

↓

Commit

Added MQTT
```

Git first shows

* Tag Information

Then

* Commit Information

---

###### Does Tagging Later Change My Files?

No.

Suppose you're currently on

```text
Commit F
```

After creating

```text
v1.0
```

your project is still

```text
Commit F
```

Nothing changes.

Only Git now remembers

```text
v1.0

↓

Commit C
```

---

###### Visual Timeline

```text
Today

Commit A

↓

Commit B

↓

Commit C

↓

Commit D

↓

Commit E

↓

Commit F (Current)
```

After tagging

```text
Commit A

↓

Commit B

↓

Commit C ← v1.0

↓

Commit D

↓

Commit E

↓

Commit F (Current)
```

Notice

Current work stays exactly the same.

---

###### Why Is This Useful?

Imagine your customer reports:

> "There is a bug in Version 1.0."

Without tags,

you must search through hundreds of commits.

With tags,

Git immediately knows

```text
v1.0

↓

Commit C
```

You can inspect exactly what the customer was using.

---

###### Summary Table

| Command                                    | Purpose                                                 |
| ------------------------------------------ | ------------------------------------------------------- |
| `git log --oneline`                        | Show commit history with short commit IDs               |
| `git tag -a v1.0 <commit-id> -m "message"` | Create an annotated tag on an older commit              |
| `git show v1.0`                            | Display the tag information and the commit it points to |
| `git tag`                                  | List all tags                                           |

---

###### Complete Workflow

```text
1. View commit history

git log --oneline

        │
        ▼

2. Find the commit where the release happened

9fceb02

        │
        ▼

3. Create the tag

git tag -a v1.0 9fceb02 -m "First Stable Release"

        │
        ▼

4. Verify it

git show v1.0
```

---

###### Memory Trick

Think of **Tagging Later** like **labeling an old photograph**.

Imagine you have a photo album from last year. You forgot to write "Birthday Party" under one photo. Today, you go back to that old photo and add the label.

* 📷 **Old photo** = Old commit
* 🏷️ **Label ("Birthday Party")** = Git tag
* 📖 **Photo album** = Git history

You **don't change the photo**—you simply add a meaningful label to it.

Git's **Tagging Later** works exactly the same way: it lets you attach a tag to any previous commit in your project's history without changing the commits themselves.
###### sharing tags and checking out tags
Excellent! This topic completes the **Git Tag** concept. We'll cover two parts:

1. **Sharing Tags** (sending tags to GitHub)
2. **Checking Out Tags** (viewing old versions)

I'll explain them with a **real software company example**.

---

###### Part 1: Sharing Tags

###### Why Do We Need to Share Tags?

Suppose you created a tag locally.

```bash
git tag -a v1.0 -m "First Stable Release"
```

Now your local repository looks like this.

```text
Your Laptop

Commit A

↓

Commit B

↓

Commit C ← v1.0
```

But GitHub still looks like

```text
GitHub

Commit A

↓

Commit B

↓

Commit C
```

Notice

GitHub **does not know about your tag**.

Only your laptop knows.

---

###### Why?

Because

```bash
git push
```

pushes **commits**, **not tags**.

Many beginners think

```bash
git push origin master
```

also pushes tags.

It does **not**.

---

###### Real-Time Example

Imagine you're working at **ABC Technologies**.

You release version

```text
v1.0
```

You create the tag.

```bash
git tag -a v1.0 -m "Production Release"
```

Only your computer knows

```text
v1.0
```

Your teammate Rahul clones the project.

He runs

```bash
git tag
```

Output

```text
(no tags)
```

Why?

Because you never uploaded the tag.

---

###### How to Share One Tag

Command

```bash
git push origin v1.0
```

Let's understand it.

---

###### git

Run Git.

---

###### push

Upload something.

---

###### origin

Upload to GitHub.

---

###### v1.0

Upload this tag.

---

Now

```text
Your Laptop

v1.0

      │
      │ Upload
      ▼

GitHub

v1.0
```

Now everyone who clones the repository can see

```text
v1.0
```

---

###### Visual Diagram

Before

```text
Your Laptop

Commit C ← v1.0



GitHub

Commit C
```

Run

```bash
git push origin v1.0
```

After

```text
Your Laptop

Commit C ← v1.0



GitHub

Commit C ← v1.0
```

---

###### Pushing All Tags

Suppose your project has

```text
v1.0

v1.1

v2.0

v2.1
```

Instead of pushing one by one,

run

```bash
git push origin --tags
```

Git uploads

```text
v1.0

v1.1

v2.0

v2.1
```

all together.

---

###### Real-Life Analogy

Imagine you have four certificates.

```text
Certificate 1

Certificate 2

Certificate 3

Certificate 4
```

Uploading one

```text
Certificate 1
```

is like

```bash
git push origin v1.0
```

Uploading the entire folder

is like

```bash
git push origin --tags
```

---

###### Summary

```bash
git push origin v1.0
```

Uploads one tag.

```bash
git push origin --tags
```

Uploads every local tag that doesn't already exist on the remote.

---

###### Part 2: Checking Out Tags

Now suppose

one year later

a customer reports

> "Version 2.0 has a bug."

Your current project is

```text
Commit G
```

But

Version 2.0 was

```text
Commit D
```

How can you see that old version?

Use

```bash
git checkout v2.0
```

---

###### What Happens?

Git moves your project back to

```text
Commit D
```

Now all project files become exactly how they were when

```text
v2.0
```

was released.

---

###### Visual Diagram

Current

```text
Commit A

↓

Commit B

↓

Commit C

↓

Commit D ← v2.0

↓

Commit E

↓

Commit F

↓

Commit G ← Current
```

Run

```bash
git checkout v2.0
```

Git temporarily shows

```text
Commit D
```

---

###### Real-Life Example

Imagine Microsoft released

```text
Windows 10

↓

Windows 11
```

Suppose engineers want to inspect

Windows 10.

They don't delete Windows 11.

They simply open the old version.

Git behaves the same way.

---

###### Detached HEAD

When you checkout a tag,

Git shows

```text
Detached HEAD
```

Students often get scared.

Let's understand it.

---

###### Normal Situation

Usually

HEAD points to a branch.

Example

```text
HEAD

↓

master

↓

Commit G
```

Everything is normal.

---

###### After Checkout Tag

```bash
git checkout v2.0
```

Now

```text
HEAD

↓

Commit D
```

Notice

HEAD is pointing directly to a commit.

Not to a branch.

This is called

```text
Detached HEAD
```

---

###### Why is This a Problem?

Suppose you edit

```text
main.c
```

and commit.

```text
Commit D

↓

Commit H
```

But

there is **no branch pointing to Commit H**.

Only

HEAD knows.

If you later switch back to

```text
master
```

Git will no longer have a branch pointing to Commit H. Unless you remember its commit hash or create a branch, that work can become hard to reach.

---

###### Real-Life Analogy

Imagine reading an old chapter in a book.

You write notes on a loose sheet of paper.

If you don't put the sheet back into the book,

it can easily be lost.

Detached HEAD is similar.

---

###### Correct Way to Fix an Old Version

Suppose customers report

Version

```text
v2.0
```

has a bug.

Instead of

```bash
git checkout v2.0
```

and editing,

create a branch.

```bash
git checkout -b version2 v2.0
```

Let's understand it.

---

###### checkout

Move somewhere.

---

###### -b

Create a new branch.

---

###### version2

New branch name.

---

###### v2.0

Start this branch from the tag.

---

Now

```text
Commit D ← v2.0

↓

version2
```

Your new commits will belong to the `version2` branch, so they won't be lost.

---

###### Visual Diagram

Before

```text
Commit D ← v2.0
```

After

```text
Commit D ← v2.0

↓

Commit E

↓

Commit F

↓

version2
```

The original tag

```text
v2.0
```

still points to **Commit D**.

The new branch moves forward with your fixes.

---

###### Real Company Example

Suppose your company released

```text
Smart Home System

v2.0
```

Customers found a bug.

Engineers do

```bash
git checkout -b hotfix-v2 v2.0
```

Fix the bug.

Commit.

Now

```text
v2.0
```

remains unchanged,

while

```text
hotfix-v2
```

contains the fixes.

---

###### Complete Workflow

###### Create Tag

```bash
git tag -a v2.0 -m "Production Release"
```

↓

###### Upload Tag

```bash
git push origin v2.0
```

↓

###### View Old Version

```bash
git checkout v2.0
```

↓

###### Need to Fix It?

Create a branch

```bash
git checkout -b hotfix-v2 v2.0
```

↓

Commit your fixes safely.

---

###### Summary Table

| Command                         | Purpose                                                                     |
| ------------------------------- | --------------------------------------------------------------------------- |
| `git push origin v1.0`          | Push a single tag to the remote                                             |
| `git push origin --tags`        | Push all local tags to the remote                                           |
| `git checkout v2.0`             | View the project exactly as it was at tag `v2.0` (detached HEAD)            |
| `git checkout -b version2 v2.0` | Create a new branch starting from tag `v2.0` so you can safely make changes |

---

###### Memory Trick

Think of a **tag as a photograph of your project at release time**.

* 📸 **Tag** = A photo of the project at a specific moment.
* 👀 **`git checkout v2.0`** = Open that old photo and look around. You can inspect it, but you're not working on a normal branch.
* 🌿 **`git checkout -b hotfix-v2 v2.0`** = Make a copy of that photo into a new album (branch) so you can edit and add new photos without changing the original.

Similarly:

* **`git push origin v1.0`** = Share one labeled release with everyone.
* **`git push origin --tags`** = Share all your release labels with everyone at once.
Great question. The entire section on **Sharing Tags** and **Checking Out Tags** exists because of a few common real-world problems developers face.

Let's understand the **problems first**, then the solutions.

---

###### Problem 1: "I created a tag, but my teammates can't see it."

###### Real-time Example

You work at **ABC Technologies**.

You release your software.

```text
Commit A

↓

Commit B

↓

Commit C ← v1.0
```

You create the tag.

```bash
git tag -a v1.0 -m "First Stable Release"
```

On **your laptop**, everything looks fine.

```text
Your Laptop

Commit C ← v1.0
```

But GitHub looks like

```text
GitHub

Commit C
```

No tag exists there.

Your teammate Rahul clones the repository.

He runs

```bash
git tag
```

Output

```text
(no tags)
```

###### Why?

Because **Git does not automatically push tags**.

It only pushes commits.

###### Solution

Upload the tag explicitly.

```bash
git push origin v1.0
```

or

```bash
git push origin --tags
```

Now everyone can see the tag.

---

###### Problem 2: "I need an older released version."

###### Real-time Example

Suppose today your project looks like

```text
Commit A

↓

Commit B

↓

Commit C ← v1.0

↓

Commit D

↓

Commit E

↓

Commit F
```

A customer says:

> "Our factory is still using Version 1.0. Please check it."

But your current code is

```text
Commit F
```

How can you see exactly what Version 1.0 looked like?

###### Solution

```bash
git checkout v1.0
```

Git temporarily shows the files exactly as they were at Version 1.0.

---

###### Problem 3: "I found a bug in Version 1.0 and need to fix it."

After checking out the tag

```bash
git checkout v1.0
```

you fix the bug.

You commit.

Now a problem appears.

Why?

Because you are **not on a branch**.

You're only looking at an old snapshot.

Your new commit has no branch pointing to it.

This is called **Detached HEAD**.

---

###### Visual

Normal situation

```text
master

↓

Commit F
```

After

```bash
git checkout v1.0
```

```text
HEAD

↓

Commit C
```

Notice

There is no branch.

---

###### Why is this dangerous?

Suppose you commit.

```text
Commit C

↓

Commit G
```

Then you switch back.

```bash
git checkout master
```

Now

```text
master

↓

Commit F
```

No branch points to **Commit G**.

Unless you remember its hash or create a branch, that work can become difficult to find later.

---

###### Solution

Instead of

```bash
git checkout v1.0
```

use

```bash
git checkout -b hotfix-v1 v1.0
```

Now

```text
Commit C ← v1.0

↓

Commit G

↓

hotfix-v1
```

Your bug fix belongs to a proper branch.

Nothing is lost.

---

###### Summary of the Problems

| Problem                       | Why it happens                        | Solution                                            |
| ----------------------------- | ------------------------------------- | --------------------------------------------------- |
| My teammates can't see my tag | Tags are local by default             | `git push origin <tag>` or `git push origin --tags` |
| I need to see an old release  | Current branch has newer code         | `git checkout <tag>`                                |
| I need to fix an old release  | A tag is just a pointer, not a branch | `git checkout -b <new-branch> <tag>`                |

###### Easy Memory Trick

Imagine you're writing a book.

* **Tag** = A bookmark placed on an important chapter.
* **Push tag** = Photocopy that bookmark and send it to everyone else.
* **Checkout tag** = Open the book directly to that bookmarked chapter.
* **Create a branch from a tag** = Make a photocopy of that chapter so you can edit it without changing the original bookmarked version.
##### Git Aliases
This is exactly why these Git features exist: to **share release markers**, **view old releases**, and **safely fix old versions** without affecting the original release.
Excellent! **Git Aliases** are one of the biggest time-savers in Git. Many professional developers use them every day.

Let's understand them from **scratch** with **real-time examples**.

---

###### First, What Problem Are Aliases Solving?

Imagine you work in an embedded systems company.

Every day you type commands like

```bash
git status
git commit
git checkout
git branch
git log
```

Suppose you do this **100 times every day**.

Typing long commands again and again becomes repetitive.

For example,

```bash
git status
```

has 10 characters after `git`.

Instead, wouldn't it be easier if you could simply type

```bash
git st
```

and Git understood that you meant `git status`?

That's exactly what **Git aliases** do.

---

###### Real-Life Example

Imagine your friend's full name is

```text
Chandrasekhar Reddy
```

But every day you simply call him

```text
Chandu
```

Both refer to the same person.

```
Chandu
     │
     ▼
Chandrasekhar Reddy
```

An **alias** is just a **nickname**.

Git aliases work exactly the same way.

---

###### What is a Git Alias?

A Git alias is simply a **shortcut** for another Git command.

Example

```
st

↓

status
```

or

```
co

↓

checkout
```

Git automatically replaces the alias with the full command.

---

###### Without Aliases

Suppose you want to check the project status.

Every time you type

```bash
git status
```

---

###### With Aliases

Create an alias

```bash
git config --global alias.st status
```

Now you can simply type

```bash
git st
```

Git internally converts it into

```bash
git status
```

You type less, Git does the rest.

---

###### How Does Git Know?

When you run

```bash
git config --global alias.st status
```

Git stores this in your global configuration.

It is like creating a small dictionary.

```
st

↓

status
```

Whenever Git sees

```bash
git st
```

it thinks

> "Oh! `st` means `status`."

Then it runs

```bash
git status
```

---

###### Visual Diagram

```
You type

git st

      │

Git checks aliases

      │

st → status

      │

Git executes

git status
```

---

###### Example 1 - Status

Create alias

```bash
git config --global alias.st status
```

Now

Instead of

```bash
git status
```

you simply write

```bash
git st
```

Same output.

---

###### Example 2 - Commit

Normally

```bash
git commit
```

Create alias

```bash
git config --global alias.ci commit
```

Now

```bash
git ci
```

Git executes

```bash
git commit
```

---

###### Example 3 - Checkout

Normally

```bash
git checkout
```

Create alias

```bash
git config --global alias.co checkout
```

Now

```bash
git co main
```

Git actually runs

```bash
git checkout main
```

---

###### Example 4 - Branch

Normally

```bash
git branch
```

Create

```bash
git config --global alias.br branch
```

Now

```bash
git br
```

means

```bash
git branch
```

---

###### Example 5 - Last Commit

Suppose every morning you want to see your most recent commit.

Normally

```bash
git log -1 HEAD
```

This is long.

Create an alias

```bash
git config --global alias.last "log -1 HEAD"
```

Now

```bash
git last
```

Git internally executes

```bash
git log -1 HEAD
```

Very convenient.

---

###### Real-Time Company Example

Suppose you work on an ESP32 firmware project.

Every day your workflow is

```bash
git status

git add .

git commit

git push
```

Instead you create aliases.

```bash
git config --global alias.st status
git config --global alias.ci commit
git config --global alias.co checkout
git config --global alias.br branch
```

Now your work becomes

```bash
git st

git add .

git ci

git push
```

Much faster.

---

###### Creating Your Own Commands

Git aliases are not limited to shortening commands.

You can create commands that **don't exist**.

Example

Suppose beginners often forget

```bash
git reset HEAD --
```

to unstage a file.

You can create

```bash
git config --global alias.unstage "reset HEAD --"
```

Now

Instead of

```bash
git reset HEAD -- file1.txt
```

you simply write

```bash
git unstage file1.txt
```

Git converts it into

```bash
git reset HEAD -- file1.txt
```

This makes the command easier to remember.

---

###### Visual Diagram

```
You type

git unstage notes.md

        │

Git Alias

unstage

↓

reset HEAD --

        │

Git Executes

git reset HEAD -- notes.md
```

---

###### External Commands with `!`

Aliases can also run **programs outside Git**.

Normally, Git aliases execute Git subcommands.

But if an alias starts with `!`, Git runs it as a shell command.

Example

```bash
git config --global alias.visual "!gitk"
```

Now

```bash
git visual
```

Git runs

```bash
gitk
```

`gitk` is a graphical application that lets you browse your Git history.

---

###### Another Example

Suppose you often list files.

You could create

```bash
git config --global alias.files "!ls"
```

Now

```bash
git files
```

runs

```bash
ls
```

Here `ls` is **not a Git command**—it's a shell command. That's why the `!` is needed.

---

###### Where Are Aliases Stored?

When you use

```bash
git config --global
```

Git saves the aliases in your global Git configuration file.

On Linux/macOS:

```text
~/.gitconfig
```

On Windows:

```text
C:\Users\<YourName>\.gitconfig
```

A typical section looks like this:

```ini
[alias]
    st = status
    co = checkout
    ci = commit
    br = branch
    last = log -1 HEAD
```

---

###### View All Your Aliases

To see your Git configuration (including aliases):

```bash
git config --global --list
```

You might see:

```text
alias.st=status
alias.co=checkout
alias.ci=commit
alias.br=branch
alias.last=log -1 HEAD
```

---

###### Summary Table

| Command                   | Alias Created                   | Use It As              |
| ------------------------- | ------------------------------- | ---------------------- |
| `git status`              | `alias.st status`               | `git st`               |
| `git checkout`            | `alias.co checkout`             | `git co`               |
| `git branch`              | `alias.br branch`               | `git br`               |
| `git commit`              | `alias.ci commit`               | `git ci`               |
| `git log -1 HEAD`         | `alias.last "log -1 HEAD"`      | `git last`             |
| `git reset HEAD --`       | `alias.unstage "reset HEAD --"` | `git unstage file.txt` |
| `gitk` (external program) | `alias.visual "!gitk"`          | `git visual`           |

---

###### Complete Workflow

```
Create Alias

git config --global alias.st status

          │
          ▼

Saved in ~/.gitconfig

st → status

          │
          ▼

You Type

git st

          │
          ▼

Git Replaces It With

git status

          │
          ▼

Command Executes
```

---

###### Memory Trick

Think of **Git aliases as contacts in your phone**.

* Your friend's full name might be **"Chandrasekhar Reddy"**, but you save it as **"Chandu"**.
* When you tap **"Chandu"**, your phone calls the correct person.

Similarly:

* `git st` → `git status`
* `git co` → `git checkout`
* `git ci` → `git commit`

The alias is just a **short nickname**. Git automatically expands it to the full command before executing it. This saves typing while producing exactly the same result.
##### Branching
This is one of the **most important concepts in Git**. Once you understand branching, you'll understand why companies like **Google, Microsoft, Amazon, Tesla, Meta**, and almost every software company use Git.

I'll explain it from **scratch**, assuming you've never heard of branches before.

---

###### First, What Problem Does Branching Solve?

Imagine you work as an Embedded Software Engineer at **ABC Technologies**.

Your team develops firmware for an **ESP32 Smart Home System**.

Current software:

```text
Version 1.0

✓ WiFi
✓ MQTT
✓ OLED
✓ Sensor Reading
```

The customers are happily using this software.

Now your manager gives you **three new tasks**.

```
Task 1
Add Bluetooth

Task 2
Fix WiFi Bug

Task 3
Add Mobile App Support
```

###### Question

Should you start changing the main project directly?

Imagine you do.

```
Version 1.0

↓

Bluetooth code (half finished)

↓

Bug Fix (not completed)

↓

Mobile App (not working)
```

Now suppose a customer reports

> "Our system crashed. We need the stable version immediately."

Oops...

Your main project is already full of unfinished work.

This is a huge problem.

---

###### Real-Life Example

Think about writing your **college project report**.

You have already submitted the final version.

Now your professor says

> "Try adding a new chapter."

Would you edit the original submitted report?

No.

You first make a copy.

```
Original Report
        │
        ├──────────────► Copy
                             │
                             │
                       Add New Chapter
                       Delete Paragraphs
                       Make Changes
```

If everything looks good,

you replace the original.

Git Branches work exactly like this.

---

###### What is a Branch?

A branch is simply

> **An independent line of development.**

It allows you to work on new features without affecting the main project.

---

###### Visual

Without Branches

```
Main Project

↓

Add Bluetooth

↓

Half Finished

↓

Broken Code

↓

Customers Can't Use It
```

Bad idea.

---

With Branches

```
Main Branch

↓

Stable Version

        │

        ├─────────────► Bluetooth Branch

        │                 Work safely

        │                 Test

        │                 Fix Bugs

        │

        └─────────────► WiFi Bug Branch

                          Fix WiFi
```

The main project always remains stable.

---

###### Why Is Git Branching Special?

Many older Version Control Systems worked like this.

```
Project

↓

Copy Entire Folder

↓

50 MB
```

Need another branch?

```
Copy Again

↓

Another 50 MB
```

Need another?

```
Copy Again

↓

Another 50 MB
```

Every branch required copying the whole project.

For large projects this was slow and wasted storage.

---

Git does something completely different.

Instead of copying files,

Git simply creates another **pointer**.

Imagine your project history.

```
Commit A

↓

Commit B

↓

Commit C
```

Master branch

```
master

↓

Commit C
```

Creating a new branch doesn't copy the project.

Git simply creates another pointer.

```
master

↓

Commit C

feature

↓

Commit C
```

That's all.

Creating a branch takes almost no time.

---

###### Why Is It Called a Branch?

Imagine a tree.

```
          Tree

            │

            │

        Main Trunk

            │

      ──────────────

      │            │

 Small Branch   Small Branch
```

The trunk continues.

The branch grows independently.

Git behaves exactly like this.

```
Main Development

↓

Commit A

↓

Commit B

↓

Commit C

          │

          │

          └──────── Bluetooth Feature
```

---

###### Understanding Git Internally

Before branching,

let's understand what Git stores.

Many beginners think Git stores

```
Version 1

Version 2

Version 3

Version 4
```

Actually,

Git stores **snapshots**.

---

###### What is a Snapshot?

Suppose your folder contains

```
Project

README.md

main.c

wifi.c
```

You commit.

Git stores

```
Snapshot 1

README.md

main.c

wifi.c
```

Now you change

```
wifi.c
```

Commit again.

Git stores another snapshot.

```
Snapshot 2

README.md

main.c

wifi.c (updated)
```

Git is remembering

> "This is exactly how the project looked at this moment."

---

###### Real-Life Example

Think of taking photos.

Monday

📷

```
Family
```

Tuesday

📷

```
Family + Dog
```

Wednesday

📷

```
Family + Dog + Car
```

Each photo captures the entire scene at that time.

Git commits work the same way.

---

###### What Happens During Commit?

Suppose your project contains

```
README.md

main.c

wifi.c
```

You run

```bash
git add README.md main.c wifi.c
```

Git prepares these files.

Then

```bash
git commit -m "Initial Commit"
```

Git creates several objects.

---

###### Step 1

Git stores each file separately.

```
README.md

↓

Blob
```

```
main.c

↓

Blob
```

```
wifi.c

↓

Blob
```

A **blob** is Git's way of storing a file's contents.

---

###### Step 2

Git creates a **tree**.

Think of a tree as a folder map.

```
Project Folder

README.md

↓

Blob1

main.c

↓

Blob2

wifi.c

↓

Blob3
```

The tree remembers which filenames point to which blobs.

---

###### Step 3

Git creates the **commit**.

```
Commit

↓

Tree

↓

README Blob

main.c Blob

wifi.c Blob
```

The commit stores metadata too:

* Author
* Email
* Date
* Commit message

---

###### What Happens After Another Commit?

Suppose you change

```
main.c
```

and commit again.

Git creates

```
Commit 2

↓

Tree 2

↓

Updated Blob
```

But Commit 2 also remembers its parent.

```
Commit 1

↓

Commit 2
```

Every normal commit points to the commit before it.

```
Commit A

↓

Commit B

↓

Commit C
```

This chain lets Git reconstruct your project's history.

---

###### What is a Branch Internally?

This is the most important point.

A branch is **not another copy of your project**.

A branch is simply a **pointer** to a commit.

Suppose

```
Commit A

↓

Commit B

↓

Commit C
```

Master

```
master

↓

Commit C
```

That's all.

The branch only remembers

```
Current Commit = Commit C
```

---

###### When You Commit Again

Current situation

```
master

↓

Commit C
```

You create a new commit.

```
Commit D
```

Git automatically moves the pointer.

Before

```
master

↓

Commit C
```

After

```
master

↓

Commit D
```

Notice

Git didn't move all commits.

Only the **branch pointer** moved.

---

###### Why Is This So Fast?

Imagine a bookmark in a book.

Your bookmark is on page 20.

```
📖

Bookmark

↓

Page 20
```

Tomorrow you read to page 40.

Do you photocopy the whole book?

No.

You simply move the bookmark.

```
📖

Bookmark

↓

Page 40
```

That's exactly what Git does.

A branch is like a bookmark pointing to the latest commit.

Creating a new branch is like placing a **second bookmark** in the same book.

---

###### Example

Initially

```
Commit A

↓

Commit B

↓

Commit C

↑

master
```

Create a new branch called `feature`.

```
Commit A

↓

Commit B

↓

Commit C

↑          ↑

master   feature
```

Both branches point to the same commit at first.

Now switch to `feature` and make a new commit.

```
Commit A

↓

Commit B

↓

Commit C

            │

            ▼

        Commit D

↑            ↑

master     feature
```

Notice:

* `master` still points to **Commit C** (stable code).
* `feature` points to **Commit D** (new Bluetooth feature).

The two branches have now **diverged**, allowing independent development.

---

##### Why Companies Love Branches

Suppose a company has different developers working at the same time.

```
Main Branch (Stable)

↓

Version 1.0

        │

        ├──────── Bluetooth Feature

        │

        ├──────── WiFi Bug Fix

        │

        ├──────── Security Patch

        │

        └──────── OLED Improvement
```

Everyone can work independently.

Once a feature is tested, it is **merged** back into the main branch.

---

###### Important Note About `master`

Older Git versions created a default branch named:

```
master
```

Today, many repositories use:

```
main
```

There is **nothing special** about either name. They are just ordinary branch names chosen as the default starting branch.

---

###### Complete Workflow

```
Project Created

        │
        ▼

Initial Commit

        │
        ▼

master

↓

Commit A

        │
        ▼

Create Feature Branch

↓

feature

↓

Commit A

        │
        ▼

Add Bluetooth

↓

Commit B

        │
        ▼

Test

↓

Commit C

        │
        ▼

Merge Into master

↓

Stable Project
```

---

###### Memory Trick

Think of your project as a **tree**:

* 🌳 **Main trunk** = Main (or master) branch
* 🌿 **Side branch** = A new feature or bug fix
* 🍃 **Leaves growing** = New commits on that branch
* 🔗 **Merge** = Joining the side branch back into the main trunk

The key idea to remember is:

> **A Git branch is not a copy of your project—it is just a lightweight pointer to the latest commit.** That's why creating, switching, and deleting branches in Git is extremely fast.

##### createing a new branch 
Excellent! This is where Git branching becomes really interesting. Most beginners get confused by **branch**, **HEAD**, and **pointer**. Let's understand them from **scratch** using **real-life examples**.

---

###### First, What Problem Are We Solving?

Imagine you're working as an **Embedded Engineer** at a company developing an **ESP32 Smart Irrigation System**.

The current software is stable.

```text
Version 1.0

✓ WiFi
✓ MQTT
✓ Temperature Sensor
✓ OLED Display
```

Now your manager gives you a new task:

> **"Add Bluetooth support."**

At the same time, another engineer must fix a WiFi bug.

###### Question

Should both of you edit the same code?

**No!**

Because if your Bluetooth code is only half-finished, it could break the stable version.

So each developer needs their **own working area**.

That's exactly what a **branch** provides.

---

###### Before Creating a Branch

Suppose your commit history looks like this:

```text
Commit A
Initial Project

↓

Commit B
WiFi Added

↓

Commit C
MQTT Added
```

Currently, Git has only one branch:

```text
master

↓

Commit C
```

Think of the branch as a **bookmark**.

It simply says:

> "The latest commit on the master branch is Commit C."

---

###### Creating a New Branch

Command:

```bash
git branch testing
```

Many beginners think this copies the whole project.

❌ It does **not**.

Git simply creates **another pointer**.

Before:

```text
Commit A

↓

Commit B

↓

Commit C

↑

master
```

After:

```text
Commit A

↓

Commit B

↓

Commit C

↑          ↑

master   testing
```

Notice something important:

* Both branches point to the **same commit**.
* No new commit is created.
* No files are copied.

Git only created another bookmark.

---

###### Real-Life Example

Imagine you're reading a textbook.

You already have one bookmark.

```text
Book

↓

Page 120

↑

Bookmark 1 (master)
```

Now you insert another bookmark.

```text
Book

↓

Page 120

↑          ↑

master   testing
```

Did you buy another copy of the book?

No.

You simply added another bookmark.

Git branches work exactly the same way.

---

###### Does `git branch` Switch to the New Branch?

This is a very common misunderstanding.

When you run:

```bash
git branch testing
```

Git **only creates** the branch.

It **does not switch** to it.

You are still on `master`.

---

###### How Does Git Know Which Branch I'm Using?

Git keeps a special pointer called **HEAD**.

Think of **HEAD** as **"Where am I currently working?"**

---

###### Visual

```text
HEAD

↓

master

↓

Commit C
```

HEAD points to **master**.

master points to **Commit C**.

So when you make a new commit, Git knows it belongs to the `master` branch.

---

###### Real-Life Example

Imagine you're in a library.

There are two bookshelves.

```text
Shelf A

Shelf B
```

You are currently standing in front of Shelf A.

```text
You

↓

Shelf A
```

Git thinks similarly.

```text
HEAD

↓

master
```

HEAD always tells Git **which branch you're currently standing on**.

---

###### What Happens After Creating the Branch?

Suppose you run:

```bash
git branch testing
```

Now Git looks like this:

```text
                 HEAD

                  ↓

master ----------------→ Commit C

testing --------------→ Commit C
```

Notice:

* HEAD still points to **master**.
* Both branches point to the same commit.

Nothing else has changed.

---

###### How Can We Check This?

Run:

```bash
git log --oneline --decorate
```

Example output:

```text
f30ab (HEAD -> master, testing)
34ac2 Fixed WiFi Bug
98ca9 Initial Commit
```

Let's understand this line:

```text
f30ab (HEAD -> master, testing)
```

---

###### What Does `HEAD -> master` Mean?

It means:

```text
HEAD

↓

master
```

You are currently working on the `master` branch.

---

###### What Does `testing` Mean?

It means:

```text
testing

↓

Same Commit
```

Both branches currently point to the same commit.

---

###### Visual

```text
Commit A

↓

Commit B

↓

Commit C

↑          ↑

master   testing

↑

HEAD
```

Everything points to Commit C.

---

###### What Happens If You Commit Now?

Since HEAD points to `master`:

```text
HEAD

↓

master

↓

Commit C
```

You make a new commit:

```bash
git commit -m "Add Bluetooth"
```

Git creates Commit D.

Now:

```text
Commit A

↓

Commit B

↓

Commit C

↓

Commit D

↑

master

↑

HEAD


testing

↓

Commit C
```

Notice:

* `master` moved to Commit D.
* `testing` stayed at Commit C.

Branches move **only when you are on them**.

---

###### Real-Time Company Example

Suppose two developers are working.

###### Developer 1 (You)

Current branch:

```text
master
```

You create:

```bash
git branch bluetooth
```

Now:

```text
master

↓

Commit C

bluetooth

↓

Commit C
```

###### Developer 2

Creates:

```bash
git branch wifi-fix
```

Now:

```text
master

↓

Commit C

bluetooth

↓

Commit C

wifi-fix

↓

Commit C
```

Each developer has an independent starting point.

Later, they switch to their own branches and continue development.

---

###### Why Is This So Fast?

Older version control systems often copied the entire project to create a branch.

For a large project, that could mean copying gigabytes of data.

Git does something much simpler:

Before:

```text
master → Commit C
```

After:

```text
master → Commit C

testing → Commit C
```

Creating a branch is just creating **another pointer**, so it's almost instantaneous.

---

###### Summary Table

| Command                           | What It Does                         |
| --------------------------------- | ------------------------------------ |
| `git branch testing`              | Creates a new branch named `testing` |
| Does it copy the project?         | ❌ No                                 |
| Does it create a new commit?      | ❌ No                                 |
| Does it switch to the new branch? | ❌ No                                 |
| What changes?                     | ✅ A new branch pointer is created    |

---

###### Complete Workflow

```text
Current Repository

Commit A

↓

Commit B

↓

Commit C

↑

master

↑

HEAD


Run

git branch testing


Repository After

Commit A

↓

Commit B

↓

Commit C

↑          ↑

master   testing

↑

HEAD
```

Nothing has moved except that Git added a **new branch pointer**.

---

###### Memory Trick

Think of your Git history as a **book**:

* 📖 **Commits** = Pages in the book.
* 🔖 **Branch** = A bookmark showing an important page.
* 👀 **HEAD** = Your eyes, telling Git **which bookmark you're currently reading**.

When you run:

```bash
git branch testing
```

you are **not making another book**. You are simply placing **another bookmark on the same page**. Since your eyes (HEAD) are still looking at the `master` bookmark, any new commits will continue to move the `master` bookmark until you explicitly switch to the `testing` branch.

##### switching branches
No problem. This section is confusing because the Git book explains it from Git's internal perspective. Let's ignore the book for a moment and learn it like a story.

---

###### Real-Time Example: You Work in an Embedded Company

Suppose you are developing an **ESP32 Smart Irrigation System**.

Yesterday your project looked like this:

```text
Commit A
Project Started

↓

Commit B
WiFi Added

↓

Commit C
MQTT Added
```

Currently you are on the **master** branch.

```text
HEAD
 ↓
master
 ↓
Commit C
```

This means:

* **HEAD** = "Where am I working?"
* HEAD says: "I am working on **master**."

---

###### Step 1: Create a New Branch

You type:

```bash
git branch testing
```

Now Git creates another branch.

```text
                HEAD
                 ↓
master ----------------→ Commit C

testing --------------→ Commit C
```

Notice:

* `master` → Commit C
* `testing` → Commit C
* **HEAD is still on master**

You have **not switched** yet.

---

###### Step 2: Switch to the Testing Branch

Now type:

```bash
git checkout testing
```

What changes?

Only **HEAD** moves.

Before:

```text
HEAD
 ↓
master
```

After:

```text
HEAD
 ↓
testing
```

Now the picture is:

```text
master  ------------→ Commit C

testing -----------→ Commit C
                      ↑
                    HEAD
```

**Very important:** Nothing happened to the commits. Only HEAD moved.

---

###### Step 3: Make a New Commit

Now you add Bluetooth support.

```bash
git commit -m "Added Bluetooth"
```

Git asks:

> "Which branch should I update?"

It looks at **HEAD**.

HEAD says:

> "I am on testing."

So Git creates a new commit.

```text
Commit A

↓

Commit B

↓

Commit C

↓

Commit D
```

Now Git moves **only the testing branch**.

```text
master  ------------→ Commit C

testing -----------→ Commit D
                      ↑
                    HEAD
```

Notice carefully.

Did **master** move?

❌ No.

Only **testing** moved.

---

###### Why Didn't Master Move?

Because **HEAD was not on master**.

Think of HEAD like your pen.

Wherever your pen is, that's where you write.

If your pen is on the testing notebook,

you write only in the testing notebook.

---

###### Step 4: Switch Back to Master

Now type:

```bash
git checkout master
```

HEAD moves again.

```text
master ------------→ Commit C
                     ↑
                   HEAD

testing ----------→ Commit D
```

Now something interesting happens.

---

###### Your Files Change Automatically

On the **testing** branch you had Bluetooth code.

```c
main.c

WiFi
MQTT
Bluetooth
OLED
```

When you switch to **master**:

```bash
git checkout master
```

Git changes your files automatically.

Now your project becomes

```c
main.c

WiFi
MQTT
OLED
```

Bluetooth disappears.

Did Git delete your Bluetooth code?

❌ No.

It still exists on the **testing** branch.

You just aren't looking at that branch anymore.

---

###### Real-Life Example

Imagine you have **two notebooks**.

###### Notebook 1 (master)

```text
Math

Chapter 1

Chapter 2
```

###### Notebook 2 (testing)

```text
Math

Chapter 1

Chapter 2

Chapter 3
```

When you pick Notebook 1,

you don't see Chapter 3.

When you pick Notebook 2,

you see Chapter 3.

The chapter wasn't deleted.

You simply changed notebooks.

Git branches work exactly like this.

---

###### Step 5: Work on Master

Suppose your manager now says:

> "Forget Bluetooth. Customers have a WiFi bug."

You stay on **master** and fix WiFi.

```bash
git commit -m "Fixed WiFi Bug"
```

Git creates another commit.

```text
                Commit D
             (Bluetooth)

                 ↑
              testing

               /

Commit A

↓

Commit B

↓

Commit C

↓

Commit E
 (WiFi Fix)

↑
master

↑
HEAD
```

Now both branches have different histories.

This is called **diverging**.

---

###### What Does "Diverged" Mean?

Both branches started together.

```text
Commit C
```

Then they went in different directions.

```text
Commit A

↓

Commit B

↓

Commit C

      /        \

     /          \

Commit D      Commit E

Bluetooth     WiFi Fix

testing       master
```

Think of it like a road.

```text
           City

             |

             |

         Main Road

             |

       Traffic Signal

         /          \

Bluetooth Road   WiFi Road
```

The road split into two directions.

That's exactly what Git branches do.

---

###### Understanding the Git Log Output

The book shows:

```text
* c2b9e (HEAD -> master) made other changes
| * 87ab2 (testing) made a change
|/
* f30ab Added MQTT
* 34ac2 Added WiFi
* 98ca9 Initial commit
```

Let's decode it.

###### Bottom

```text
* 98ca9 Initial commit
```

Project started.

↓

```text
* 34ac2 Added WiFi
```

↓

```text
* f30ab Added MQTT
```

Everything is common up to here.

Now Git split.

```text
| * 87ab2 (testing)
```

This is the **testing** branch.

While

```text
* c2b9e (HEAD -> master)
```

is the **master** branch.

HEAD is pointing to master because you're currently working there.

---

###### Why Are Branches So Fast?

Many beginners think:

> "Creating a branch copies the whole project."

Git does **not** copy the project.

Internally, a branch is just a tiny file containing the latest commit ID.

For example:

```text
master
↓

Commit C
```

might simply be stored as:

```text
f30ab12345...
```

When you create:

```bash
git branch testing
```

Git creates another tiny file:

```text
testing
↓

f30ab12345...
```

That's why creating a branch takes almost no time.

---

###### The Whole Story in One Diagram

```text
1. Initial

HEAD
 ↓
master
 ↓
A → B → C

────────────────────────────

2. Create Branch

git branch testing

HEAD
 ↓
master
 ↓
A → B → C
         ↑
      testing

────────────────────────────

3. Switch

git checkout testing

HEAD
 ↓
testing
 ↓
A → B → C
         ↑
      master

────────────────────────────

4. Commit

HEAD
 ↓
testing
 ↓
A → B → C → D
         ↑
      master

────────────────────────────

5. Switch Back

git checkout master

HEAD
 ↓
master
 ↓
A → B → C
             \
              D
              ↑
           testing

────────────────────────────

6. Commit Again

HEAD
 ↓
master
 ↓
A → B → C → E
             \
              D
              ↑
           testing
```

###### The three rules you should always remember

1. **`git branch testing`** → Creates a new branch. It **does not switch** to it.
2. **`git checkout testing`** → Switches **HEAD** to the `testing` branch.
3. **`git commit`** → Always adds the new commit to the branch that **HEAD** is currently pointing to.

Once these three rules are clear, branching becomes much easier to understand.

##### Git branching and Merging
This is **the most important chapter in Git**. After learning this, you'll understand **how real software companies like Google, Microsoft, Amazon, and TCS actually use Git every day**.

Don't worry about all the commands at first. We'll learn it as a story.

---

###### The Story

Imagine you work as an **Embedded Software Engineer**.

Your company makes an **ESP32 Smart Home System**.

Current software running in customers' homes:

```text
Version 1.0

✓ WiFi
✓ MQTT
✓ OLED
✓ Sensor Reading
```

This is the **stable version**.

In Git, this stable version is stored in the **master** (or **main**) branch.

```text
master

↓

Version 1.0
```

---

###### Day 1 - Manager Gives You a New Feature

Manager says:

> Add Bluetooth support.

This feature will take **one week**.

Should you directly modify the stable version?

❌ No.

Customers are still using Version 1.0.

So create a new branch.

```bash
git checkout -b bluetooth
```

What does this command do?

It is actually two commands together.

```bash
git branch bluetooth
git checkout bluetooth
```

Meaning

1. Create a branch.
2. Switch to it.

---

Now Git looks like this.

```text
master

↓

Commit C

bluetooth

↓

Commit C

HEAD

↓

bluetooth
```

You are now working only on the **bluetooth** branch.

---

###### Day 2 - You Start Coding

You write Bluetooth code.

```c
Bluetooth_Init();

Bluetooth_Pair();

Bluetooth_Send();
```

Commit.

```bash
git commit -m "Bluetooth Driver Added"
```

Git creates another commit.

```text
master

↓

Commit C


bluetooth

↓

Commit D
```

Notice

Did master move?

❌ No.

Only bluetooth moved.

---

###### Suddenly...

Your manager calls.

📞

> Customer systems have stopped sending emails!

This is an emergency.

Customers cannot wait until Bluetooth is finished.

---

###### Question

Should you continue working on Bluetooth?

❌ No.

Bluetooth is unrelated.

You need to fix the emergency.

---

###### Step 1

Switch back.

```bash
git checkout master
```

Immediately

HEAD moves.

```text
HEAD

↓

master
```

---

###### Something Amazing Happens

Bluetooth code disappears.

Why?

Because master doesn't contain Bluetooth.

Git automatically changes your project files.

Now your project becomes

```text
WiFi

MQTT

OLED

Sensor
```

Exactly how master looked before.

---

###### Step 2

Create another branch.

```bash
git checkout -b hotfix
```

Now

```text
master

↓

Commit C


hotfix

↓

Commit C


bluetooth

↓

Commit D
```

HEAD

↓

hotfix

---

Now fix the bug.

Example

```c
Email_Send();
```

was

```c
Email_Send(NULL);
```

You fix it.

Commit.

```bash
git commit -m "Fixed Email Bug"
```

Now

```text
master

↓

Commit C


hotfix

↓

Commit E
```

---

###### Step 3

Testing Team Says

✅ Bug Fixed

Now you want customers to get this fix immediately.

How?

Merge it into master.

```bash
git checkout master
```

then

```bash
git merge hotfix
```

---

###### What is Merge?

Merge means

> Copy the work from one branch into another.

Think about college notes.

Notebook A

```text
Math

Chapter 1

Chapter 2
```

Notebook B

```text
Math

Chapter 1

Chapter 2

Chapter 3
```

When exams come,

you copy Chapter 3 into Notebook A.

That copying process is called

**Merge**

---

After merge

```text
master

↓

Commit E

hotfix

↓

Commit E
```

Both point to the same commit.

---

###### Fast Forward Merge

The Git book says

> Fast Forward

What does it mean?

Suppose

Initially

```text
Commit A

↓

Commit B

↓

Commit C

↑

master
```

Hotfix

```text
Commit A

↓

Commit B

↓

Commit C

↓

Commit D

↑

hotfix
```

Notice

master never changed.

Only hotfix moved.

Now merge.

Git notices

> "Master has no extra work."

So Git simply moves master forward.

Before

```text
master

↓

Commit C
```

After

```text
master

↓

Commit D
```

No extra commit is created.

Git simply says

> Move master to the latest commit.

Like this.

```text
Before

master

↓

C

↓

D

↑

hotfix
```

After

```text
master

↓

D

↑

hotfix
```

This is called a

###### Fast Forward Merge

Think of a car moving on a straight road.

```text
Road

A ---- B ---- C ---- D
```

master is at C.

Hotfix is at D.

Merge simply moves master from C to D.

No complicated work.

---

###### Step 4

Delete Hotfix

Do we still need it?

No.

master already contains the fix.

Delete it.

```bash
git branch -d hotfix
```

Now

```text
master

↓

Commit D
```

Hotfix disappears.

---

###### Step 5

Continue Bluetooth Work

Switch back.

```bash
git checkout bluetooth
```

Now your Bluetooth code comes back automatically.

You continue coding.

```bash
git commit -m "Bluetooth Pairing Complete"
```

Now

```text
Commit A

↓

Commit B

↓

Commit C

↓

Commit D

↓

Commit F

↑

bluetooth
```

---

###### But Wait...

master is here.

```text
Commit D
```

Bluetooth is here.

```text
Commit F
```

The histories are different.

---

###### This Is Called Diverged History

```text
             Bluetooth

                 F

                /

A

↓

B

↓

C

↓

D

(master)

```

Both branches started together.

Then went in different directions.

Exactly like a road.

```text
            Highway

               |

               |

           Traffic Signal

          /            \

Bluetooth Road     Hotfix Road
```

---

###### Later...

Bluetooth is finished.

Manager says

> Merge Bluetooth into master.

Switch.

```bash
git checkout master
```

Merge.

```bash
git merge bluetooth
```

Now Git sees

Both branches changed.

master changed.

bluetooth changed.

It cannot simply move the pointer.

It has to combine both.

---

###### Three-Way Merge

Git compares three things.

```text
          Common Parent

               C

             /   \

            /     \

master      bluetooth

D              F
```

Git compares

* Common parent
* master
* bluetooth

Then creates a new commit.

```text
             G

            / \

           /   \

          D     F
```

This new commit

```text
G
```

is called a

###### Merge Commit

Because it has **two parents**.

Normal commit

```text
Commit D

↓

Commit C
```

One parent.

Merge commit

```text
          Merge

         /     \

Parent 1   Parent 2
```

Two parents.

---

###### Final History

```text
A

↓

B

↓

C

      \

       D

        \

         G

        /

       F
```

Now master contains

* Bluetooth feature
* Hotfix

Everything.

---

###### Complete Workflow

```text
Start

master

↓

Version 1.0

        │

        ▼

Create bluetooth

↓

Bluetooth Work

↓

Commit

        │

Emergency

↓

Checkout master

↓

Create hotfix

↓

Fix Bug

↓

Commit

↓

Merge Hotfix

↓

Delete Hotfix

↓

Checkout bluetooth

↓

Continue Work

↓

Merge bluetooth

↓

Delete bluetooth
```

---

###### Commands Used in This Workflow

| Command                     | Purpose                                  |
| --------------------------- | ---------------------------------------- |
| `git checkout -b bluetooth` | Create and switch to a new branch        |
| `git checkout master`       | Switch back to master                    |
| `git commit -m "message"`   | Save changes                             |
| `git merge hotfix`          | Merge the hotfix into the current branch |
| `git branch -d hotfix`      | Delete the hotfix branch after merging   |
| `git merge bluetooth`       | Merge the completed feature into master  |

---

###### The One Idea to Remember

Think of a **company with multiple teams**:

* 🟢 **master** = Stable product that customers use.
* 🔵 **feature branch** = Team building a new feature (Bluetooth).
* 🔴 **hotfix branch** = Team fixing an urgent production bug.
* 🔄 **merge** = Bringing completed work back into the stable product.
* 🗑️ **delete branch** = Removing the temporary workspace after its work has been incorporated.

This branching workflow lets multiple developers work on different tasks at the same time without disrupting the stable version of the software. That's why it's one of the most common Git workflows used in real-world software development.

