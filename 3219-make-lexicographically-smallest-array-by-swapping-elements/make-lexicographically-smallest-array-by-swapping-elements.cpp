class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<queue<int>> a; // List of queues for group formation.

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        if (sorted == nums) return nums; // Already sorted case

        unordered_map<int, int> indMap; // (element, queue index)

        // Distribute elements into respective queues:
        for (int val : sorted) {
            // Check the last queue in the vector `a`
            if (!a.empty() && abs(a.back().back() - val) <= limit) {
                a.back().push(val);
                indMap[val] = a.size() - 1; // Map value to last queue
            } else {
                // Create a new queue for this value
                queue<int> tmp;
                tmp.push(val);
                a.push_back(tmp);
                indMap[val] = a.size() - 1; // Map value to new queue
            }
        }

        // Construct the lexicographically smallest array:
        for (int i = 0; i < n; i++) {
            int ind = indMap[nums[i]];
            nums[i] = a[ind].front(); // Get the front of the respective queue
            a[ind].pop(); // Remove the used element
        }

        return nums;
    }
};
