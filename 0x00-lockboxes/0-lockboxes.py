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


def canUnlockAll(boxes):
    keys = boxes[0]
    pending = []
    # keys_used = 0
    for i in range(1,len(boxes)):
        if i in keys:
            # d = dict.fromkeys(keys)
            # keys = list(d.keys())
            # keys.remove(i)
            # keys_used += 1
            for key in boxes[i]:
                keys.append(key)
        else:
            pending.append(i)
    for i in pending:
        if i in keys:
            # d = dict.fromkeys(keys)
            # keys = list(d.keys())
            # keys.remove(i)
            # keys_used += 1
            for key in boxes[i]:
                keys.append(key)
        else:
            return False
    return True # keys_used == len(boxes)
