def answer(coins, n):
    dp = [0] * (n+1)
    dp[0] = 1

    for coin in coins:
        for i in range(coin, n+1):
            dp[i] += dp[i-coin]

    return dp[-1]

n, m = input().split()
coins = map(int, input().split())
print(answer(coins, int(n)))
