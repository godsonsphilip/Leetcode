class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        map<int, vector<int>> myMap;
        for(auto& i: arr){
            int t = __builtin_popcount(i);
            myMap[t].push_back(i);
        }
        for(auto& [_, val]: myMap){
            if(val.size()>1){
                sort(val.begin(), val.end());
                for(auto& i: val) result.push_back(i);
            }
            else result.push_back(val[0]);
        }
        return result;
    }
};