class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int ans = 0;
        unordered_map<char, int> myMap;
        for(int i = 0; i<n; i++){
            myMap[s[i]]++;
            ans = max(ans, min(abs(myMap['S']-myMap['N']) + abs(myMap['E']-myMap['W']) + 2*k, i+1));
        }

        return ans;
    }
};