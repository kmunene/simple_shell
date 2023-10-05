# Simple Shell Project

This is a simple shell project created by KELVIN MUNENE  and OSCAR MUTWIRI  for software engineerig students at ALX.

## Introduction

The Simple Shell project is a basic implementation of a command-line shell in the C programming language. It allows users to interact with the system by entering commands and executing them. This README provides an overview of the project, how to compile and run it, and some basic usage examples.

## Features

- **Command Execution:** The shell can execute system commands and display their output.
- **Built-in Commands:** We have implemented a few basic built-in commands such as `ENV` and `exit`.
- **Input/Output Redirection:** The shell supports input and output redirection using `<` and `>` operators.
- **Piping:** Users can pipe the output of one command into another using the `|` operator.

## Getting Started

### Prerequisites

To compile and run this project, you need:

- [GCC](https://gcc.gnu.org/) (GNU Compiler Collection) and is supposed to be compiled using these GCC flags

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### system calls and functions

These were the only allowed functions and system calls


    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    getpid (man 2 getpid)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)



