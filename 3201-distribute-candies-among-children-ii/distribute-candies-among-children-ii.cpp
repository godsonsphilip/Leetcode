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

    // Principle of INclusion and Exclusion: t.c: O(1);
    // long long distributeCandies(int n, int limit) { 
    //     return cal(n+2) -3*cal(n-(limit+1)+2) + 3*cal(n-2*(limit+1)+2) - cal(n-3*(limit+1)+2);
    //  }

    //  long long cal(int n){
    //     if(n<=1) return 0;
    //     return (long long)n*(n-1)/2;
    //  }

    // T.C = O(n);
    long long distributeCandies(int n, int limit){
        long long ans = 0;
        for(int i  = 0; i<= min(n,limit); i++){
            int s = n-i;
            if(s>2*limit) continue;
            int jmax = min(limit, s);
            int jmin = max(0, s-limit);

            ans += (long long)(jmax-jmin + 1);
        }
        return ans;

    }

};