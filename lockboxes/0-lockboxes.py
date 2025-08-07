#!/usr/bin/python3
"""
Lockboxes problem solution
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.

    Args:
        boxes: List of lists where each index represents a box
               and contains keys to other boxes

    Returns:
        True if all boxes can be opened, False otherwise
    """
    if not boxes:
        return False

    n = len(boxes)

    # Set to keep track of opened boxes
    opened = set([0])  # Box 0 is initially unlocked

    # Stack for DFS - start with keys from box 0
    keys_to_check = list(boxes[0])

    # Process all available keys
    while keys_to_check:
        key = keys_to_check.pop()

        # If key corresponds to a valid box that hasn't been opened yet
        if 0 <= key < n and key not in opened:
            opened.add(key)
            # Add all keys from this newly opened box
            keys_to_check.extend(boxes[key])

    # Check if all boxes have been opened
    return len(opened) == n
