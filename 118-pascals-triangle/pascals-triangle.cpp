class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> result;
        result.push_back({1});
        
        for (int i = 1; i < n; i++) {
            vector<int> row;
            vector<int> prev = result.back();
            
            // First element is always 1
            row.push_back(1);
            
            // Compute middle elements
            for (int j = 1; j < prev.size(); j++) {
                row.push_back(prev[j - 1] + prev[j]);
            }
            
            // Last element is always 1
            row.push_back(1);
            
            result.push_back(row);
        }
        
        return result;
    }
};
