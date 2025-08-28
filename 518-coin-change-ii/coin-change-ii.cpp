class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(amount, n-1, dp, coins);
    }

    int solve(int target, int index, vector<vector<int>>& dp, vector<int>& coins){
        if(index==0){
            if(target%coins[index]==0) return 1;
            return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int take = 0;
        if(coins[index]<=target) take = solve(target-coins[index], index, dp, coins );
        int skip = solve(target, index-1, dp, coins);
        return dp[index][target] = take + skip;
    }
};