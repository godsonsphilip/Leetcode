class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ind = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            //Left Sorted:
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target and nums[mid]>=target){
                    high = mid -1;
                }
                else low = mid + 1;
            }
            else{
                if(nums[high]>=target and target >= nums[mid]){
                    low = mid +1 ;
                }
                else high = mid - 1;
            }
        }
            return ind;
    }
};