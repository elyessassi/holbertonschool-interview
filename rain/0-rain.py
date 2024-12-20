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
        print(f"entering :: i = {i}  w1 = {w1}  w2 =  {w2}")
        if (walls[i] > 0) and (started == False):
            w1 = i
            started = True
            print(f"exiting case 1 ::: i = {i}  w1 = {w1}  w2 =  {w2}")
            continue
        if (walls[w1] > 0) and (walls[w1 + 1] >= walls[w1]) and (w1 < len(walls) - 2):
            w1 = w1 + 1
            print(f"exiting case 2 ::: i = {i}  w1 = {w1}  w2 =  {w2}")
            continue
        if (walls[w1] > 0) and (walls[i] > walls[w1 + 1]):
            w2 = i
            
            for j in range(w1 + 1, w2):
                if (walls[w1] >= walls[w2]):
                    RainWater = RainWater + (walls[w2] - walls[j])
                else:
                    RainWater = RainWater + (walls[w1] - walls[j])
            w1 = w2
            print(f"exiting  case 3 ::: i = {i}  w1 = {w1}  w2 =  {w2}    RW = {RainWater}")
        
    return RainWater