#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n, write
a method that calculates the fewest number of operations needed to result in
exactly n H characters in the file.

    Prototype: def minOperations(n)
    Returns an integer
    If n is impossible to achieve, return 0

Example:

n = 9

H => Copy All => Paste => HH => Paste =>HHH => Copy All => Paste => HHHHHH =>
Paste => HHHHHHHHH

Number of operations: 6
"""


def minOperations(n):
    opps, text = 0, 'H'
    if n == 1:
        opps = 1
    if n > 1:
        if n % 2 == 1:
            for i in [3, 5, 7]:
                if n % i == 0:
                    copy = text[:]
                    text += (i - 1) * copy
                    opps = i
        while len(text) != n:
            if n % len(text) == 0:
                copy = text[:]
                text += copy
                opps += 2
            else:
                text += copy
                opps += 1
    return opps
