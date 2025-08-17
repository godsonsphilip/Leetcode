class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        n = len(nums)

        def feasible(mid: int) -> int:
            count = 1
            total = 0
            for i in nums:
                total += i
                if total > mid:
                    total = i
                    count+=1
                    continue
                

            return count

        low, high = max(nums), sum(nums)
        ans = high
        while low<=high:
            mid = low + (high-low)//2
            if feasible(mid) > k :
                low = mid + 1
                continue
            
            high = mid - 1
        
        return low