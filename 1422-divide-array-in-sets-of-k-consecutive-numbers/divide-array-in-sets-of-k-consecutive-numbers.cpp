class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;

        map<int, int> freqMap;
        for (auto& i : nums) {
            freqMap[i]++;
        }

        auto it = freqMap.begin();
        while (it != freqMap.end()) {
            if (it->second == 0) {
                ++it; // Move to next key when current value is 0
            } else {
                int key = it->first;
                for(int i = key; i<key+k; i++){
                    if(freqMap[i]==0) return false;
                    freqMap[i]--;
                }
            }
        }

        return true;
    }
};