class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int count1 = 0, count2 = 0;
        int l = 0, r = 1;

        int c = 1;
        //For Decreasing Function:
        while(l<n && r<n){
            if(nums[l]>nums[r]){
                r++;
                l++;
                c++;
            }
            else {
                l = r;
                r++;
                c = 1;
            }
            count2 = max(count2, c);
        }

        l = 0; r = 1; c= 1;
        //For increasing function:
        while(l<n and r<n){
            if(nums[l]<nums[r]) {
                r++; c++; l++;
                
            }
            else{
                l = r;
                r++;
                c = 1;
            }
            count2 = max(count2, c);
        }

        return max(count1, count2);
    }
};