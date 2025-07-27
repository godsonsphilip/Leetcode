class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int i = 0, j = 1;
        while(i<j and j<n){
            if(i==0 || i==n-1){
                i++;
                j++;
                continue;
            }
            while(j<n and nums[i]==nums[j]){
                j++;
            }   
            if(j<n){if(nums[i] > nums[i-1] and nums[i] > nums[j] ){
                count++;
                cout<<nums[i]<<" ";
            }
            if(nums[i] < nums[i-1] and nums[i] < nums[j]){
                count++;
                cout<<nums[i]<<" ";
            }
            i = j;
            j++;}

        }
        return count;
    }
};