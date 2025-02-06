class Solution {
public:
    string getSmallestString(string s) {
        int u = s.size();
         for (int i = 0; i < (u - 1); i++) {
            
            if (s[i] % 2 == 0 && s[i + 1]%2 == 0 && s[i]>s[i+1])  {
                // int t = s[i];
                // s[i] = s[i + 1];
                // s[i + 1] = t;
                swap(s[i],s[i+1]);
                break;
            }

            else if (s[i] % 2 != 0 && s[i + 1] % 2 != 0 && s[i]>s[i+1]) {
                // int q = s[i];
                // s[i] = s[i + 1];
                // s[i + 1] = q;
                swap(s[i],s[i+1]);

                break;
            }
        
        }
        return s;
    }
};