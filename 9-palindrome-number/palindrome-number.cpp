class Solution {
public:
    bool isPalindrome(int x) {
        string t = to_string((x));
        int n = t.size();
        for(int i = 0; i<(n/2); i++){
            if(t[i]!=t[n-i-1]) return false;
        }
        return true;
    }
};