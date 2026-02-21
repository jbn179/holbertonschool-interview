#!/usr/bin/python3
"""Example runner for makeChange"""

makeChange = __import__('0-making_change').makeChange

if __name__ == '__main__':
    # Example 1
    print(makeChange([1, 2, 25], 37))
    # Example 2
    print(makeChange([1256, 54, 48, 16, 102], 1453))
