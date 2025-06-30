class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        if(!is_sorted(nums.begin(), nums.end())) sort(nums.begin(), nums.end());
        unordered_map<int, int> myMap;
        for(int i = 0; i<n; i++) myMap[nums[i]] = i;
        for(int i = 0; i<n; i++){
            int val = nums[i];
            if(find(nums.begin(), nums.end(), val+1)==nums.end()) continue;
            maxi = max(maxi, (myMap[val+1]-i+1));
        }
        
        return maxi;
    }
};