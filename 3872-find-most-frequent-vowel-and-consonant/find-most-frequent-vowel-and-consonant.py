class Solution:
    def maxFreqSum(self, s: str) -> int:
        vmax, cmax = 0, 0
        freq = {}
        vowels = {'a', 'e', 'i', 'o', 'u'}
        for i in s:
            freq[i] = freq.get(i, 0) + 1
        for i in s:
            if i in vowels:
                vmax = max(vmax, freq[i])
            else : cmax = max(cmax, freq[i])
        return vmax+cmax