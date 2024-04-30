#!/usr/bin/env python3


import sys


def safe_column_and_row(col, row, queen):
    for i in range(row):
        if queen[i] == col:
            return False
    return True


def safe_diagonal(col, row, queen):
    for i in range(row):
        if abs(queen[i] - col) == abs(i - row):
            return False
    return True


def nqueens(nQ, row, queen, solutions):
    if row == nQ:
        solutions.append([[i, queen[i]] for i in range(nQ)])
    else:
        for col in range(nQ):
            if safe_column_and_row(col,
                                   row,
                                   queen) and safe_diagonal(col, row, queen):
                queen[row] = col
                nqueens(nQ, row + 1, queen, solutions)


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        nQ = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if nQ < 4:
        print("N must be at least 4")
        sys.exit(1)
    queen = [0 for _ in range(nQ)]
    solutions = []
    nqueens(nQ, 0, queen, solutions)
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
