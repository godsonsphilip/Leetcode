class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int mcount = 0, count;
        unordered_set<int> temp;
        for(auto& i: nums) temp.insert(i);
        for(auto i: temp){
            if(temp.count(i-1)){
                continue;
            }
            count = 1;
            while(temp.count(i+1)){
                count++;
                i++;
            }
            mcount = max(mcount, count);
        }
        return mcount;
    }
};