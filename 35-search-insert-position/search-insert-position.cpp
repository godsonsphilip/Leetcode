class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        ans = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        return ans;
    }
};