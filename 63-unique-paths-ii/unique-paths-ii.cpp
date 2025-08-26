class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dp, obstacleGrid, m-1, n-1);
    }

    int solve(vector<vector<int>>& dp, vector<vector<int>>& arr, int i, int j){
        if(i==0 and j==0) {
            if(arr[i][j]==0) return 1;
            return 0;
        }
        if(i<0 or j<0) return 0;
        if(arr[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = solve(dp, arr, i-1, j);
        int right = solve(dp, arr, i, j-1);
        dp[i][j] = left + right;
        return dp[i][j];
    }
};