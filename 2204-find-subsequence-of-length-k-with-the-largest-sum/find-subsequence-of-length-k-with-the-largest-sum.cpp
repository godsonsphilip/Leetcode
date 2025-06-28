class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n) return nums;
        if(k==1) return {*max_element(nums.begin(), nums.end())};
        vector<int> result;
        auto temp = nums;
        sort(temp.rbegin(), temp.rend());
        vector<int> temp1;
        for(int i = 0; i<k; i++) temp1.push_back(temp[i]);
        unordered_map<int, int> freqMap;

        for(auto& i: temp1) freqMap[i]++;
        for(auto& i: nums){
            if(freqMap[i]==0) continue;
            freqMap[i]--;
            result.push_back(i);
        }

        return result;
    }
};