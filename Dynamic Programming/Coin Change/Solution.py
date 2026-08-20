class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        def coinChangeHelper(coins, amount, memo):
            if amount in memo.keys(): return memo[amount]
            if amount < 0: return float("inf")
            memo[amount] = 1 + min(coinChangeHelper(coins, amount - coin, memo) for coin in coins)
            return memo[amount]
        
        answer = coinChangeHelper(coins, amount, {0: 0})
        return -1 if answer == float("inf") else answer