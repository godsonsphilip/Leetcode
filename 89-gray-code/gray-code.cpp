class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);

        if(n==0) return result;
        int i = 1;

        while(i<pow(2,n)){
            for(int j = result.size()-1; j>=0; j--){
                int p = result[j]+i;
                result.push_back(p);
            }
            i *= 2;
        }
        return result;
    }
};