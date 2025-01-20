class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n == 0)
            return {{}};
        vector<vector<int>> r;
        vector<int> p(nums.begin() + 1, nums.end());
        r = permute(p);
        int o = nums[0];

        for (int i = 0; i < r.size(); i++) {

            for (int j = 0; j <= r[i].size(); j++) {
                auto a = r[i];
                a.insert(a.begin() + j, o);
                result.push_back(a);
            }
        }

        if (r.empty()) {
            result.push_back({o});
        }

        return result;
    }
};


