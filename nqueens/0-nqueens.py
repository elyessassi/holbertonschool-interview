#!/usr/bin/python3

""" Nqueens Algorithm """

from sys import argv


if (len(argv) < 2):
    print("Usage: nqueens N")
    exit(1)

if (not argv[1].isnumeric()):
    print("N must be a number")
    exit(1)

if (int(argv[1]) < 4):
    print("N must be at least 4")
    exit(1)

chessboard = []
line = list('.' * int(argv[1]))
res = []
for i in range(int(argv[1])):
    chessboard.append(list(line))


def check(i, j, board):
    """ Method that checks for queens """
    # check up
    temp_i = i - 1
    while (temp_i >= 0):
        if (board[temp_i][j] == "Q"):
            return False
        temp_i = temp_i - 1

    # check left diagonal
    temp_i = i - 1
    temp_jl = j - 1
    while (temp_jl >= 0):
        if (board[temp_i][temp_jl] == 'Q'):
            return False
        temp_i = temp_i - 1
        temp_jl = temp_jl - 1

    # check right diagonal
    temp_i = i - 1
    temp_jr = j + 1
    while (temp_jr < len(board)):
        if (board[temp_i][temp_jr] == 'Q'):
            return False
        temp_i = temp_i - 1
        temp_jr = temp_jr + 1

    return True


def nqueens(N, board, i):
    if (i == len(board)):
        if (N == 0):
            res.append([row[:] for row in board])
        return
    for cpt in range(len(board)):
        if (check(i, cpt, board)):
            board[i][cpt] = "Q"
            nqueens(N - 1, board, i + 1)
            board[i][cpt] = "."


nqueens(int(argv[1]), chessboard, 0)

for i in range(len(res)):
    sol = []
    for j in range(len(res[i])):
        sol.append([j, res[i][j].index("Q")])
    print(sol)
