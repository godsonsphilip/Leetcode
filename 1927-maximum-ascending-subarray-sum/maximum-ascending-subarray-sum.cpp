class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int result = nums[0];
        for(int i = 1; i<n; i++){
            if(nums[i]>nums[i-1]){
                sum+= nums[i];
                result = max(result, sum);
            }
            else {result = max(result, sum);sum = nums[i];}
            
        }
        return result;
    }
};