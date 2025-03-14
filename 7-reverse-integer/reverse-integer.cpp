class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x!=0){
            int i = x%10;
            result = result*10 + i;
            x /= 10;
            if(result>=INT_MAX) return 0;
            if(result<=INT_MIN) return 0;
        }
        return result;
    }
};