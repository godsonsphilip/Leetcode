class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 and j==0) continue;
                int left = 0, right = 0;
                if(j>0)  left = dp[i][j-1];
                if(i>0) right = dp[i-1][j];
                dp[i][j] = left + right;
            }
        }
        return dp[m-1][n-1];
    }

    int solve(vector<vector<int>>& dp, int i, int j){
        if(i==0 and j==0) return 1;
        if(j<0 or i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = solve(dp, i, j-1);
        int right = solve(dp, i-1, j);
        return dp[i][j] = left + right;
    }
};