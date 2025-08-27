class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(backtrack(i, j, 0, board, word))return true;
            }
        }
        return false;
    }

    bool backtrack(int i, int j, int k, vector<vector<char>>& board, string word){
        int row = board.size(), col = board[0].size();
        if(k==word.size()) return true;
        if(i<0 or i>=row or j<0 or j>=col or board[i][j] != word[k]) return false;
        auto temp = board[i][j];
        board[i][j] = '0';
        if(backtrack(i-1, j, k+1, board, word) | backtrack(i, j-1, k+1, board, word) | backtrack(i, j+1, k+1, board, word) | backtrack(i+1, j, k+1, board, word)) return true;
        board[i] [ j] = temp;
        return false;
    }
};