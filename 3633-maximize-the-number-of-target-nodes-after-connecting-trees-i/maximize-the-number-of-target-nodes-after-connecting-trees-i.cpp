class Solution {
public:
    int bfs(int src, vector<vector<int>>& adj, int k, int n) {
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        int ans = 0;
        while (!q.empty() && k >= 0) {
            int size = q.size();
            ans += size;
            for (int j = 0; j < size; j++) {
            
            int val = q.front();
            q.pop();
            for (auto& i : adj[val]) {
                if (vis[i] == 0) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        k--;
    }
    return ans;
}

vector<int>
maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2,
               int k) {
    int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
    vector<vector<int>> adj1(n1), adj2(n2);
    // Adjacency list for first graph:
    for (auto& i : edges1) {
        adj1[i[0]].push_back(i[1]);
        adj1[i[1]].push_back(i[0]);
    }

    // Adjacency List for second graph:
    for (auto& i : edges2) {
        adj2[i[0]].push_back(i[1]);
        adj2[i[1]].push_back(i[0]);
    }

    // find the best source in graph-2 giving the max. number of targets:
    int best = 0;
    for (int i = 0; i < n2; i++) {
        int connections = bfs(i, adj2, k - 1, n2);
        best = max(best, connections);
    }
    cout << best;

    // For each node in graph-1, we need to find the targest that too maximum:
    vector<int> result;
    for (int i = 0; i < n1; i++) {
        int connections = bfs(i, adj1, k, n1);
        int ans = connections + best;
        result.push_back(ans);
    }
    return result;
}
}
;