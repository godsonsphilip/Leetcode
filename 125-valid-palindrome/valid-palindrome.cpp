class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while(i<j){
            while(i<j and (!isalpha(s[i]) and !isdigit(s[i]))) i++;
            if(isupper(s[i])) s[i] = tolower(s[i]);
            while(j>i and (!isalpha(s[j]) and !isdigit(s[j]))) j--;
            if(isupper(s[j])) s[j] = tolower(s[j]);
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};