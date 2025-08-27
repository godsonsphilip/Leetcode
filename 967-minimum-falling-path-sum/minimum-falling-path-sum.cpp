class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 0), temp(n, 0);
        for(int i = 0; i<n; i++){
            dp[i] = matrix[n-1][i];
        }

        for(int i = n-2; i>=0; i--){
            fill(temp.begin(), temp.end(), 0);
            for(int j = n-1; j>=0; j--){
                int diag_left = INT_MAX, diag_right = INT_MAX;
                int down = dp[j];
                if(j>0) diag_left = dp[j-1];
                if(j<n-1) diag_right = dp[j+1];

                temp[j] = min(down, min( diag_left, diag_right)) + matrix[i][j];
            }
            dp = temp;
        }
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            ans = min(ans, dp[i]);
        }   
        return ans;
    }

    int solve(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i, int j){
        if(i==matrix.size()-1) return matrix[i][j];
        if(j<0 or j>matrix.size()-1) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int diag_left = INT_MAX, diag_right = INT_MAX;
        int down = solve(dp, matrix, i+1, j);
        if(j>0) diag_left = solve(dp, matrix, i+1, j-1);
        if(j<matrix.size()-1) diag_right = solve(dp, matrix, i+1, j+1);

        return dp[i][j] = matrix[i][j] + min(down, min(diag_left, diag_right));
    }
};