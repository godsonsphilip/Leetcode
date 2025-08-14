class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        result = []
        n = len(nums)
        positive, negative = 0, 0
        while positive<n and negative<n:
            while positive<n and nums[positive]<0:
                positive+=1
            if positive<n : 
                result.append(nums[positive])
                positive+=1

            while negative<n and nums[negative]>0 :
                negative += 1
            if negative<n:
                result.append(nums[negative])
                negative += 1
            
        return result