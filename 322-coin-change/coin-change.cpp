class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        if(amount==0) return 0;
        int t = solve(dp, coins, amount, n-1);
        return (t==INT_MAX) ? -1 : t;
    }

    int solve(vector<vector<int>>& dp, vector<int>& coins, int target, int index){
        if(index==0){
            if(target % coins[0] ==0) return target/coins[0];
            return INT_MAX;
        }
        if(dp[index][target]!=-1) return dp[index][target];

        int take = INT_MAX;
        if(coins[index]<=target){
            int temp = solve(dp, coins, target-coins[index], index);
            if(temp!=INT_MAX) take = 1 + temp;}
        int skip = solve(dp, coins, target, index-1);
        
        return dp[index][target] = min(take, skip);
    }
};