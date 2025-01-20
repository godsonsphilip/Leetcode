class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> myMap;
        for(int i =0; i<n; i++){
            int p = target-nums[i];
            if(myMap.find(p)==myMap.end())
            myMap[nums[i]] = i;
            else {
                auto it = myMap.find(p);
                int t = it->second;
                result.push_back(i);
                result.push_back(t);
                break;
            }
        }
        return result;
    }
};