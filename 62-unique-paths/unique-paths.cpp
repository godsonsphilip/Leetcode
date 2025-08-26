class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[0][0] = 1;
        vector<int> dp(n,0), temp(n,0);
        
        for(int i = 0; i<m; i++){
            fill(temp.begin(), temp.end(), 0);  // Efficient and safe

            for(int j = 0; j<n; j++){
                if(j==0 and i==0){ temp[i] = 1;continue;}
                int left = 0, right = 0;
                if(j>0)  left = temp[j-1];
                temp[j] = left + dp[j];
            }
            dp = temp;
            
        }
        return dp[n-1];
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