class Solution:
    def doesAliceWin(self, s: str) -> bool:
        n = len(s)
        vowels = {'a', 'e', 'i', 'o', 'u'}
        for c in s:
            if c in vowels: return True
        return False
        