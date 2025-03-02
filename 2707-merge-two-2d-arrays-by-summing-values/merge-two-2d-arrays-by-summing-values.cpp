class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        map<int, int> myMap;
        for (auto& i : nums1) {
            myMap[i[0]] += i[1];
        }
        for (auto& i : nums2) {
            myMap[i[0]] += i[1];
        }
        for (auto& i : myMap) {
            int a = i.first;
            int b = i.second;
            result.push_back({a, b});
        }
       
        return result;
    }
};