#!/usr/bin/python3


def canUnlockAll(boxes):
    keys = boxes[0]
    pending = []
    for i in range(1, len(boxes)):
        if i in keys:
            for key in boxes[i]:
                keys.append(key)
        else:
            pending.append(i)
    for i in pending:
        if i in keys:
            for key in boxes[i]:
                keys.append(key)
        else:
            return False
    return True
