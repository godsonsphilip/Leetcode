class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        int ans = 0;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i<n; i++){
            pq.push({y[i], x[i]});
        }

        int flag = 0;
        vector<int> a;
        while(!pq.empty() and flag!=3){
            auto [key, val] = pq.top();
            pq.pop();
            if(find(a.begin(), a.end(), val)!=a.end()){
                continue;
            }
            ans += key;
            flag++;
            a.push_back(val);
        }
        if(flag==3) return ans;
        return -1;
        
    }
};