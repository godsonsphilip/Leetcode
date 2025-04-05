class Solution {
public:void subsetsHelper(vector<int>& nums, int index, vector<int>& current, int& xorSum) {
    if (index == nums.size()) {
        // Calculate the XOR value of the current subset
        int xorValue = 0;
        for (const auto& num : current) {
            xorValue ^= num;
        }
        
        xorSum += xorValue;  // Accumulate the XOR value

        return;
    }

    // Exclude the current element
    subsetsHelper(nums, index + 1, current, xorSum);

    // Include the current element
    current.push_back(nums[index]);
    subsetsHelper(nums, index + 1, current, xorSum);

    // Backtrack
    current.pop_back();
}
  int subsetXORSum(vector<int>& nums) {
       vector<int> current;
    int xorSum = 0;  // Variable to store the sum of XOR values

    subsetsHelper(nums, 0, current, xorSum);

    return xorSum; 
    }
};