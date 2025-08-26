class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int index){
        int n = nums.size();
        if(index==0){
             return nums[index];
        }
        if(index<0) return 0;
        if(dp[index]!=-1)  return dp[index];

        int right = solve(dp, nums, index-1);
        int left = nums[index] + solve(dp, nums, index-2);
        
        
        return dp[index] = max(left, right);
    }

    //Bottom-up Approach:
    int solve1(vector<int>& nums){
        int n = nums.size();
        int prev = nums[0], prev1 = 0, curr = prev;
        for(int i = 1; i<n; i++){
            int pick = nums[i] + prev1;
            int notpick = prev;
            curr = max(pick, notpick);

            prev1 = prev;
            prev = curr;
            
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n, -1), dp2(n,-1), nums1, nums2;
        for(int i = 0; i<n; i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }

        return max(solve1(nums1), solve1(nums2));
    }
};