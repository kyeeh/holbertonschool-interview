#!/usr/bin/python3
"""
Given a list of non-negative integers representing walls of width 1, calculate
how much water will be retained after it rains. 
"""

def rain(walls):
    """
    walls is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    Assume that the ends of the list (before index 0 and after index
    walls[-1]) are not walls, meaning they will not retain water.
    If the list is empty return 0.
    """
    n = len(walls)
    wtr = 0

    for i in range(1, n - 1):
        lft = walls[i]
        for j in range(i):
            lft = max(lft, walls[j])
        rgt = walls[i]

        for j in range(i + 1, n):
            rgt = max(rgt, walls[j])

        wtr = wtr + (min(lft, rgt) - walls[i])
    return wtr
