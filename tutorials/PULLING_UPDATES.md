# Pulling Updates from This Repository

You should regularly pull updates to get the latest in-class examples. I try to push the code soon after each class, although I do go bck through and add comments that I don't get around to during class. So code may slightly change from what we do in class, but nothing drastic that I won't point out.

> This document assumes you are working on Windows with a standard Git installation. Some things may be different, but the concepts and most commands should translate to Linux or Mac.

## Before You Pull

Make sure you **have not modified files** in this repository

This repo must be:

- read-only reference code
- not a place for your own experiments

If you want to experiment (which I highly encourage):

- make a copy of a file, or
- work in a different repository

---

Option 1: Pull Using CLion (Recommended)

1. Open the **root directory** of this repo in CLion
2. In the top menu, select:  
**Git -> Pull**
3. Leave all settings at their defaults
4. Click **Pull**

If CLion asks how to handle changes and you didn't modify anything:
- choose **Update**

If CLion reports conflicts:
- stop and ask for help (this should not normally happen)

---

Option 2: Pull Using the Command Line

Open a Git Bash shell (or terminal that can run `git`) and from the root of the repository run:

```bash
git pull
```

That's it.

---

## If Git Refuses to Pull

If Git says you have local changes, you have two save options:

### Option A: Discard Local Changes (Recommended)  
If you don't care about local edits:

```bash
git reset --hard
git pull
```

⚠️ This permanently discards local changes in this repo.

---

### Option B: Save Your Changes Elsewhere
If you *do* want to keep your changes
1. Copy the files you modified into a different folder
2. Then run

```bash
git reset --hard
git pull
```

---

### What You Should *Not* Do

❌ Do not commit changes to this repository  
❌ Do not push to this repository  
❌ Do not use this repo for assignments  
❌ Do not force pull or rebase

If you see Git asking you to make a commit here, **stop**.

---

### When in Doubt

If:
- Git shows a warning
- You see merge conflicts
- Something looks unfamiliar

**Stop and ask before clicking anything**

Fixing Git mistakes is harder than preventing them. (I know this from experience unfortunately)

