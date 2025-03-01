class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int i = 0;
        while(i!=n-1){
            if(nums[i]==nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
            i++;
        }

        int l = 0, r = 0;

        //Two pinter Method:
        while(r<n){
            if(nums[l]==0 && nums[r]!=0){
                swap(nums[l], nums[r]);
                l++;
                r++;
            }
            else if(nums[l]==0 && nums[r]==0){
                r++;
            }

            else if(nums[l]!=0){ l++; r++;}
        }
        return nums;
    }
};