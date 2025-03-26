class Solution {
public:
    bool check(vector<vector<int>>& m, int k) {
        int r = m.size(), c = m[0].size();
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (i && abs(m[i][j] - m[i - 1][j]) % k !=0)
                    return 0;
                if (j && abs(m[i][j] - m[i][j - 1]) % k!=0)
                    return 0;
            }
        return 1;
    }

    int med(vector<vector<int>>& m) {
        vector<int> v;
        for (auto& r : m)
            v.insert(v.end(), r.begin(), r.end());
        nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
        return v[v.size() / 2];
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        int r = grid.size(), c = grid[0].size();
        if (!check(grid, x))
            return -1;

        //From the pattern we get the idea, that the value must be around the median for all the values to be equal to in ,atrix:
        int m = med(grid);
        int count = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j]!=m){
                    int a = grid[i][j];
                    int diff = abs(a-m);
                    count += diff/x;
                }
            }
        }
        return count;

    }
};