class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       int maxi = 0;
       unordered_map<char, int> myMap;
       int l = 0, r= 0;
       while(l<=r and r<n){
        if(myMap.find(s[r])!=myMap.end()){
           if(myMap[s[r]]>=l){
            l = myMap[s[r]] + 1;
           }
        }
        myMap[s[r]] = r;

        maxi = max(maxi, r-l+1);
        r++;

       }
        return maxi;
    }
};