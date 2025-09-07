class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        int count = 0;
        bool flag = false;
        if(n&1) {result.push_back(0); count++;}

        int n1 = n;
        while(count<n){
            result.push_back(n1);
            result.push_back(-n1);
            count+=2;
            n1--;
        }
        return result;
    }
};