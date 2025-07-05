class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i<n){
            if(i!=0 and nums[i]==nums[i-1]){
                i++;
                continue;
            }
            int left = i+1, right = n-1;
            int val = nums[i];
            while(left<right){
                if(left!=i+1 and nums[left]==nums[left-1]){
                    left++;
                    continue;
                }
                if(right!=n-1 and nums[right]==nums[right+1]){
                    right--;
                    continue;
                }
                if(nums[left]+nums[right]==-val){
                    result.push_back({val, nums[left], nums[right]});
                    left++;
                    continue;
                }
                if(nums[left] + nums[right] > -val){
                    right--;
                    continue;
                }
                left++;
            }
            i++;
        }
        return result;
    }
};