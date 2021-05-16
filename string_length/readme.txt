# Exercise 431: Buffer Overflow

Refactoring string functions under Sanitizers

In the file string_length.cpp there are 3 functions:

1) stringLength
2) copyString
3) containsChar

Task:

Remove the ifdefs from the tests in string_length.tests.cpp and fix the
functions in string_length.cpp so that all the tests pass.

Preserve the current behavior of the functions, even when it is strange, all
tests should pass unaltered.

---------------------

CWE-121: Stack-based Buffer Overflow
CWE-122: Heap-based Buffer Overflow
CWE-124: Buffer Underwrite ('Buffer Underflow')

---------------------
