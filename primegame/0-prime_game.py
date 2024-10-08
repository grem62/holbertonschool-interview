#!/usr/bin/python3
"""
Defines a function that determines the winner after a certain number of rounds
of playing the Prime Game
"""


def isWinner(x, nums):
    """
    Determines the winner after a certain number of rounds
    of playing the Prime Game

    The Prime Game is a list of consecutive integers starting from 1 up to and
    including n. Players take turns picking prime numbers, which removes
    that number and all multiples of that number from the set. The player that
    has no more prime numbers to choose loses the game.

    Maria and Ben are playing the game, and Maria always goes first.

    Parameters:
        x (int):
            The number of rounds
        nums (list of ints):
            List of all ns for each round

    Returns:
        The name of the player that won the most rounds,
        if both players play optimally,
        or None if the winner cannot be determined
    """
    Maria = 0
    Ben = 0

    if x < 1 or x != len(nums):
        return None

    for n in nums:
        winner = primeGame(n)
        if winner == 1:
            Maria += 1
        elif winner == 2:
            Ben += 1

    if Maria == Ben:
        return None
    elif Maria > Ben:
        return "Maria"
    return "Ben"


def primeGame(n):
    """
    Determines the winner of a single round of the Prime Game

    Parameters:
        n (int):
            The maximum number of the set of consecutive integers
            from 1 up to and including n

    Returns:
        1 if the first player wins the game
        2 if the second player wins the game
    """
    if n < 1:
        return None

    if n == 1:
        return 2

    numbers = list(range(n + 1))
    player = 1
    prime = 2
    primes_used = []

    for num in numbers:
        if num % prime == 0:
            numbers.remove(num)

    primes_used.append(prime)
    prime = 3

    while numbers != [1]:
        if player == 1:
            player = 2
        else:
            player = 1

        for num in numbers:
            if num % prime == 0:
                numbers.remove(num)

        primes_used.append(prime)
        prime += 2
        flag = 1

        while flag:
            for num in primes_used:
                if prime % num == 0:
                    prime += 2
                    break
            else:
                flag = 0

    if player == 1:
        return 1
    return 2