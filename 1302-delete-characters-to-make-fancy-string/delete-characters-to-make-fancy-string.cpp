class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int n = s.size();
        if(n<3) return s;
        result += s[0];
        result += s[1];
        int i = 2;
        while(i<n){
            if(s[i] != s[i-1] or s[i]!=s[i-2]){
                result += s[i];
            }
            i++;
        }
        return result;
    }
};