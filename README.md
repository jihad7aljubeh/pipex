# pipex

A Unix-like command-line utility written in C that emulates the shell pipe (`|`) functionality between commands.

## Overview

pipex is a custom implementation—typically as part of a C programming project or coding school curriculum—of Unix pipes. It allows for execution of two commands where the output of the first command is passed as the input to the second, mimicking:

```sh
< infile cmd1 | cmd2 > outfile
```

## Features

- Executes two commands with piping between them.
- Supports input file (`infile`) and output file (`outfile`) redirection.
- Handles command path resolution using the `PATH` environment variable.
- Implements error handling for system calls (fork, execve, dup2, pipe, open, close).
- Written in C for UNIX/Linux environments.

## Usage

### Compilation

Compile the project using:

```sh
make
```
or manually:

```sh
gcc -Wall -Wextra -Werror -o pipex pipex.c
```

### Running

The standard usage is:

```sh
./pipex infile "cmd1 args" "cmd2 args" outfile
```

- `infile`: Path to the input file
- `"cmd1 args"`: First command and its arguments (quoted)
- `"cmd2 args"`: Second command and its arguments (quoted)
- `outfile`: Path to the output file

#### Example:

```sh
./pipex input.txt "grep foo" "wc -l" result.txt
```

This reads `input.txt`, pipes it through `grep foo`, then passes the result to `wc -l`, and writes the output to `result.txt`.

## Project Structure

- `pipex.c`: Main program logic (process creation, piping, error handling)
- `utils.c` / `utils.h`: Utility functions (parsing, path resolution, error output)
- `Makefile`: Build script

> Adjust structure as per your file organization.

## Error Management

- Invalid file, command, or memory allocation errors print descriptive messages to `stderr` and exit with appropriate codes.

## Requirements

- UNIX/Linux environment (uses POSIX API)
- GCC compiler

---

_For educational purposes. Created by [jihad7aljubeh](https://github.com/jihad7aljubeh)._
