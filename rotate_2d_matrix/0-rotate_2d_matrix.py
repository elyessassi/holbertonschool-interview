#!/usr/bin/python3

def rotate_2d_matrix(matrix):
	line_length = len(matrix)
	
	matrix.reverse()

	for i in range(line_length):
		for j in range(i, line_length):
			temp = matrix[i][j]
			matrix[i][j] = matrix[j][i]
			matrix[j][i] = temp
