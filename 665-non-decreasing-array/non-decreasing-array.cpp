class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        auto t = nums;
        sort(t.begin(), t.end());
        if(t==nums) return true;
        int n = nums.size();
        bool changed = false;
        for(int i = 0;i<n-1; i++){
            if(nums[i]<=nums[i+1]) continue; //checks whether they are already in ascending order:
            if(changed) return false;

            //This portion signifies that the current element is greater than the next element:
            //Checking whether the current number needs to be changed or the next one:
            if(i==0 or nums[i+1]>=nums[i-1]){
                nums[i] = nums[i+1];
            }
            else {
                nums[i+1]  = nums[i];
            }
            changed = true;
        }
        return true;
    }
};