class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>((sum / 2)+1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        if(nums[0]<=(sum/2))dp[0][nums[0]] = 1;
        for (int i =1; i < n; i++) {
            for (int j = 1; j <= (sum / 2); j++) {
                bool left = false, right = false;
                if (nums[i] <= j)
                    left = dp[i - 1][j - nums[i]];
                right = dp[i - 1][j];
                dp[i][j] = left | right;
            }
        }

        return dp[n - 1][sum / 2];
    }

    bool solve(vector<vector<int>>& dp, vector<int>& nums, int index,
               int target) {
        if (target == 0)
            return true;
        if (index < 0)
            return false;
        if (dp[index][target] != -1)
            return dp[index][target];
        bool left = false;
        if (nums[index] <= target)
            left = solve(dp, nums, index - 1, target - nums[index]);
        bool right = solve(dp, nums, index - 1, target);
        return dp[index][target] = right || left;
    }
};