class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int mval =0, curr = 0;
        if(n==1) return 1;
       
       for(auto& i: nums){
        if(mval < i){
            mval = i;
            maxi = curr = 0;
        }
        if(mval == i) curr++;
        else curr = 0;

        maxi = max(curr, maxi);
       }
        return maxi;
    }
};