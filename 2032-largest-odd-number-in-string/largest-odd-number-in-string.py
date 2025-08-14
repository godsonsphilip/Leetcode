class Solution:
    def largestOddNumber(self, num: str) -> str:
        result = ''
        n = len(num)
        for i in range(n-1, -1, -1):
            a = int(num[i])
            if a%2!=0:
                result = num[:i+1]
                break
            
        return result