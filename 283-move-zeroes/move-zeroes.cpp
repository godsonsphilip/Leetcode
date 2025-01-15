class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 1;

        while (right < n) {
            if (nums[right] != 0 && nums[left] == 0) {
                swap(nums[right], nums[left]);
                left++;
                right++;
            } else {
                if (nums[left] != 0)
                    { left++;
                    right++;}
                else if (nums[right] == 0) {
                   right++;
                }
            }
        }
    }
};