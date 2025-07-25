class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> myMap;
        sort(nums.begin(), nums.end()); if(nums[n-1]<0) return nums[n-1];
        for(auto& i: nums) myMap[i]++;
        for(auto& pair: myMap){
            if(pair.first>=0) sum += pair.first;
        }
        return sum;
    }
};