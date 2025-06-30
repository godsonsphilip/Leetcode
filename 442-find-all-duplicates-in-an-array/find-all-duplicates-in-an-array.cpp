class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i<n;i++){
            int val = abs(nums[i]);
            if(nums[val-1]<0){
                result.push_back(abs(val));
                continue;
            }
            nums[val-1] = -nums[val-1];

        }
        return result;
    }
};