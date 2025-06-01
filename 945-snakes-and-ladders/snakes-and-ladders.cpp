class Solution {
public:
    vector<int> findcord(int n, int size) {
        int row = size - 1 - (n - 1) / size;
        int column;
        if (size % 2 == 0 ){
            if(row%2==0)  column = size - 1 - (n - 1) % size;
            else 
            column = (n - 1) % size;
        }
        else
            if(row%2==0)  column = (n - 1) % size;
            else column = size - 1 - (n - 1) % size;
        return {row, column};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> visit(n, vector<int>(n,0));
        queue<int> q;
        q.push(1);
        visit[n-1][0] = 1;
        int rolls = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int val = q.front();
                q.pop();
                if (val == n * n) return rolls;

                for (int i = 1; i <= 6; i++) {
                    int curr = val + i;
                    if (curr > n * n) continue;
                    auto temp = findcord(curr, n);
                    int x = temp[0], y = temp[1];
                    if (visit[x][y]) continue;
                    visit[x][y] = 1;
                    int dest = board[x][y] == -1 ? curr : board[x][y];
                    q.push(dest);
                   
                }
            }
            rolls++;
        }

        return -1;
    }
};
