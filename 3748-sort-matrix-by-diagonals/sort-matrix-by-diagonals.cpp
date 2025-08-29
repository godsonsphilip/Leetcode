class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        int i = rows-1;
        while(count<rows){
            int j=0;
            vector<int> result;
            for(int k = i; k<rows; k++){
                result.push_back(grid[k][j++]);
            }
            sort(result.rbegin(), result.rend());
            j = 0;
            for(int k = i; k<rows ; k++){
                grid[k][j] = result[j];
                j++;
            }
            count++;
            i--;
        }
        int j = 1;
        while(count<2*rows-1){
                int i = 0;
                vector<int> result;
                for(int k = j; k<cols; k++){
                    result.push_back(grid[i++][k]);
                }

                sort(result.begin(), result.end());
                i = 0;
                for(int k = j; k<cols ; k++){
                    grid[i][k] = result[i];
                    i++;
                }
                count++;
                j++;
        }
        return grid;
    }
};