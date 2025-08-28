class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        int ans = solve(prices, dp, 0, 1, 0);
        return (ans == INT_MIN) ? 0 : ans;
    }

    int solve(vector<int>& prices, vector<vector<vector<int>>>& dp, int index, int buy, int count){
        if(count==2) return 0;
        int n = prices.size();
        if(index==n) return 0;
        if(dp[index][buy][count]!=-1) return dp[index][buy][count];

        int profit1 = INT_MIN, profit2 = INT_MIN;
        if(buy){
            profit1 = -prices[index] + solve(prices, dp, index+1, 0, count);
            profit2 = 0 + solve(prices, dp, index+1, 1, count);
        }
        else{
            profit1 = prices[index] + solve(prices, dp, index+1, 1, count+1);
            profit2 = 0 + solve(prices, dp, index+1, 0, count);

        }
        return dp[index][buy][count] = max(profit1, profit2);
    }
};