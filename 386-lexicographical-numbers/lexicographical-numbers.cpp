class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int a = 1;
        for(int i = 0; i<n; i++){
            ans.push_back(a);
            if(a*10<=n){
                a *= 10;
                continue;
            }
            if(a+1 > n){
                a /= 10;
               
                
            }
            a++;
            while(a%10 == 0){
                a /= 10;
            }

        }
        return ans;
    }
};