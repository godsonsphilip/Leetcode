class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
       
        unordered_map<int, int> myMap;
        for(auto& i: nums) myMap[i]++;
        for(auto& [key, val]: myMap){
            if(myMap.count(key+1)!=0){
                maxi = max(maxi, val + myMap[key+1]);
            }
        }
        
        return maxi;
    }
};