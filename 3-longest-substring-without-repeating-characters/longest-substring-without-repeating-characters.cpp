class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, r = 0;
        vector<int> a(256,-1);
        int mlen = 0;
        while(r<n){
            
            if(a[s[r]]>=l){
                l = a[s[r]]+1;
            }
            a[s[r]] = r;
            mlen = max(mlen, r - l +1);
            r++;
        }
        return mlen;
    }
};