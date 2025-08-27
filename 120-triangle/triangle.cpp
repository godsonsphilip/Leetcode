class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp(m, 0), temp(m, 0);
        for(int j = 0; j<m; j++){
            dp[j] = triangle[m-1][j];
        }

        for(int i = m-2; i>=0; i--){
            fill(temp.begin(), temp.end(), 0);
            for(int j = i; j>=0; j--){
                int down = dp[j];
                int up = dp[j+1];
                temp[j] = min(up, down) + triangle[i][j];
            }
            dp = temp;
        }
        return dp[0];
    }

    int solve(vector<vector<int>>& dp, vector<vector<int>>& triangle, int x, int y){
        int m = triangle.size();
        if(x == m-1) return triangle[x][y];
        if(dp[x][y] != -1) return dp[x][y];
        int down = triangle[x][y] + solve(dp, triangle, x+1, y);
        int diag = triangle[x][y] + solve(dp, triangle, x+1, y+1);
        return dp[x][y] = min(down, diag);
    }
};