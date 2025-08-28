class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                int profit1 = INT_MIN, profit2 = INT_MIN;
                if (j) {
                    profit1 = -prices[i] + dp[i + 1][0];
                    profit2 = 0 + dp[i + 1][1];
                } else {
                    profit1 = prices[i] + dp[i + 1][1];
                    profit2 = dp[i + 1][0];
                }
                dp[i][j] = max(profit1, profit2);
            }
        }

        int t = dp[0][1];
        return (t == INT_MIN) ? 0 : t;
    }

    int solve(vector<int>& prices, vector<vector<int>>& dp, int index,
              int flag) {
        if (index == prices.size())
            return 0;
        if (dp[index][flag] != -1)
            return dp[index][flag];
        int profit1 = INT_MIN, profit2 = INT_MIN;
        if (flag) {
            profit1 = -prices[index] + solve(prices, dp, index + 1, 0);
            profit2 = 0 + solve(prices, dp, index + 1, 1);
        } else {
            profit1 = prices[index] + solve(prices, dp, index + 1, 1);
            profit2 = solve(prices, dp, index + 1, 0);
        }
        return dp[index][flag] = max(profit1, profit2);
    }
};