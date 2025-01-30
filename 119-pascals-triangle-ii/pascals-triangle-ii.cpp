class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> resultRow = {1};
        for(int i = 0; i<rowIndex; i++){
            vector<int> next_Row(resultRow.size()+1, 0);
            for(int j = 0; j<resultRow.size(); j++){
                next_Row[j] += resultRow[j];
                next_Row[j+1] += resultRow[j];
            }
            resultRow = next_Row;
        }
        return resultRow;
    }
};