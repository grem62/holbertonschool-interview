#!/usr/bin/env python3
"""_summary_
"""


def minOperations(n):
    """_summary_

    Args:
        n (_type_): _description_
    """
    div = 2
    result = 0
    while isinstance(n, int) and n > 1:
        while n % div:
            div += 1
        result += div
        n = n // div
    return result
