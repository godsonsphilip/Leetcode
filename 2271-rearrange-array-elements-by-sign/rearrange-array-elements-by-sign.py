class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0]*n
        positive, negative = 0, 1
        for i in range(0, n):
            if nums[i] < 0:
                result[negative] = nums[i]
                negative += 2
            
            else:
                result[positive] = nums[i]
                positive += 2
            

        return result