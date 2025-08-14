class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currSum = 0
        maxSum = -sys.maxsize-1
        n = len(nums)
        for i in range(0, n):
            currSum += nums[i]
            maxSum = max(currSum, maxSum)
            if currSum < 0:
                currSum = 0
        return maxSum