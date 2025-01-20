class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
         // Set to track unique triplets
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int l = i+1;
            int r = n-1;
            int val = nums[i];
            while(l<r){
                if((l!=i+1 && nums[l]==nums[l-1] )) {
                    l++;
                    continue;}

                if( (r!=n-1 && nums[r]==nums[r+1])) {
                    r--;
                    continue;
                }
                vector<int> s;
                if(nums[l]+nums[r]==(-val)) {
                    s = {val,nums[l],nums[r]};
                    result.push_back(s);
                    l++;
                    continue;
                }

                if(nums[l]+nums[r]>(-val)){
                    r--;
                    continue;
                }

                l++;

            }
        }
        
        return result;
    }
};
