#!/usr/bin/env python3

"""_summary_
"""

def makeChange(coins, total):
    dp = [float('inf')] * (total + 1)
    dp[0] = 0
    for i in range(1, total + 1):
        for coin in coins:
            if i >= coin:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[total] if dp[total] != float('inf') else -1
