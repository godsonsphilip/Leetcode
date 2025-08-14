class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxi = 0
        buy = prices[0]
        n = len(prices)
        for i in range(1, n):
            if buy>prices[i]:
                buy = prices[i]
                continue
            maxi = max(maxi, prices[i]-buy)
        
        return maxi