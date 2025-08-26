class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dp, m-1, n-1);
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