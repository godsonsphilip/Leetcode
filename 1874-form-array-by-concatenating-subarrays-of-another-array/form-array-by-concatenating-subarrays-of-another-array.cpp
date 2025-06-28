class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int start = 0;        
        while(j<groups.size() and start<nums.size()){
            if(isMatch(groups[j], nums, start)){
                start += groups[j].size();
                j++;
            }
            else{
                start++;
                continue;
            }
        }
        return j==groups.size();
       
    }

    bool isMatch(vector<int>& g, vector<int>& nums, int start){
        if(start+g.size()>nums.size()) return false;
        for(int i = 0; i<g.size(); i++){
            if(g[i]!=nums[start+i]) return false;
        }
        return true;
    }
};