class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        int ans = 0;

        priority_queue<pair<int, int>> myMap;
        for(int i = 0; i<n; i++){
            myMap.push({values[i], labels[i]});
        }

        unordered_map<int, int> freqMap;
        while(!myMap.empty() and numWanted){
            auto [key, val] = myMap.top();
            myMap.pop();
            if(freqMap[val]>=useLimit) continue;
            freqMap[val]++;
            ans += key;
            numWanted--;
        }
        

        return ans;
    }
};