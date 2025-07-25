class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n =nums.size();
        int result = 0;
        for(int i: nums) mpp[i]++;
        for(auto it : mpp){
            if(it.second > n/2){
               result = it.first;
               break;
            }
        }
       return result;
    }
};