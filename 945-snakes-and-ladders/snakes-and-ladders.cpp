class Solution {
public:
    vector<int> findcord(int n, int size) {
        int row = size - 1 - (n - 1) / size;
        int column;
        if (size % 2 == 0) {
            if (row % 2 == 0)
                column = size - 1 - (n - 1) % size;
            else
                column = (n - 1) % size;
        } else if (row % 2 == 0)
            column = (n - 1) % size;
        else
            column = size - 1 - (n - 1) % size;
        return {row, column};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        // First Do the BFS of each pposition starting from 1 and going all the
        // way to n*n Then For each dice value + curr, this gives your adjacency
        // value for the popped out item Then find the ACTUAL COORDINATES by
        // basic maths Return the minMoves:
        int n = board.size();
        vector<vector<int>> visit(n, vector<int>(n,0));
        queue<int> q;
        q.push(1);
        visit[n-1][0] = 1;
        int rolls = 0;

        // Level Order Traversal:
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                int val = q.front();
                if (val == n * n)
                    return rolls;
                q.pop();
                for (int i = 1; i <= 6; i++) {
                    int curr = val + i;
                    if (curr > n * n)
                        break;
                    
                    auto temp = findcord(curr, n);
                    int x = temp[0];
                    int y = temp[1];
                    int val2 = board[x][y];
                    if (!visit[x][y]) {
                        visit[x][y] = 1;
                        if (val2 == -1) {
                            q.push(curr);
                        } else  {
                            q.push(val2);
                            
                        }
                    }
                }
                size--;
            }
            rolls++;
        }
        return -1;
    }
};