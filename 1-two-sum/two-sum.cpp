class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
       unordered_map<int, int> myMap;
       int y = -1, t = -1;
       for(int i= 0; i<n; i++){
        int x = target - nums[i];
        if(myMap.find(x) != myMap.end()){
            t = myMap[x];
            y = i;
            break;
        }
        myMap[nums[i]] =  i;
       }
       return {y,t};
    }
};