class Solution {
public:
    int maxFreqSum(string s) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> freq;
        int n = s.size();
        int vmax = 0, cmax = 0;
        for(auto& i: s) freq[i]++;
        for(auto& i: s){
            if(find(vowels.begin(), vowels.end(), i)!=vowels.end()){
                vmax = max(vmax, freq[i]);
            }
            else cmax = max(cmax, freq[i]);
        }
        return vmax + cmax;
    }
};