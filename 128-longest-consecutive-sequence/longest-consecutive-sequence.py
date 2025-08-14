class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n = len(nums)
        maxi = 0
        count = 0
        mpp = set(nums)
        
        for num in mpp:
            if num-1 in mpp : continue
            count = 1
            curr = num
            while curr+1 in mpp:
                count += 1
                curr += 1
            maxi = max(count, maxi)
            
        return maxi