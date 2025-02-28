class Solution {
public:
    int myAt(string s, int t, int sign , long ans) {
        int n = s.length();

        if (t == 0) {
            // Just to remove the leading white spaces:
            while (t < n && s[t] == ' ') {
                t++;
            }

            // Checking thr signs:
            if (s[t] == '-' || s[t] == '+') {
                sign = (s[t] == '-') ? -1 : 1;
                t++;
            }

            // Skipping the leading zeroes:
            while (t < n and s[t] == '0') {
                t++;
            }
        }

        // Checking whether the character is a non-integer or not?

        if ( t >= n or !isdigit(s[t]))
            return ans * sign;
        ans = ans * 10 + (s[t]-'0');
        t++;
        if (ans * sign >= INT_MAX)
            return INT_MAX;
        if (ans * sign <= INT_MIN)
            return INT_MIN;
        return myAt(s, t, sign, ans);
    }

    int myAtoi(string s){
        return myAt(s, 0, 1, 0);
    }
};