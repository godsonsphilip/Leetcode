class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        vector<char> present;
        string temp = s;
        for(auto& i: s){
            if(find(vowels.begin(), vowels.end(), i)!=vowels.end()){
                present.push_back(i);
            }
        }
        sort(present.begin(), present.end());
        int l = 0;
        for(int i = 0; i<n; i++){
            if(find(vowels.begin(), vowels.end(), s[i])!=vowels.end()){
                temp[i] = present[l];
                l++;
                continue;
            }
        }
        return temp;
    }
};