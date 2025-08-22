class Solution {
public:
    void backtrack(int index, vector<int>& ds, vector<vector<int>>& result, int target, vector<int>& candidates){
        int n = candidates.size();
        if(target==0){
            if(find(result.begin(), result.end(), ds)==result.end()) result.push_back(ds);
            return;
        }

        if(index>=n) return;

        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            backtrack(index, ds, result, target-candidates[index], candidates);
            ds.pop_back();
        }

        backtrack(index+1, ds, result, target, candidates);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(0, temp, result, target, candidates);
        return result;
    }
};