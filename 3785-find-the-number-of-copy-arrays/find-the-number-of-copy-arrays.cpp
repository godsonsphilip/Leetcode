#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int countArrays(vector<int>& o, vector<vector<int>>& b) {
        int n = o.size();
        if (n == 0) return 0;

        vector<int> d(n - 1);
        for (int i = 1; i < n; ++i) {
            d[i - 1] = o[i] - o[i - 1];
        }

        int l = b[0][0];
        int u = b[0][1];

        //Merging all the ranges to find the optimal values that can be taken for the copy array.
        //This is done to ensure how many values that can be taken from the first bounds[0][i], as its clear that once the first value is fixed, all the values are fixed.
        for (int i = 1; i < n; ++i) {
            int nl = l + d[i - 1];
            int nu = u + d[i - 1];

            l = max(nl, b[i][0]);
            u = min(nu, b[i][1]);

            if (l > u) {
                return 0;
            }
        }

        return u - l + 1;
    }
};