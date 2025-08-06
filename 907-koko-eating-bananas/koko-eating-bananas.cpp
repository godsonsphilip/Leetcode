class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(n==1) return ceil((double)piles[0]/h);
        int m = *max_element(piles.begin(), piles.end());
        long long ans = m;
        int low = 1, high = m;
        while(low<=high){
            long long mid = low +(high-low)/2;
            long long p = time(piles, mid);
           
            if(p<=h){
                ans = min(ans, mid);
               high = mid-1;
                continue;
            }
            low = mid+1;
        }
        return ans;
    }

    long long time(vector<int> p, int k){
        long long total = 0;
        for(auto& i: p){
            total += ceil((double)i/k);
        }
        return total;
    }
};