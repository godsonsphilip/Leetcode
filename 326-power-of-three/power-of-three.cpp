class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        while(n!=1){
            int rem = n%3;
            if(rem){
                return false;
            }
            n /= 3;
        }
        return true;
    }
};