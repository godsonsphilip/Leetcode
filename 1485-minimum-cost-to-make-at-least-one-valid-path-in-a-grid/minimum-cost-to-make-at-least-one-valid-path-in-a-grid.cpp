class Solution {
public:
    bool isValid(int& x, int& y, int& m, int& n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Min-Heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        pq.push(make_pair(0, make_pair(0,0)));
        while (!pq.empty()) {
            auto [cost, cor] = pq.top();
            pq.pop();

            int x = cor.first;
            int y = cor.second;

            if (vis[x][y]) continue;

            if (x == m - 1 && y == n - 1) {
                return cost;
            }

            vis[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (isValid(newx, newy, m, n) && !vis[newx][newy]) {
                    int nc = cost + ((i + 1 == grid[x][y]) ? 0 : 1);
                    pq.push({nc, {newx, newy}});
                }
            }
        }
        return -1; // In case no path is found
    }
};
