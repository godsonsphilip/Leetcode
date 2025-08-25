class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size(), cols = mat[0].size();
        vector<int> result;
        int i = 0, j = 0;
        bool flag = false;
        while (i < row && j < cols) {
            if (!flag) {
                while (i >= 0 && j < cols) {
                    result.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                flag = true;
                if(j==cols){
                    j = cols-1; 
                    i += 1;
                }
                i += 1; // move down to next valid row
            } else {
                while (j >= 0 && i < row) {
                    result.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                flag = false;
                if(i==row){
                    i = row-1;
                    j++;
                }
                j += 1; // move right to next valid column
            }
        }

        return result;
    }
};