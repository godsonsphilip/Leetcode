class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0, length = 0;

        if (!is_sorted(nums.begin(), nums.end()))
            sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        while(j<n){
            if(nums[j]-nums[i] == 1) maxi = max(maxi, j-i+1);
            while(nums[j]-nums[i]>1) i++;
            j++;
        }

        return maxi;
    }
};