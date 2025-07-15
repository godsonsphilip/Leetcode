class Solution {
public:
    bool isValid(string word) {
        int count = 0, cnum = 0;
        if(word.size()<3) return false;
        for(auto& i: word) if(!isalnum(i)) return false;
        vector<char> vowel = {'a','e','i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(auto& i: word){
            if(find(vowel.begin(), vowel.end(), i) != vowel.end()){ count++;}
            if(isdigit(i)) cnum++;
        }
        if(count<1) return false;
        if(word.size()-count-cnum <1) return false;
        return true;
    }
};