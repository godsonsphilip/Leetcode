class Solution {
public: 
    //Top-down Approach:
    int solve(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int left = nums[ind] + solve(ind-2, nums, dp);
        int right = solve(ind-1, nums, dp);
        return dp[ind] = max(left, right);
    }


    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n+1, -1);
       int ans = solve(n-1, nums, dp);
       return ans;
    }
};