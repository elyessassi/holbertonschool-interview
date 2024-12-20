#!/usr/bin/python3

""" Rain Algorithm """


def rain(walls):
    """ Rain function
    w1 : index of the wall to the left
    w2 : index of the wall to the right
    RainWater: the total of rain water collected
    Return Value: RainwWater
    """
    RainWater = 0
    if (len(walls) == 0):
        return 0
    w1 = 0
    w2 = 0
    started = False
    for i in range(len(walls)):
        if (walls[i] > 0) and (started is False):
            w1 = i
            started = True
            continue
        if (walls[w1] > 0) and (walls[w1 + 1] >= walls[w1]) and (w1 < len(walls) - 2):
            w1 = w1 + 1
            continue
        if (walls[w1] > 0) and (walls[i] > walls[w1 + 1]):
            w2 = i
            for j in range(w1 + 1, w2):
                if (walls[w1] >= walls[w2]):
                    RainWater = RainWater + (walls[w2] - walls[j])
                else:
                    RainWater = RainWater + (walls[w1] - walls[j])
            w1 = w2
    return RainWater
