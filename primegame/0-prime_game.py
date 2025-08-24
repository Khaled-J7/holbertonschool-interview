#!/usr/bin/python3
"""
Module for solving the Prime Game problem.
"""


def isWinner(x, nums):
    """
    Determines the winner of a prime game played over x rounds.

    The winner is decided based on the parity of the count of prime numbers
    up to n for each round. A Sieve of Eratosthenes is used to efficiently
    pre-compute primes up to the maximum n.

    Args:
        x (int): The number of rounds to be played.
        nums (list): A list of integers, where each integer n defines the set
                     {1, 2, ..., n} for a round.

    Returns:
        str: The name of the player who won the most rounds ("Maria" or "Ben").
        None: If the overall winner cannot be determined (e.g., a tie or
              invalid input).
    """
    if not nums or x < 1:
        return None

    max_n = max(nums)
    is_prime = [True] * (max_n + 1)
    is_prime[0] = is_prime[1] = False

    # Sieve of Eratosthenes to find all primes up to max_n
    for i in range(2, int(max_n**0.5) + 1):
        if is_prime[i]:
            for multiple in range(i * i, max_n + 1, i):
                is_prime[multiple] = False

    # Create a cumulative count of primes up to each number
    prime_counts = [0] * (max_n + 1)
    count = 0
    for i in range(max_n + 1):
        if is_prime[i]:
            count += 1
        prime_counts[i] = count

    maria_wins = 0
    ben_wins = 0

    # Determine the winner for each round
    for n in nums:
        primes_in_round = prime_counts[n]
        if primes_in_round % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    # Determine the overall winner
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
