class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      
         unordered_set<int> temp;
         //Total number of operations are equal to number of distnct elements in nums:
        for(auto& i: nums) {
            if(i<k) return -1;
            else if(i>k)
            temp.insert(i); }
       
        return temp.size();
    }   
};