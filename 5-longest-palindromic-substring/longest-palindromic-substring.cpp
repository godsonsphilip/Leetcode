class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int max_length = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int l = i, r = i;

            // Odd length :
            while (l >= 0 and r < n and s[l] == s[r]) {
                if (r - l + 1 > max_length) {
                    max_length = r - l + 1;
                    result = s.substr(l, max_length);
                }
                l--;
                r++;
            }

            // Even Length palindrome:
            l = i;
            r = i + 1;
            while (l >= 0 and r < n and s[l] == s[r]) {
                if (r - l + 1 > max_length) {
                    max_length = r - l + 1;
                    result = s.substr(l, max_length);
                }
                l--;
                r++;
            }
        }
        return result;
    }
};