#!/usr/bin/python3
""" An algorithm that determines if a given
data set represents a valid UTF-8 encoding """


def validUTF8(data):
    """ The function that does the task"""
    i = 0
    byteCount = 0
    while i < (len(data) - 1):
        if data[i] > 255 or data[i] < 0:
            return False
        else:
            if data[i] >> 5 == int("110", 2):
                byteCount = 2
            if data[i] >> 4 == int("1110", 2):
                byteCount = 3
            if data[i] >> 3 == int("11110", 2):
                byteCount = 4
        if byteCount > 0:
            for j in range(1, byteCount + 1):
                j = j + i
                if data[j] >> 6 != int("10", 2):
                    return False
                i = i + 1
        else:
            i = i + 1
    return True
