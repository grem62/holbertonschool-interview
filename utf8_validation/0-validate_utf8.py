#!/usr/bin/python3
"""
Module that contains a function to check if a list of integers
represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Check if a list of integers represents a valid UTF-8 encoding.

    Args:
        data (list): A list of integers representing bytes.

    Returns:
        bool: True if the list of integers represents a valid UTF-8 encoding,
            False otherwise.
    """
    nbBytes = 0

    for byte in data:
        mask = 1 << 7
        if nbBytes == 0:
            while mask & byte:
                nbBytes += 1
                mask = mask >> 1
            if nbBytes == 0:
                continue
            if nbBytes == 1 or nbBytes > 4:
                return False
        else:
            if not (byte & mask and not (byte & (mask >> 1))):
                return False
        nbBytes -= 1
    return nbBytes == 0
