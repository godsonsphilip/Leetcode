class Solution {
public:
    void backtrack(vector<string>& r, int n, int open, int closed, const string& a){
        if(open==closed and closed == n){
            r.push_back(a);
            return;
        }

        if(closed<open){
            backtrack(r, n, open, closed+1, a+')');
        }

        if(open<n)
        backtrack(r, n, open+1, closed, a+'(');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string a = "";
        backtrack(result, n, 0, 0, a);
        return result;
    }
};