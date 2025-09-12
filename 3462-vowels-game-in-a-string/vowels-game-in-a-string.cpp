class Solution {
public:
    bool doesAliceWin(string s) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        for(auto& i: s){
            if(find(vowels.begin(), vowels.end(), i)!=vowels.end()) return true;
        }
        return false;
    }
};