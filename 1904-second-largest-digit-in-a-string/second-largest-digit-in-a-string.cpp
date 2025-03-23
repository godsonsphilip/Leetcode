class Solution {
public:
    int secondHighest(string s) {
        int n = s.size();
        int m1 = 0, m2 = 0;
        set<int> a;
        for(int i = 0; i<n; i++){
            int d = s[i]-'0';
            if(isdigit(s[i])){
                a.insert(s[i]);
                if(d>m1){
                    m2 = m1; m1 =d;
                }
                else if(d<m1 && d>m2) m2 = d;
            }
        }
        if(a.size()<=1) return -1;
        
        return m2;
    }
};