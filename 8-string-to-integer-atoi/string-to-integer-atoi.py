class Solution:
    def myAtoi(self, s: str) -> int:
        # 1. Check for the whitespaces:
        # 2. Check for the sign
        # 3. check for the leading zeroes
        # 4. Check for the non-digit characters
        # 5. stop untill the end or overfow happens
        n = len(s)

        def solve(index, sign, ans):
            if index == 0:
                while index < n and s[index] == " ":
                    index += 1

                if index < n and (s[index] == "+" or s[index] == "-"):
                    sign = -1 if s[index] == "-" else 1
                    index += 1

                while index < n and s[index] == "0":
                    index += 1

            if index >= n or not s[index].isdigit():
                return ans * sign

            ans = ans * 10 + int(s[index])
            index += 1
            if sign == 1 and ans > 2**31 - 1:
                return 2**31 - 1
            if sign == -1 and ans > 2**31:
                return -(2**31)
            return solve(index, sign, ans)

        return solve(0, 1, 0)
