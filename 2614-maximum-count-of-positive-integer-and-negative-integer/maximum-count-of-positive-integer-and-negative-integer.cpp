class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int n = nums.size();
        for(auto& i: nums){
            if(i>0) c1++;
            else if(i<0) c2++;
        }
        return max(c1, c2);
    }
};