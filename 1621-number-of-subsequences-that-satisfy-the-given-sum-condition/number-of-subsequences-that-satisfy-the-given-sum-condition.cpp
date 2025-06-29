class Solution {
public:
    const int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        vector<int> a(n+1, 1);
        for(int i = 1; i<n+1; i++){
            a[i] = (2*a[i-1]) % mod;
        }
       if(!is_sorted(nums.begin(), nums.end())){ sort(nums.begin(), nums.end());}
        int l = 0, r = n-1;
        while(l<=r){
            if(nums[r]+nums[l] <= target){
                ans =(ans + a[r-l]) % mod;
                l++;
            }
            else{
                r--;
                continue;
            }
        }

        return ans % mod;
    }
};