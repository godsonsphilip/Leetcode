class Solution {
public:

    void backtrack(string digits, string& ds, vector<string>& result, unordered_map<char, string> myMap, int index){
        if(ds.size()==digits.size()){
            result.push_back(ds);
            return;
        }

        for(auto& i: myMap[digits[index]]){
            ds += i;
            backtrack(digits, ds, result, myMap, index+1);
            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()==0) return result;
        string temp;
        unordered_map<char, string> myMap = {
            {'2', "abc"}, {'3', "def"}, {'4',"ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        backtrack(digits,temp, result, myMap, 0);
        return result;
    }
};