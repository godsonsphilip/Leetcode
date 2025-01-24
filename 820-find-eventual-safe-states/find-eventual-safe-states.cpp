class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph,
             unordered_map<int, bool>& myMap) {
        if (myMap.find(i) != myMap.end()) {
            return myMap[i];
        }
        myMap[i] = false;
        for (int j = 0; j < graph[i].size(); j++) {
            if (!dfs(graph[i][j], graph, myMap)){
                    return myMap[i];
        }
    }
    myMap[i] = true;
    return myMap[i];
}


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> result;
    unordered_map<int, bool> myMap;

    for (int i = 0; i < n; i++) {
        if (dfs(i, graph, myMap)) {
            result.push_back(i);
        }
    }
    return result;
}
}
;