class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& ds, vector<vector<int>>& result, int count, int sum){
        if(sum==0 and ds.size()==count) {result.push_back(ds); return;}

        if(index>=nums.size() or nums[index]>sum) return;

        if(ds.size()<count){
        ds.push_back(nums[index]);
        backtrack(nums, index+1, ds, result, count, sum-nums[index]);
        ds.pop_back();}
        backtrack(nums, index+1, ds, result, count, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        backtrack(nums, 0, temp, result, k, n);
        return result;
    }
};