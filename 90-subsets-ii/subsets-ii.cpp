class Solution {
public:
    void backtrack(int index, vector<vector<int>>& result, vector<int>& ds,
                   vector<int> nums) {
        
            result.push_back(ds);
            
        
        for(int i = index; i<nums.size(); i++)
        {
            if(i>index and nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            backtrack(i + 1, result, ds, nums);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ds;
        backtrack(0, result, ds, nums);
        return result;
    }
};