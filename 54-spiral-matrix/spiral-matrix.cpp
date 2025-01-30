class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int top = 0, bottom = r, left = 0, right = c;
        vector<int> result;
        while(top<bottom and left<right){
            //Moving towards right direction:
            for(int i = left; i<right; i++){
                result.push_back(matrix[left][i]);
            }
            top++;

            //Moving down:
            for(int i = top; i<bottom; i++){
                result.push_back(matrix[i][right-1]);
            }
            right--;

            if(top>=bottom || left>=right) break; //Applying this condition for the edge case of a row vector or a column vector

            //Moving left:
            for(int i = right-1; i>=left; i--){
                result.push_back(matrix[bottom-1][i]);
            }
            bottom--;

            //Moving up:
            for(int i = bottom-1; i>=top; i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};