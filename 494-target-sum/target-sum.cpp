class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2*sum + 1, -1));
        return solve(nums, dp, target, n-1 , 0, sum);
    }

    int solve(vector<int>& nums, vector<vector<int>>& dp,int target,  int index, int sum, int total){
        if(index<0) return (target==sum);
        if (sum + total < 0 || sum + total >= 2 * total + 1) return 0;

        if(dp[index][sum+total]!=-1) return dp[index][sum+total];
        int take = solve(nums, dp, target, index-1, sum+nums[index], total);
        int skip = solve(nums, dp, target, index-1, sum-nums[index], total);
        return dp[index][sum+total] = take + skip;
    }
};