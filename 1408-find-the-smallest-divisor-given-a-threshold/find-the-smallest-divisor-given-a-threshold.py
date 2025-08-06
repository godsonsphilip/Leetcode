import math
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def divisors(mid, nums):
            total = 0
            n = len(nums)
            for i in nums:
                total += math.ceil(i/mid)
            return total
        n = len(nums)
        ans = 0
        maxi, mini = max(nums), min(nums)

        # Applying teh binary search on Answers:
        low = 1
        high = maxi
        while low<=high:
            mid = low + (high-low)//2
            if divisors(mid, nums) <= threshold :
                ans = mid
                high = mid-1
                continue
            
            low = mid + 1
        return ans
    
