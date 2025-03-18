class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        int currSum = 0; // Represents the bitwise OR of the current window

        // Sliding Window Technique:
        int i = 0, j = 0;
        while (j < n) {
            // If the current element overlaps with the current window, shrink the window
            while ((currSum & nums[j]) != 0 && i < j) {
                currSum ^= nums[i]; // Remove nums[i] from the window
                i++;
            }

            // Add nums[j] to the window
            currSum |= nums[j];

            // Update the maximum length of the nice subarray
            maxLength = max(maxLength, j - i + 1);

            // Move the right pointer
            j++;
        }

        return maxLength;
    }
};