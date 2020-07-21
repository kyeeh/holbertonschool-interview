#!/usr/bin/python3
# from functools import reduce
# from numpy import unique


# def canUnlockAll(boxes):
#     keys = reduce(lambda x, y: x + y, boxes)
#     # flatten = lambda l: [item for sublist in l for item in sublist]
#     keys = list(unique(keys))
#     if keys[0] == 0:
#         keys = keys[1:]
#     # d = dict.fromkeys(keys)
#     # keys = list(d.keys())
#     for box in range(len(boxes) - 1):
#         if box + 1 != keys[box]:
#             return False
#     return True


def open(box, keys):
    return box in keys


def canUnlockAll(boxes):
    keys = boxes[0]
    n = len(boxes) - 1
    i = rec_canUnlockAll(boxes, keys, n, 1)
    return i == n


def rec_canUnlockAll(boxes, keys, n, i):
    if open(i, keys):
        if i != n:
            for key in boxes[i]:
                keys.append(key)
            i = rec_canUnlockAll(boxes, keys, n, i + 1)
    return i
