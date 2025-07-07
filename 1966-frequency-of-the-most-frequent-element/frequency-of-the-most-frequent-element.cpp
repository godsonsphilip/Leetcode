class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 1;
        int l = 0, r = 0;
        long long total = 0 ;
        sort(nums.begin(), nums.end());
        while(l<=r and r<n){
            total += nums[r];
            int length = r-l+1;
            while((long long)nums[r]*(r-l+1) > (long long)total + k){
                total -= nums[l];
                l++;
            }

            maxi = max(maxi, r-l+1);
            r++;
            
        }
        return maxi;
    }
};