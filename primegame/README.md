# Prime Game

This project is a classic algorithmic challenge based on game theory and number theory.

## Problem Description

The task is to determine the winner of a game played by Maria and Ben over multiple rounds. For each round, given a number `n`, a set of consecutive integers `{1, 2, ..., n}` is created. The players take turns choosing a prime number from the set and removing that prime and all its multiples. The player who cannot make a move (because no prime numbers are left) loses the game.

## Objective

The goal is to implement the function `def isWinner(x, nums)` which takes the number of rounds `x` and a list of `n` values `nums`, and returns the name of the player who wins the most rounds.

## Algorithmic Approach

The winner of any given round depends solely on the number of prime numbers available in the set at the start.

* If the count of primes from 1 to `n` is odd, the first player (Maria) will make the last move and win.

* If the count of primes is __even__, the second player (Ben) will make the last move and win.
