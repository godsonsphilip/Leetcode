class Solution:
    def largestGoodInteger(self, num: str) -> str:
        mpp = set()
        n = len(num)
        result = ''
        left, right = 0, 0
        
        while right < n:
            # Check for a block of same digits
            left = right
            while right < n and num[right] == num[left]:
                right += 1
            
            # If length of block >= 3, store digit
            if right - left >= 3:
                mpp.add(num[left])
        
        # If no triple found, return empty string
        if not mpp:
            return ''
        
        # Get largest digit and form result
        a = max(mpp)
        return a * 3
