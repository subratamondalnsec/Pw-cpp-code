
Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~
$ git --version 
%  <!-- This command should display the installed Git version -->
% git version 2.44.0.windows.1

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~
$ git help
<!--The git help command provides a summary of Git commands and shows you how to get more information on each command. Here’s how to use it: -->


<!-- usage: git [-v | --version] [-h | --help] [-C <path>] [-c <name>=<value>]
           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
           [-p | --paginate | -P | --no-pager] [--no-replace-objects] [--bare]
           [--git-dir=<path>] [--work-tree=<path>] [--namespace=<name>]
           [--config-env=<name>=<envvar>] <command> [<args>]

These are common Git commands used in various situations:

start a working area (see also: git help tutorial)
   clone     Clone a repository into a new directory
   init      Create an empty Git repository or reinitialize an existing one

work on the current change (see also: git help everyday)
   add       Add file contents to the index
   mv        Move or rename a file, a directory, or a symlink
   restore   Restore working tree files
   rm        Remove files from the working tree and from the index

examine the history and state (see also: git help revisions)
   bisect    Use binary search to find the commit that introduced a bug
   diff      Show changes between commits, commit and working tree, etc
   grep      Print lines matching a pattern
   log       Show commit logs
   show      Show various types of objects
   status    Show the working tree status

grow, mark and tweak your common history
   branch    List, create, or delete branches
   commit    Record changes to the repository
   merge     Join two or more development histories together
   rebase    Reapply commits on top of another base tip
   reset     Reset current HEAD to the specified state
   switch    Switch branches
   tag       Create, list, delete or verify a tag object signed with GPG

collaborate (see also: git help workflows)
   fetch     Download objects and refs from another repository
   pull      Fetch from and integrate with another repository or a local branch
   push      Update remote refs along with associated objects

'git help -a' and 'git help -g' list available subcommands and some
concept guides. See 'git help <command>' or 'git help <concept>'
to read about a specific subcommand or concept.
See 'git help git' for an overview of the system. -->


<!-- git init: Initialize a new Git repository.
git clone: Clone an existing repository.
git add: Add files to the staging area.
git commit: Commit changes to the repository.
git status: Show the status of changes in the repository.
git push: Push commits to a remote repository.
git pull: Pull updates from a remote repository.
--> 

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~
$ pwd  
/c/Users/Subrata Mondal

% The pwd command in a terminal stands for "print working directory." It shows the current directory path you are in. To use it, simply type:


Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~
$ cd C:  
<!--The cd command is used to change directories-->

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 /c
$ cd Users
Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 /c/Users
$ cd Subrata\ Mondal
Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~
$ cd OneDrive
Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive
$ cd Desktop
Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop
$ cd pw\ lec\ all\ code\ vs\ code
Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code (main)
$ cd 23Graph
Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph (main)
$ cd class


Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph/class (main)
$ git status

<!-- On branch main
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        00practice.cpp
        00practice.exe
        01undirected_unweighted_graph_adjacency_list.cpp
        02directed_unweighted_graph_adjacency_list.cpp
        03undirected_weighted_graph_adjacency_list.cpp
        04directed_weighted_graph_adjacency_list.cpp
        05undirected_unweighted_graph_adjacency_set.cpp
        06directed_unweighted_graph_adjacency_set.cpp
        07undirected_weighted_graph_adjacency_map.cpp
        08directed_weighted_graph_adjacency_map.cpp
        09undirected_unweighted_graph_adjacency_matrix.cpp
        10directed_unweighted_graph_adjacency_matrix.cpp
        11undirected_weighted_graph_adjacency_matrix.cpp
        12directed_weighted_graph_adjacency_matrix.cpp
        13DFS_of_graph_gfg.cpp
        14BFS_of_graph_gfg.cpp
        15Any_Node_present_using_dfs_method.cpp
        16All_path_src_to_dct_DFS.cpp
        17Shortest_Path_BFS.cpp
        20find-center-of-star-graph_Leetcode-1791.cpp
        21keys-and-rooms_Leetcode-841.cpp
        22clone-graph_Leetcode-133.cpp
        floodfill -application/

nothing added to commit but untracked files present (use "git add" to track) -->

<!--
The `git status` command shows the current state of the working directory and staging area in a Git repository. It provides information about:

1. **Tracked Changes**: Any changes staged for the next commit.
2. **Unstaged Changes**: Files that have been modified but not yet staged.
3. **Untracked Files**: Files that are not tracked by Git yet (i.e., new files).

