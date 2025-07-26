class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        long long sum = 0, ans = 0;
        unordered_map<int, int> diff;
        for(auto& i: nums){
            sum += i;
            if(sum==k) ans++;
            if(diff.count(sum-k)) ans += diff[sum-k];
            diff[sum]++;
        }
        return ans;
    }
};