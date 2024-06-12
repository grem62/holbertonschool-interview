#!/usr/bin/python3
"""_summary_
"""


def rotate_2d_matrix(matrix):
    """_summary_

    Args:
        matrix (_type_): _description_
    """
    matrix_copy = matrix.copy()
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j] = matrix_copy[len(matrix[i])-1-j][i]
    return matrix
