#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll n = nums.size();
        unordered_map<ll, ll> myMap;
        long long result = 0;
        ll gp=0;


        
        for(ll i = 0; i<n; i++){
            ll diff = nums[i] - i;
            gp+=myMap[diff];

            myMap[diff]++;

        }

        result = n*(n-1)/2 -gp; 
        return result;
    }
};