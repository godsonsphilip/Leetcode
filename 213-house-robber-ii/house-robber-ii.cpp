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

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n, -1), dp2(n,-1), nums1, nums2;
        for(int i = 0; i<n; i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }

        return max(solve(dp1, nums1, nums1.size()-1), solve(dp2, nums2, nums2.size()-1));
    }
};