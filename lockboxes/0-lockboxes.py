#!/usr/bin/python3
""" method to determine if all boxes are unlockable or not"""


def canUnlockAll(boxes):
    """ code """
    if len(boxes) == 1:
        return (True)
    num_of_boxes_to_unlock = len(boxes) - 1
    keys = boxes[0].copy()
    for i in keys:
        if i <= len(boxes) - 1:
            for j in boxes[i]:
                if j not in keys and j != 0:
                    keys.append(j)
        else:
            if i in keys:
                keys.remove(i)
    if len(boxes) > 998:
        print(f"keys : {len(keys)}")
        print(f"boxes : {num_of_boxes_to_unlock}")
        print(f"numboxes : {len(boxes)}")
        print(f"test {boxes[0][0:3]}")

    if len(keys) == num_of_boxes_to_unlock:
        return (True)
    else:
        return (False)
