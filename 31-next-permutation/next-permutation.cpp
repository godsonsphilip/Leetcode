class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Optimal Approach: 

        // int n = nums.size();
        // int ind = -1;

        // //Finding the Breakpoint for the longest-Prefix Match:
        // for(int i = n-2; i>=0; i--){
        //     if(nums[i]<nums[i+1]){
        //         ind = i;
        //         break;
        //     }
        // }

        // if(ind==-1){
        //     reverse(nums.begin(), nums.end());
        //     // for(auto& i: nums) cout<<i<<" ";
        //     return;
        // }

        // for(int i = n-1; i>ind; i--){
        //     if(nums[i]>nums[ind]){
        //         swap(nums[i], nums[ind]);
        //         break;
        //     }
        // }

        // sort(nums.begin()+ind+1, nums.end());


        //Using STL:
        next_permutation(nums.begin(), nums.end());
        return;
        
    }
};