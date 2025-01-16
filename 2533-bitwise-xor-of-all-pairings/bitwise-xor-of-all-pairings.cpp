class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        int n = nums1.size();
        int m = nums2.size();

        // XOR all elements in nums1 if the size of nums2 is odd
        if (m % 2 != 0) {
            for (int num : nums1) {
                result ^= num;
            }
        }

        // XOR all elements in nums2 if the size of nums1 is odd
        if (n % 2 != 0) {
            for (int num : nums2) {
                result ^= num;
            }
        }

        return result;
    }
};
