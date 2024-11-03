#!/usr/bin/python3
""" An algorithm that determines if a given
data set represents a valid UTF-8 encoding """


def validUTF8(data):
    """ The function that does the task"""
    i = 0
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
            for j in range(following_bytes):
                if (j + i + 1) > len(data) - 1:
                    return False
                elif data[j + i + 1] >> 6 != int("10", 2):
                    return False
        i = i + following_bytes
        following_bytes = 0
    return True
