class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //Find the breakpoint:
        int ind = -1;
        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind>-1){
            int mini = nums[ind+1], miniIndex = ind+1;
            for(int i = ind + 1; i<n; i++){
                if(nums[i]>nums[ind] and nums[i]<mini) {
                    mini = nums[i];
                    miniIndex = i;
                }
            }
            swap(nums[ind], nums[miniIndex]);
            sort(nums.begin()+ind+1, nums.end());
        }
        else sort(nums.begin(), nums.end());
    }
};