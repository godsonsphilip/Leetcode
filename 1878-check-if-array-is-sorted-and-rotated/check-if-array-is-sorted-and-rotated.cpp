class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return true;
        
        int inversion = 0;
        for(int i = 1; i<n; i++){
            if(nums[i]<nums[i-1]) inversion++;
        }

        if(nums[0]<nums.back()) inversion++;
        if(inversion>1) return false;
        return true;

    }
};