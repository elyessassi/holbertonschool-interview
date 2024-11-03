#!/usr/bin/python3
""" An algorithm that determines if a given
data set represents a valid UTF-8 encoding """


def validUTF8(data):
    """ The function that does the task"""
    i = 0
    j = 1
    k = 0
    following_bytes = 0
    while i <= (len(data) - 1):
        data[i] = data[i] & 0xFF
        if data[i] >= 250:
            return False
        if data[i] >> 5 == int("110", 2):
            following_bytes = 1
        elif data[i] >> 4 == int("1110", 2):
            following_bytes = 2
        elif data[i] >> 3 == int("11110", 2):
            following_bytes = 3
        if following_bytes > 0:
            while True:
                k = i + j
                if k > len(data) - 1:
                    return False
                elif data[k] >> 6 != int("10", 2):
                    return False
                i = i + 1
                if k == following_bytes:
                    i = i + 1
                    following_bytes = 0
                    break
        else:
            i = i + 1
    return True
