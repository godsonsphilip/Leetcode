class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int t = solve(prices, dp, 0, 1);
        return (t==INT_MIN) ? 0 : t;
    }

    int solve(vector<int>& prices, vector<vector<int>>& dp, int index, int flag){
        if(index==prices.size()) return 0;
        if(dp[index][flag]!=-1) return dp[index][flag];
        int profit1 = INT_MIN, profit2 = INT_MIN;
        if(flag){
            profit1 = -prices[index] + solve(prices, dp, index+1, 0);
            profit2 = 0 + solve(prices, dp, index+1, 1);
        }
        else{
            profit1 = prices[index] + solve(prices, dp, index+1, 1);
            profit2 = solve(prices, dp, index+1, 0);
        }
        return dp[index][flag] = max(profit1, profit2);
    }
};