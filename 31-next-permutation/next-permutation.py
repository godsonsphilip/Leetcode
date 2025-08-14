class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        n = len(nums)
        critical = -1
        for i in range(n-1, 0, -1):
            if nums[i]>nums[i-1]:
                critical = i
                break

        if critical==-1:
           nums.sort()
           return
        
        # Swap the next element with the smallest greater element than this one:

        for i in range(n-1, critical-1, -1):
            if nums[i]>nums[critical-1]:
                nums[i], nums[critical-1] = nums[critical-1], nums[i]
                break

        #Sorting the remaining elements after the critical:
        nums[critical:] = sorted(nums[critical:])