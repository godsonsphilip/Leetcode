class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int increasing = 1, decreasing = 1;

        //For maintaining the global maximum:
        int result = 0;

        for(int i = 0; i<n-1; i++){
            //Increasing Function:
            if(nums[i]<nums[i+1]){
                increasing++;
                decreasing = 1;
            }

            else if(nums[i]>nums[i+1]){
                decreasing++;
                increasing = 1;
            }

            else {
                increasing = 1; decreasing = 1;
            }

            result = max(result, max(increasing, decreasing));
        }
       
        return result;
    }
};