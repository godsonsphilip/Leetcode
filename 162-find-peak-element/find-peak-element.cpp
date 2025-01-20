class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0; int r = n-1;
        int m = 0;
        if(n==1) return 0;

        //Improvised BInary Search Mathod or Modified Binary Search Algo
        while(l<=r){
            
             m = l + (r-l)/2;
            if(m>0 and m<n-1 and nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                return m;
            }

            if(m>0 && nums[m]<nums[m-1]){
                r = m-1;
                continue;
            }
            if(m<n-1 && nums[m]<nums[m+1]){
                l = m+1;
                continue;
            }

            if(m==0 || m==n-1) break;

           

        }
         return m;
    }
};