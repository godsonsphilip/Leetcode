#define ll long long
class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 2LL * n * (n - 1);  // ✅ Ensures long long calculation
    }
};
