#!/usr/bin/python3
"""
Module for the makeChange function.
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest
    number of coins needed to meet a given amount total.

    Args:
        coins (list): A list of the values of the coins in your possession.
                      The value of a coin will always be an integer > 0.
        total (int): The target amount.

    Returns:
        int: The fewest number of coins needed to meet total.
             If total is 0 or less, return 0.
             If total cannot be met by any number of coins you have, return -1.
    """
    if total <= 0:
        return 0

    # dp[i] will be storing the minimum number of coins required for amount i
    # Initialize all values to a value larger than any possible solution
    dp = [total + 1] * (total + 1)

    # The minimum coins for amount 0 is 0
    dp[0] = 0

    # Compute minimum coins for each amount from 1 to total
    for i in range(1, total + 1):
        # Check each coin
        for coin in coins:
            if coin <= i:
                # Update dp[i] if we find a better solution
                # The new potential solution is 1 (for the current coin) +
                # the solution for the remaining amount (i - coin)
                dp[i] = min(dp[i], dp[i - coin] + 1)

    # If dp[total] is still our initial large value, it means total can't be
    # met. Otherwise, dp[total] holds the answer.
    if dp[total] > total:
        return -1
    else:
        return dp[total]
