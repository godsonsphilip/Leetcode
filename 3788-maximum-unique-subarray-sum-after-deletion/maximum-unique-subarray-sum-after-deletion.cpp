class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        unordered_set<int> positives;
        for(int n: nums){
            if(n>0) positives.emplace(n);
        }
        if(positives.empty()) return *max_element(nums.begin(), nums.end());
        return accumulate(positives.begin(), positives.end(), 0LL);
    }
};