class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, dp, m-1, n-1);
    }

    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
        if(i==0 and j==0)  return grid[i][j];
        if(i<0 or j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = INT_MAX, right = INT_MAX;
        if(i>0) left = grid[i][j] +  solve(grid, dp, i-1, j);
        if(j>0) right = grid[i][j] + solve(grid, dp, i, j-1);
        dp[i][j] = min(left, right);
        return dp[i][j];
    }
};