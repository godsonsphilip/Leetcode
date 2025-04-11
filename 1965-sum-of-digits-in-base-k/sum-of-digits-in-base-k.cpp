class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        while(n>=k){
            int rem = n%k;
            n /= k;
            sum += rem;
        }
        if(n!=0) sum += n;
        return sum;
    }
};