class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[low] and nums[mid]==nums[high]){
                low++; high--; continue;
            }

            //Check for left Sorted:
            if(nums[low]<=nums[mid]){
                if(nums[mid]>=target and target>= nums[low]){
                    high = mid - 1;
                    continue;
                }
                else low = mid + 1;
            }
            else{
                if(nums[mid]<= target and nums[high] >= target){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return false;
    }
};