class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        int sum = 0;
        int bits = 32 - __builtin_clz(k);
        for(int i = 0; i<n; i++){
            char ch = s[n-i-1];
            if(ch=='1'){
                if(i<bits and sum + (1<<i) <=k){
                    sum += 1<<i;
                    count++;
                }
                else continue;
            }
            else count++;
        }
        return count;
    }
};