#!/usr/bin/env python3
"""_summary_
"""

def rotate_2d_matrix(matrix):
    """_summary_
    """
    matrix_copy = matrix.copy()
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[j][len(matrix[i])-1-i] = matrix_copy[i][j]
    return matrix_copy