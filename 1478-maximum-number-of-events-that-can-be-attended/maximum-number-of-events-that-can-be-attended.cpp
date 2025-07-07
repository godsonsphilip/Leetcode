class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        int start = events[0][0], end = 0;
        for(auto& i: events){
            end = max(end, i[1]);
        }
        priority_queue<int, vector<int>, greater<>>
            pq;
        int i = start, ans = 0;
        int j = 0;
        while (i <= end) {
            // Checking the start date of events:
            while (j < n and events[j][0] <= i) {
                pq.push(events[j][1]);
                j++;
            }

            // Checking the expired ones:
            while (!pq.empty() and pq.top()<i) {
                pq.pop();
            }

            if (!pq.empty()) {
                ans++;
                pq.pop();
            }
            i++;
        }
        return ans;
    }
};