class Solution {
public:
    void backtrack(vector<string>& path, vector<vector<string>>& result,
                   string s, int index) {
        int n = s.size();
        if (index == n) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < n; i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                backtrack(path, result, s, i + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start; i < start + (end - start + 1) / 2; ++i) {
            if (s[i] != s[end - (i - start)])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(path, result, s, 0);
        return result;
    }
};