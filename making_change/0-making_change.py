#!/usr/bin/python3

"""_summary_
"""

def makeChange(coins, total):
    memo = {}

    def dp(n):
        if n in memo:
            return memo[n]
        if n == 0:
            return 0
        if n < 0:
            return float('inf')
        min_count = float('inf')
        for coin in coins:
            count = dp(n - coin)
            if count != float('inf'):
                min_count = min(min_count, count + 1)
        memo[n] = min_count
        return min_count

    result = dp(total)
    return result if result != float('inf') else -1
