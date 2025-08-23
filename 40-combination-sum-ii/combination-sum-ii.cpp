class Solution {
public:

    void backtrack(int index, vector<int>& ds, vector<vector<int>>& result, vector<int> candidates, int target){
        int n = candidates.size();
      
            if(target==0 ) {result.push_back(ds);
            return;}
        

        // In hunt of the first element avoiding duplicate subsequences:
        for(int i = index; i<n; i++){
            if(i>index and candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            backtrack(i+1, ds, result, candidates, target - candidates[i]);
            ds.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(0, temp, result, candidates, target);
        return result;
    }
};