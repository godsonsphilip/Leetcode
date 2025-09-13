class Solution:
    def maxFreqSum(self, s: str) -> int:
        vmax, cmax = 0, 0
       
        vowels = {'a', 'e', 'i', 'o', 'u'}
        freq = Counter(s);
        for i in s:
            if i in vowels:
                vmax = max(vmax, freq[i])
            else : cmax = max(cmax, freq[i])
        return vmax+cmax