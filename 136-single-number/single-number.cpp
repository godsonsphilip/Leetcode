class Solution {
public:
    int singleNumber(vector<int>& nums) { 
      int ans = 0;
      int n = nums.size();
      for(auto& i: nums) ans ^= i;
      return ans;
    }
};