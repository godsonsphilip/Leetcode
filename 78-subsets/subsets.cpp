class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        int last = (1<<n)-1;
        for(int i = 0; i<=last; i++){
            vector<int> temp;
            for(int j = 0; j<n; j++){
                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            if(find(result.begin(), result.end(), temp)==result.end())
            result.push_back(temp);
        }

        return result;
    }
};