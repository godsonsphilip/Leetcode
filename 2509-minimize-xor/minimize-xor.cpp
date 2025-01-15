class Solution {
public:
    bool isSet(int n, int a) { return (n & (1 << a) ? true : false); }

    void set(int& a, int i) { a = a | (1 << i); }

    void unset(int& a, int t) { a = a & ~(1 << t); }

    int minimizeXor(int num1, int num2) {
        // int r = num1;
        // int curr = 0;
        // int targetbit = __builtin_popcount(num2);
        // int result = __builtin_popcount(num1);
        // while(result<targetbit){
        //     if(!isSet(r,curr)){
        //         set(r,curr);
        //         result++;
        //     }
        //     curr++;
        // }

        // curr = 0;
        // while(result>targetbit){
        //     if(isSet(r,curr)){
        //         unset(r,curr);
        //         result--;
        //     }
        //     curr++;
        // }

        int p = __builtin_popcount(num2);
        int t = num1;
        while (true) {
            if (__builtin_popcount(t) == p) {
                return t;
            }
            else if(__builtin_popcount(t) > p){
                t--;
            }
           else t++;
        }

        return t;
    }
};