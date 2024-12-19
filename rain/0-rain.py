#!/usr/bin/python3

def rain(walls):
    w1 = 0
    w2 = 0
    RainWater = 0
    space = 0
    if (len(walls) == 0):
        return 0
    for i in walls:
        if (i != 0) and (w1 == 0):
            w1 = i
            continue
        if (i == 0) and (w1 != 0):
            space = space + 1
            continue
        if (i != 0) and (w1 != 0):
            w2 = i
            if w1 >= w2:
                RainWater = RainWater + (space * w2)
            else:
                RainWater = RainWater + (space * w1)
            w1 = w2
            w2 = 0
            space = 0
    return RainWater
