class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a, b, c;
        for(int x : nums) {
            if(x < pivot) a.push_back(x);
            else if(x == pivot) b.push_back(x);
            else c.push_back(x);
        }
        a.insert(a.end(), b.begin(), b.end());
        a.insert(a.end(), c.begin(), c.end());
        return a;
    }
};