To use it, simply type:

```bash
git status
```

### Example Output

You might see something like this:

```plaintext
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   file1.txt

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   file2.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        file3.txt
```

This output indicates:
- `file1.txt` is staged and ready to be committed.
- `file2.txt` has changes but is not staged.
- `file3.txt` is a new, untracked file.
-->


Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph/class (main)
$ git add 21keys-and-rooms_Leetcode-841.cpp

% <!-- git add are individual add Stage a File:-->

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph/class (main)
$ git add.

<!--
git add this folder all file are  add  Stage a File:
-->


Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph/class (main)
$ git restore --staged 21keys-and-rooms_Leetcode-841.cpp

%  The git restore --staged command is used to unstage files that were previously added to the staging area. This effectively removes changes from the staging area but keeps them in your working directory.

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph/class (main)
$ git restore  <file name>


<!-- The `git restore <file>` command is used to discard changes in a specific file and revert it back to the last committed version in the repository. This command is helpful if you want to undo modifications to a file that haven't been staged yet.

### Syntax

```bash
git restore <file>
```

Replace `<file>` with the name of the file you want to restore.

### Example Usage

1. **Make Changes to a File**  
   Suppose you make some edits to `example.txt`.

2. **Restore the File to Last Commit**  
   If you want to discard those changes and revert to the last committed version:
   ```bash
   git restore example.txt
   ```

### Important Notes
- **Restoring Staged Changes**: If the file has already been staged, use `git restore --staged <file>` to unstage it, or `git restore <file>` to discard all changes, both staged and unstaged.
- **Irreversible Action**: Using `git restore` will discard your changes, so make sure to only use it when you're okay with losing those modifications. -->


Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph/class (main)
$ git commit -m "first commit"

<!--
% On branch main
% Untracked files:
%   (use "git add <file>..." to include in what will be committed)
%         00practice.cpp
%         00practice.exe
%         01undirected_unweighted_graph_adjacency_list.cpp
%         02directed_unweighted_graph_adjacency_list.cpp
%         03undirected_weighted_graph_adjacency_list.cpp
%         04directed_weighted_graph_adjacency_list.cpp
%         05undirected_unweighted_graph_adjacency_set.cpp
%         06directed_unweighted_graph_adjacency_set.cpp
%         07undirected_weighted_graph_adjacency_map.cpp
%         08directed_weighted_graph_adjacency_map.cpp
%         09undirected_unweighted_graph_adjacency_matrix.cpp
%         10directed_unweighted_graph_adjacency_matrix.cpp
%         11undirected_weighted_graph_adjacency_matrix.cpp
%         12directed_weighted_graph_adjacency_matrix.cpp
%         13DFS_of_graph_gfg.cpp
%         14BFS_of_graph_gfg.cpp
%         15Any_Node_present_using_dfs_method.cpp
%         16All_path_src_to_dct_DFS.cpp
%         17Shortest_Path_BFS.cpp
%         20find-center-of-star-graph_Leetcode-1791.cpp
%         21keys-and-rooms_Leetcode-841.cpp
%         22clone-graph_Leetcode-133.cpp
%         floodfill -application/

% nothing added to commit but untracked files present (use "git add" to track)
-->

<!--
%  The `git commit -m "first commit"` command is used to create a new commit with a message describing the changes. The `-m` flag allows you to add a message inline, without opening an editor.

% ### Syntax

% ```bash
% git commit -m "your commit message here"
% ```

% In this example:

% ```bash
% git commit -m "first commit"
% ```

% Git creates a new commit with the message "first commit," which could be a typical initial commit message for a new project.

% ### Example Workflow

% 1. **Stage Changes**:
%    ```bash
%    git add .
%    ```
%    This stages all changes in the current directory.

% 2. **Create the Commit**:
%    ```bash
%    git commit -m "first commit"
%    ```

% ### Important Notes

% - **Commit Message**: Choose a descriptive message to explain what changes are included in the commit.
% - **Staged Changes Only**: Only staged changes are included in the commit.

