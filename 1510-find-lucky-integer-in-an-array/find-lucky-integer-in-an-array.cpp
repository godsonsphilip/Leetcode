class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
       
        map<int, int> freq;
        for(auto& i: arr) freq[i]++;
        int ans = -1;
        for(auto& [key,val]: freq){
            if(val==key) ans = max(ans, key);
        }
        return ans;
    }
};