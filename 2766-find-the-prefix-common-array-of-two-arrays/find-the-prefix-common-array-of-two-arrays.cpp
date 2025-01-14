class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result;

        int n = A.size();
        set<int> a,b;
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            //Two set Approach:
            a.insert(A[i]); b.insert(B[i]);
           for(auto&i: a){
                if(b.count(i)) count++;
           }

            result.push_back(count);
        }
        return result;
    }
};