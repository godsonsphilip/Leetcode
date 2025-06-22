class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> result;
        int t = n/k;
        for(int i = 0;i<t;i++){
            string temp = "";
            for(int j=k*i; j<k*i+k; j++){
                temp += s[j];
            }
            result.push_back(temp);
        }
        if(n%k!=0){
            string temp1="";

            for(int i = k*t; i<k*t+n%k; i++){
                temp1+= s[i];
            }
            int p = temp1.size();
            int m = k-p;
            while(m){
                temp1 += fill;
                m--;
            }
            result.push_back(temp1);
        }
        return result;
    }
};