class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k==0) return;
        vector<int> sample;
        sample.insert(sample.end(), nums.begin() + (n-k), nums.end());
        sample.insert(sample.end(), nums.begin(), nums.begin() + n - k);
        nums = sample;
    }
};