class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ans;
        for(int i = 1; i<=n; i++){
            string a = to_string(i);
            ans.push_back(a);
        }
        sort(ans.begin(), ans.end());
        vector<int> result;
        for(auto& i: ans){
            
            result.push_back(stoi(i));
        }
        return result;
    }
};