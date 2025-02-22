#define ll long long
class Solution {
    public:
    int minOperations(vector<int>& nums, int k) {
        ll count = 0;
        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        for(auto& i : nums){
            minHeap.push(i);
        }

        if(minHeap.top()>=k) return count;
        while(minHeap.size()>=2){
            if(minHeap.top()>=k) return count;
            count++;

            ll x = minHeap.top();
            minHeap.pop();
            ll y = minHeap.top();
            minHeap.pop();

            minHeap.push(2*x + y);

        }
        return count;
    }
};