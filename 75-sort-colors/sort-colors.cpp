class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Slightly better Approach: T.C. O(2*n);
        int c0 = 0, c1 = 0, c2 = 0;
        for(int i: nums) {
            if(i==0) c0++;
            else if(i==1) c1++;
            else c2++;
        }

        for(int i = 0; i<c0; i++){
            nums[i] = 0;
        }
        for(int i = 0; i<c1; i++) nums[i + c0] = 1;
        for(int i = c0+c1; i<nums.size(); i++) nums[i] = 2;
    }
};