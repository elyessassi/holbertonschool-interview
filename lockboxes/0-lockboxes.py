#!/usr/bin/python3
""" method to determine if all boxes are unlockable or not"""


def canUnlockAll(boxes):
    """ code """

    num_of_boxes_to_unlock = len(boxes) - 1
    keys = boxes[0].copy()
    for i in keys:
        for j in boxes[i]:
            if j not in keys and j != 0:
                keys.append(j)
                print(keys)
    print(f"keys: {len(keys)}")
    print(f"num: {num_of_boxes_to_unlock}")
    if len(keys) == num_of_boxes_to_unlock:
        return (True)
    else:
        return (False)
