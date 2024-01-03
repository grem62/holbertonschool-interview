#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    # Create a set to keep track of the opened boxes
    opened_boxes = set([0])

    # Create a list to keep track of the keys
    keys = boxes[0]

    # Iterate through the keys and boxes
    while keys:
        # Get the first key from the list
        key = keys.pop(0)

        # Check if the key opens a new box
        if key < len(boxes) and key not in opened_boxes:
            # Add the key to the opened boxes set
            opened_boxes.add(key)

            # Add the new keys to the list
            keys.extend(boxes[key])

    # Check if all boxes have been opened
    return len(opened_boxes) == len(boxes)
