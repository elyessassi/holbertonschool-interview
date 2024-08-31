#!/usr/bin/python3
""" method to determine if all boxes are unlockable or not"""


def canUnlockAll(boxes):
    """ code """
    if len(boxes) == 1:
        return (True)
    num_of_boxes_to_unlock = len(boxes) - 1
    keys = list(dict.fromkeys(boxes[0]))
    index = 0
    for i in keys:
        if i <= len(boxes) - 1:
            for j in boxes[i]:
                if j not in keys and j != 0:
                    keys.append(j)
        else:
            if i in keys:
                keys[index] = None
        index = index + 1
    keys = [k for k in keys if k is not None]
    if len(keys) == num_of_boxes_to_unlock:
        return (True)
    else:
        return (False)
