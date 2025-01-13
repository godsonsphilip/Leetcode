class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> a(26,0);
        for(int i = 0; i<n; i++){
            a[s[i]-'a']++;
        }

        int count = 0;
        for(auto&i : a){
            if(i>2){
                count += (i%2==0) ? 2 : 1;
            }
            else count += i;
        }

        return count;
    }
};