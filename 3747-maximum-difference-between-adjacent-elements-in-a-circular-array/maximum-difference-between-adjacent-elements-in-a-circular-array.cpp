class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        for(int i = 0; i<n-1; i++){
            int a = abs(nums[i]-nums[i+1]);
            ans = max(ans, a);
        }

        int t = abs(nums[0]-nums[n-1]);
        ans = max(t, ans);

        return ans;
    }
};