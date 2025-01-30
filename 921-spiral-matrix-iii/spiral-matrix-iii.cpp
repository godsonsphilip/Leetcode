class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        int r = rStart, c = cStart;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0;
        int steps = 1;
        vector<vector<int>> result;
        while (result.size() < rows * cols) {
            for (int j = 0; j < 2;
                 j++) { // This ensures that the steps are repeated only twice
                        // to maintain a spiral structure
                auto [dr, dc] =
                    dir[i]; // Decides the direction for each loop for step;
                for (int k = 0; k < steps; k++) {
                    if (r < rows && r >= 0 && c >= 0 &&
                        c < cols) { // Checks the validty of the cell
                        result.push_back({r, c});
                    }
                    r = r + dr;
                    c += dc;
                }
                i = (i + 1) % 4; // This ensures, i doesnt gets out of bound
            }
            steps++;
        }
        return result;
    }
};