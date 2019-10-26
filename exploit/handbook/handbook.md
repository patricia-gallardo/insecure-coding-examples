# Notes and examples
## Background

The code and examples are based on the book ['The Shellcoder's Handbook: Discovering and Exploiting Security Holes 2nd Edition'][1] by Chris Anley, John Heasman, Felix Lindner and Gerardo Richarte

## Address space layout randomization (ASLR) : find_stackpointer.c

~~~~
$ cat /proc/sys/kernel/randomize_va_space
2
~~~~

0: No randomization
1: Conservative randimization
2: Full randimization


[1]: http://a.co/d/hKF1whP
