class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        result = ''
        for i in range(0, n-2):
            if num[i]==num[i+1]==num[i+2]:
                cand = num[i:i+3]
                if cand>result:
                    result = cand
        return result