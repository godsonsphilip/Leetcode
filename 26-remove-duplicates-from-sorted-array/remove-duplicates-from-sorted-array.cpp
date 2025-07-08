class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1, n = nums.size();
        while(right<nums.size()){
            while(right<n and nums[right]==nums[left]){
                right++;
            }
          if(right<n) 
          { left++;
           nums[left] = nums[right];
           right++;}
        }

        return left+1;
    }
};