class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n<1 : return False
        while n!=1:
            rem = n%3
            if rem : return False
            n //= 3
        return True