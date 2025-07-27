class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1) return ((nums[0]==target) ? vector<int>{0,0} : vector<int>{-1,-1});
        int l = -1, r = -1;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                int temp = mid;
                while(mid>=1 and nums[mid]==nums[mid-1]){
                    mid--;
                }
                l = mid;
                while(temp<n-1 and nums[temp]==nums[temp+1]){
                    temp++;
                }
                r = temp;
                break;
            }
            if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return{l,r};
    }
};