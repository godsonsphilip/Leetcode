class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int count = 0;
        while(k!=1){
           int t = __lg(k);
            if(k==((long long)1<<t)){
                t--;
            }
            k = k - (((long long)1<<t));
            if(operations[t]) count++;
        }

        return ('a' + (count%26));
    }
};