class Solution {
public:

    int find(int a, vector<int>& par) {
        if (a != par[a]) par[a] = find(par[a], par);
        return par[a];
    }

    bool Union(int a, int b, vector<int>& par, vector<int>& rank) {
        int pa = find(a, par), pb = find(b, par);
        if (pa == pb) return false;

        if (rank[pa] > rank[pb]) {
            par[pb] = pa;
            rank[pa] += rank[pb];
        } else {
            par[pa] = pb;
            rank[pb] += rank[pa];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!Union(edges[i][0], edges[i][1], parent, rank)) {
                result.push_back(edges[i][0]);
                result.push_back(edges[i][1]);
                break;
            }
        }
        return result;
    }
};
