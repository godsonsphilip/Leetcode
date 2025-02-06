class Solution {
public:
    vector<string> shift(string c, char d) {
        vector<string> ans;
        // Continue shifting the last character until it matches d
        while (c.back() != d) {
            c.back() = (c.back() - 'a' + 1) % 26 + 'a';
            ans.push_back(c); // Collect the current state
        }
        return ans; // Return all intermediate states
    }
    vector<string> stringSequence(string target) {
        string given ;
        vector<string> ans;
        

        for (int i = 0; i < target.size(); i++) {
            given += "a";
            ans.push_back(given);
            if (target[i] != 'a') {
                vector<string> t = shift(given, target[i]);
                ans.insert(ans.end(), t.begin(), t.end());
                if (i == 0) {
                    given = target[i];
                } else {
                    given.back()= target[i];
                }
            }
            
        }
        return ans;
    }
};