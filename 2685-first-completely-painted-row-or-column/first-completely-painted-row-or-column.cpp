class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int index = -1;
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, int> rowPos, colPos;
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<n; j++){
                rowPos[mat[i][j]] = i;
                colPos[mat[i][j]] = j;
            }
        }

        unordered_map<int, int> row, col;
        for(int i = 0; i<arr.size(); i++){
            int val = arr[i];
            row[rowPos[val]]++;
            col[colPos[val]]++;
            if(row[rowPos[val]]==n || col[colPos[val]]==m)
            {
               index = i;
               break;
            }
        }
        return index;
    }
};