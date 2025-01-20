class Solution {
public:
    // void display(vector<vector<char>>& b){
    //     for(int i = 0; i<)
    // }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        // display(board);
    }

    bool solve(vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='.'){
                    for(char c = '1'; c<='9'; c++){
                        if(check(board, i, j, c)){
                            board[i][j]=c;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                                continue;
                            }
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }


    bool check(vector<vector<char>> & board, int row, int column, char c){
        for(int i = 0; i<9; i++){
            if(board[i][column]==c) return false;
            if(board[row][i]==c) return false;
            if(board[3*(row/3)+i/3][3*(column/3)+i%3]==c) return false;
            
        }
        return true;
    }
};