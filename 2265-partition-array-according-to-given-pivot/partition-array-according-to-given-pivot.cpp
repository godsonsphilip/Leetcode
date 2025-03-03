class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result, a, b;
        int n = nums.size();
        for(auto& i: nums){
            if(i<pivot) result.push_back(i);
            else if(i==pivot) a.push_back(i);
            else b.push_back(i);
        }

        result.insert(result.end(), a.begin(), a.end());
        result.insert(result.end(), b.begin(), b.end());
        return result;
    }
};
