class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n<1: return False
        while n!= 1:
            rem = n%4
            if rem :
                return False
            n //= 4
        return True