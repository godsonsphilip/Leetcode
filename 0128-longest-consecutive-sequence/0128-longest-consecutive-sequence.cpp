class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int maxi = 0;

        for(auto &i : st){

            if(st.count(i - 1))
                continue;

            int cnt = 1;
            int num = i;

            while(st.count(num + 1)){
                cnt++;
                num++;
            }

            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};