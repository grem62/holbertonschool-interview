#!/usr/bin/python3
"""
Pascal's Triangle
"""


def pascal_triangle(n):
    """
    returns a list of lists of integers representing the Pascal’s triangle of n
    """
    # If n is less than or equal to 0, return an empty list
    if n <= 0:
        return []

    # If n is equal to 1, return a list containing a single list with 1
    if n == 1:
        return [[1]]

    # Create the first row of the triangle containing just 1
    triangle = [[1]]

    # Loop to generate each row of the triangle up to the n-th row
    for i in range(1, n):

        # Start each new row with a 1
        row = [1]

        # Fill in row by calculating the sum of adjacent elements from prev row
        for j in range(1, i):

            # Add the element to new row, which is sum of 2 adjacent elements
            # from the previous row (triangle[i-1][j-1] and triangle[i-1][j])
            row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])

        # End the row by adding a 1 to the end
        row.append(1)

        # Add the completed row to the triangle
        triangle.append(row)

    # Return the triangle
    return triangle
