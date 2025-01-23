class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        //Vector fro storing 1's coordinates:
        vector<pair<int, int>> v;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1) v.push_back(make_pair(i,j));
            }
        }

        for(int i = 0; i<v.size(); i++){
            int row = v[i].first;
            int col = v[i].second;
            bool key = false;
            for(int j = 0; j<n; j++){
                if(j!=col and grid[row][j]==1){
                    key = true;
                    break;
                }
            }

            for(int j =0;j<m; j++){
                if(j!=row and grid[j][col]==1){
                    key = true;
                    break;
                }
            }
            if(key){
                count++;
            }
            }
        
        return count;

    }
};