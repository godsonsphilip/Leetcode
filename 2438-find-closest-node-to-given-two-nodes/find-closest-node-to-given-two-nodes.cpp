class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int V = edges.size();
        vector<int> dist1(V,numeric_limits<int>::max()), dist2(V, numeric_limits<int>::max());
        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        vector<int> temp(V, 0);
        for(int i = 0; i<V; i++){
            temp[i] = max(dist1[i], dist2[i]);
        }

        int result = -1, mini = numeric_limits<int>::max();
        for(int i = 0; i<V; i++){
            if(mini>temp[i]){
                mini = temp[i];
                result = i;
            }
        }
        return result;
    }

    void bfs(vector<int> edges, int src, vector<int>& dist) {
        int n = edges.size() + 1;
        vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        int distance = 0;

        while(!q.empty()){
            int val = q.front();
            q.pop();
            if(vis[val]) continue;
            vis[val] = 1;
            int neighbour = edges[val];
            if(neighbour != -1 and vis[neighbour]==0){
                q.push(neighbour);
                distance++;
                dist[neighbour] = distance;
            }
        }
    }
};