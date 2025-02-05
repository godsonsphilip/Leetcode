class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        if(s1.length()!=s2.length()) return false;
        int count = 0;
        int n = s1.length();

        //unorderedmap for checking the letters in both strings:
        vector<int> a(26,0), b(26,0);
        for(int i = 0; i<n; i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }

        if(a!=b) return false;
        for(int i = 0; i<n; i++){
            if(s1[i]!=s2[i]) count++;
        }
        if(count!=2) return false;
        return true;
    }
};