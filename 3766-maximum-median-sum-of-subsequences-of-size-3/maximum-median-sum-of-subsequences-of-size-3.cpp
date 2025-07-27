class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        if(!is_sorted(nums.begin(), nums.end())) sort(nums.begin(), nums.end());
        for(int i = n-2; i>=(n/3); i-=2){
            sum += nums[i];
        }
        return sum;
    }
};
