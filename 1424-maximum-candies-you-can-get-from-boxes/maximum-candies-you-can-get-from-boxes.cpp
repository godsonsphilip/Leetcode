class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        if(initialBoxes.size()==0) return 0;
        int n = status.size();
        int ans = 0;
        queue<int> q;
        vector<int> open(n, 0);
        for(auto& i: initialBoxes) q.push(i);
        for(int i = 0; i<n; i++){
            open[i] = status[i];
        }
        int timer = 0;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            if(!open[val]){
                q.push(val);
                timer++;

                if(timer>q.size()) break;
                continue;
            }
            ans += candies[val];
            for(auto& i: keys[val]) open[i] = 1;

            for(auto& i: containedBoxes[val]){
                q.push(i);
            }
            timer = 0;
        }

        return ans;
    }
};