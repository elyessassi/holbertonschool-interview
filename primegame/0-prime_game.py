#!/usr/bin/python3
""" Prime game algotithm """


def isWinner(x, nums):
    """ returns the winner's name (main function) """
    if (x < 1):
        return ("None")

    p1_score = 0
    p2_score = 0
    for i in nums:
        nb_prime = prime_num(i)
        if (nb_prime % 2 != 0):
            p1_score = p1_score + 1
        else:
            p2_score = p2_score + 1
    if (p1_score > p2_score):
        return ("Maria")
    elif (p1_score < p2_score):
        return ("Ben")
    else:
        return (None)


def prime_num(num):
    """
    returns the number or prime numbers in a group
    of numbers starting by 1 and ending by n
    """

    cpt = 0
    for i in range(2, num + 1):
        if (is_prime(i) is True):
            cpt = cpt + 1
    return (cpt)


def is_prime(n):
    """ returns True if a number is prime and false if not """

    for i in range(2, n):
        if ((n % i) == 0):
            return (False)
    return (True)
