class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        auto a = nums;
        for(int i = 0; i<n; i++){
            nums[(i+k)%n] = a[i];
        }
        
    }
};