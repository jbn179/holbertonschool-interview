#!/usr/bin/python3
"""
Module for making change problem.
Determines the fewest number of coins needed to meet a given amount.
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given total.

    Args:
        coins: list of coin values available (infinite supply of each)
        total: the target amount

    Returns:
        Fewest number of coins needed to meet total.
        0 if total is 0 or less.
        -1 if total cannot be met by any combination of coins.
    """
    if total <= 0:
        return 0

    # dp[i] will hold the minimum coins needed to make amount i
    # Initialize with total + 1 (acts as infinity since we can't
    # need more than 'total' coins even with denomination 1)
    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] <= total else -1
