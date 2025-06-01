class Solution {
public:
#define ll long long

        //Brute-Force Approach:

    // ll count(int n, int r, int limit){
    //     if(n==0) return 1;
    //     if(r==0 or n<0) return 0;
    //     ll ans = 0;
    //     for(int i = 0; i<=limit; i++){
    //         ans += count(n-i, r-1, limit);
    //     }
    //     return ans;
    // }

    long long distributeCandies(int n, int limit) { 
        return cal(n+2) -3*cal(n-(limit+1)+2) + 3*cal(n-2*(limit+1)+2) - cal(n-3*(limit+1)+2);
     }

     long long cal(int n){
        if(n<=1) return 0;
        return (long long)n*(n-1)/2;
     }


    // Principle of INclusion and Exclusion:

};