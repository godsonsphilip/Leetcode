class Solution {
public:
    int find(int a, vector<int>& par) {
        return par[a] == a ? a : (par[a] = find(par[a], par));
    }

    bool Union(int a, int b, vector<int>& par, vector<int>& rank) {
        int pa = find(a, par), pb = find(b, par);
        if (pa == pb) return false;
        
        if (rank[pa] > rank[pb]) par[pb] = pa;
        else if (rank[pa] < rank[pb]) par[pa] = pb;
        else { 
            par[pb] = pa;
            rank[pa]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1), rank(n + 1, 0);
        iota(par.begin(), par.end(), 0);

        for (auto& e : edges) {
            if (!Union(e[0], e[1], par, rank))
                return e;
        }
        return {};
    }
};
