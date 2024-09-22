#!/usr/bin/python3

""" Minimum Operations Algorithm :given one letter H and an integer n this
algorithm calculates the number of copy and paste
operation it takes to to have n letters H """


def minOperations(n):

    """ a funtion that finds the prime factors
    of n and sums them in a variable called op"""
    if (n <= 1):
        return (0)
    else:
        op = 0
        div = 2
        while n > 1:
            if (n % div == 0):
                op = op + div
                n = n / div
            else:
                div = div + 1
        return (op)
