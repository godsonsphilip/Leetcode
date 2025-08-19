class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        if 0 not in nums: return 0
        i, j = 0, 0
        count = 0
        while j<n :
            while j<n and nums[j] != 0:
                j+=1
                i+=1
            while j<n and nums[j]==0:
                count += j-i+1
                j += 1
            i = j
        return count
            