-->

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~
$ git config --list
<!-- 
diff.astextplain.textconv=astextplain
filter.lfs.clean=git-lfs clean -- %f
filter.lfs.smudge=git-lfs smudge -- %f
filter.lfs.process=git-lfs filter-process
filter.lfs.required=true
http.sslbackend=openssl
http.sslcainfo=C:/Program Files/Git/mingw64/etc/ssl/certs/ca-bundle.crt
core.autocrlf=true
core.fscache=true
core.symlinks=false
pull.rebase=false
credential.helper=manager
credential.https://dev.azure.com.usehttppath=true
init.defaultbranch=master
user.name=subratamondal2
user.email=subrata24012005@gmail.com
filter.lfs.clean=git-lfs clean -- %f
filter.lfs.smudge=git-lfs smudge -- %f
filter.lfs.process=git-lfs filter-process
filter.lfs.required=true
 -->

<!-- 
user.name=Your Name
user.email=your.email@example.com
it tail us your git user.name and email.
-->

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~
$ git config --list --show-origin

<!--
% file:C:/Program Files/Git/etc/gitconfig diff.astextplain.textconv=astextplain
% file:C:/Program Files/Git/etc/gitconfig filter.lfs.clean=git-lfs clean -- %f
% file:C:/Program Files/Git/etc/gitconfig filter.lfs.smudge=git-lfs smudge -- %f
% file:C:/Program Files/Git/etc/gitconfig filter.lfs.process=git-lfs filter-process
% file:C:/Program Files/Git/etc/gitconfig filter.lfs.required=true
% file:C:/Program Files/Git/etc/gitconfig http.sslbackend=openssl
% file:C:/Program Files/Git/etc/gitconfig http.sslcainfo=C:/Program Files/Git/mingw64/etc/ssl/certs/ca-bundle.crt
% file:C:/Program Files/Git/etc/gitconfig core.autocrlf=true
% file:C:/Program Files/Git/etc/gitconfig core.fscache=true
% file:C:/Program Files/Git/etc/gitconfig core.symlinks=false
% file:C:/Program Files/Git/etc/gitconfig pull.rebase=false
% file:C:/Program Files/Git/etc/gitconfig credential.helper=manager
% file:C:/Program Files/Git/etc/gitconfig credential.https://dev.azure.com.usehttppath=true
% file:C:/Program Files/Git/etc/gitconfig init.defaultbranch=master
% file:C:/Users/Subrata Mondal/.gitconfig user.name=subratamondal2
% file:C:/Users/Subrata Mondal/.gitconfig user.email=subrata24012005@gmail.com
% file:C:/Users/Subrata Mondal/.gitconfig filter.lfs.clean=git-lfs clean -- %f
% file:C:/Users/Subrata Mondal/.gitconfig filter.lfs.smudge=git-lfs smudge -- %f
% file:C:/Users/Subrata Mondal/.gitconfig filter.lfs.process=git-lfs filter-process
% file:C:/Users/Subrata Mondal/.gitconfig filter.lfs.required=true
-->

% The git config --list --show-origin command is similar to git config --list but with an added feature: it shows the source of each configuration setting. This command is useful for identifying where each setting originates (e.g., global, local, or system configuration files). 

% dont show user name and email you use add this command

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~
$ git config --global user.name "github user name" 
<!-- add user name this command -->


Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~
$ git config --global user.email "github user email" 
% <!-- add user email this command -->


Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph (main)
$ git branch -M master 

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph (master)

<!-- change the branch-> git branch -M (branch name)  -->

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph (main)
$ git remote add origin https://github.com/subratamondalnsec/aise-hi.git

%  your origin remote will be set to https://github.com/subratamondalnsec/aise-hi.git, and you should be able to push to it without issues.

 Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/pw lec all code vs code/23Graph (main)
$ git push -u origin main

<!-- it will attempt to push your local main branch to the main branch in the remote repository at origin. -->

Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/web devlopment
$ git clone https://github.com/subratamondalnsec/aise-hi.git
Cloning into 'aise-hi'...
remote: Enumerating objects: 4, done.
remote: Counting objects: 100% (4/4), done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 4 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (4/4), done.

<!--
% The git clone command is used to create a local copy of a remote repository:
% git clone <repository_url>
% Example:
% git clone https://github.com/username/repository.git
-->


Subrata Mondal@LAPTOP-TCIJE5DP MINGW64 ~/OneDrive/Desktop/web devlopment
$ git pull https://github.com/subratamondalnsec/aise-hi.git

<!-- This command updates your local branch with the latest changes(modifing version) from the specified branch in the remote repository (commonly origin/main if using the main branch). -->
