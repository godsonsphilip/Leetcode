class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result;

        int n = A.size();
        unordered_set<int> a;
        int count = 0;
        for (int i = 0; i < n; i++) {

            if (a.find(A[i]) != a.end()) {
                if (a.find(B[i]) != a.end()) {
                    count++;
                } else
                    a.insert(B[i]);

                count++;
            }

            else if (A[i] == B[i]) {
                count++;
            } else if (a.find(B[i]) != a.end()) {
                if (a.find(A[i]) != a.end()) {
                    count++;
                } else
                    a.insert(A[i]);

                count++;
            } else {
                a.insert(A[i]);
                a.insert(B[i]);
            }

            result.push_back(count);
        }
        return result;
    }
};