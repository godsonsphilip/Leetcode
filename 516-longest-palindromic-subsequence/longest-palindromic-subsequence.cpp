class Solution {
public:
    int longestPalindromeSubseq(string s) {
        auto s2 = s;
        reverse(s2.begin(), s2.end());
        string s1 = s2;
        int maxi = 0;
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1]==s1[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};