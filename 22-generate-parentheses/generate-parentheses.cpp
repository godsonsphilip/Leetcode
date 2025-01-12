class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string sample = "";
        backtrack(result, sample, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& sample, int open, int close, int n) {
        // Base Condition:
        if (open == n && close == n) {
            result.push_back(sample);
            return;
        }

        if (open < n) {
            sample += '(';
            backtrack(result, sample, open + 1, close, n);
            sample.pop_back(); // Remove the last character added
        }

        if (close < open) {
            sample += ')';
            backtrack(result, sample, open, close + 1, n);
            sample.pop_back(); // Remove the last character added
        }
    }
};
