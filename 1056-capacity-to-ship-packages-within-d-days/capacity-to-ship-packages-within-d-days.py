class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        # Classic BS on Answers:
        # Range: mini to sum:
        def valid(mid):
            total, load = 1, 0
            for i in weights:
                if load + i > mid :
                    total += 1
                    load = i
                    continue
                load += i
            return total

        n = len(weights)
        maxi, mini = sum(weights), max(weights)
        ans = maxi
        # Applying BS on Answers:
        while mini<=maxi:
            mid = mini + (maxi-mini)//2
            if valid(mid) <=days:
                ans = mid
                maxi = mid -1
                continue
            mini = mid + 1
        return ans