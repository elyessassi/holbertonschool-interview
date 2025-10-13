#!/usr/bin/python3
""" Rotate Matrix Algorithm """


def rotate_2d_matrix(matrix):
    """ Main function """
    line_length = len(matrix)
    matrix.reverse()

    for i in range(line_length):
        for j in range(i, line_length):
            temp = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = temp
