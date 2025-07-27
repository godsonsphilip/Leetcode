class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            //Check Which array is sorted:
            //Left side:
            if(nums[mid]>= nums[low]){
                mini = min(mini, nums[low]);
                low = mid + 1;
                continue;
            }
            //Right Side:
            else{
                mini = min(mini, nums[mid]);
                high = mid-1;
                continue;
            }
        }
        return mini;
    }
};