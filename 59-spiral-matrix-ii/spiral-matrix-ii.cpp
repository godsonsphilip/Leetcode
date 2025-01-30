class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 1;
        vector<vector<int>> result(n, vector<int>(n));
        int cRow = 0, cCol = 0;
        int top = 0, bottom = n, left = 0, right = n;
        while(i<=n*n){
            //Moving right:
            for(int j = left; j<right; j++){
                result[top][j] = i;
                i++;
            }
            top++;

            //Moving down:
            for(int j = top;j<bottom; j++){
                result[j][right-1] = i;
                i++;
            }
            right--;

            if(left>=right or top>=bottom) break;

            //Moving left:
            for(int j = right-1; j>=left; j--){
                result[bottom-1][j] = i;
                i++;
            }
            bottom--;

            //Moving up:
            for(int j = bottom-1; j>=top; j--){
                result[j][left] = i;
                i++;
            }
            left++;
            
        }
        return result;
    }
};