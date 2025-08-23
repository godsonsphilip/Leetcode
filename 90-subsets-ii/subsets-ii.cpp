class Solution {
public:
    void backtrack(int index, vector<vector<int>>& result, vector<int>& ds, vector<int> nums){
        if(index>=nums.size()){
            if(find(result.begin(),result.end(), ds)==result.end())
            result.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        backtrack(index+1, result, ds, nums);
        ds.pop_back();
        backtrack(index+1, result, ds, nums);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ds;
        backtrack(0, result, ds, nums);
        return result;
    }
};