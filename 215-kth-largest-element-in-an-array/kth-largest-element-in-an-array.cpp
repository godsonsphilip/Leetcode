class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap;

        for(auto& i: nums){
            max_heap.push(i);
        }
        int l = max_heap.size();
        vector<int> n;
        while(k--){
            n.push_back(max_heap.top());
            max_heap.pop();
        }

        return n.back();
    }
};