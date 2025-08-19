class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = 10**9 + 7
        def solve(num, count):
            result = 1
            if count==0 : return 1
            temp = solve(num, count//2)
            temp = (temp*temp) % MOD
            result = temp
            return (result*num)%MOD if count%2 else result
        even = math.ceil(n/2)
        odd = n//2
        return (solve(4, odd) * solve(5, even))%MOD