class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==INT_MIN) return false;
        if(__builtin_popcount(n)==1) return true;
        return false;

    }
};