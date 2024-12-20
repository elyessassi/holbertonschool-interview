#!/usr/bin/python3

""" Rain Algorithm """


def rain(walls):
    """ Rain function
    w : index of the wall to the left
    w2 : index of the wall to the right
    RainWater: the total of rain water collected
    Return Value: RainwWater
    """
    RainWater = 0
    if (len(walls) == 0):
        return 0
    w = 0
    w2 = 0
    started = False
    for i in range(len(walls)):
        if (walls[i] > 0) and (started is False):
            w = i
            started = True
            continue
        if walls[w] > 0 and walls[w + 1] >= walls[w] and w < len(walls) - 2:
            w = w + 1
            continue
        if (walls[w] > 0) and (walls[i] > walls[w + 1]):
            w2 = i
            for j in range(w + 1, w2):
                if (walls[w] >= walls[w2]):
                    RainWater = RainWater + (walls[w2] - walls[j])
                else:
                    RainWater = RainWater + (walls[w] - walls[j])
            w = w2
    return RainWater
