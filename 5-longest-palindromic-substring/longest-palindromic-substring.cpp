class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string result = "";
        int l = 0, r = 0;
        int maxi = -1;
        int start = -1, end = -1;
        for(int i = 0; i<n; i++){
            l = i; r = i;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l>maxi){
                    start = l;
                    end = r;
                     maxi = r -l;
                }
                r++;
                l--;
            }
            l = i; r = i+1;
            while(l>=0 and r<n and s[l]==s[r]){
               if(r-l>maxi){
                    start = l;
                    end = r;
                     maxi = r -l;
                }
                r++;
                l--;
        }
        }

        result = s.substr(start, maxi+1);

        return result;
    }
};