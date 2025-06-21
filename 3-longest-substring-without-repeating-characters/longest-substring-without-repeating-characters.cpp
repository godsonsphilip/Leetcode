class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, maxi = 0;
        unordered_set<int> mySet;
        while(l<=r and r<n){
            if(mySet.find(s[r])!=mySet.end()){
                mySet.erase(s[l]);
                l++;
                continue;
            }
            mySet.insert(s[r]);
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};