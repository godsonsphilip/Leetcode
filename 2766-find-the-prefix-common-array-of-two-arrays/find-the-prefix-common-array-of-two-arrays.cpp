class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result;

        int n = A.size();
        vector<int> s(n + 1, 0);
        unordered_set<int> a, b;
        int count = 0;
        for (int i = 0; i < n; i++) {

            //     //Two set Approach:
            //     a.insert(A[i]); b.insert(B[i]);
            //    for(auto&i: a){
            //         if(b.count(i)) count++;
            //    }

            // Using frequency array approach:
            s[A[i]]++; s[B[i]]++;
            if(A[i]!=B[i])
            {if(s[A[i]]==2) count++;
            if(s[B[i]]==2) count++;}
            else {
                if(s[A[i]]==2) count++;
            }

            result.push_back(count);
        }
        return result;
    }
};