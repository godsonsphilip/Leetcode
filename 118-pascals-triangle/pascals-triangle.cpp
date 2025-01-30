class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> result;
        result.push_back({1});
        
        for (int i = 1; i < n; i++) {
            vector<int> row;
            vector<int> prev = result.back();
            
           
            vector<int> temp;
            temp.push_back(0);
            for(int j =0; j<prev.size(); j++)
            temp.push_back(prev[j]);
            temp.push_back(0);
            
            // Compute middle elements
            for (int j = 0; j < prev.size()+1; j++) {
                row.push_back(temp[j] + temp[j+1]);
            }
            
           
            
            
            result.push_back(row);
        }
        
        return result;
    }
};
