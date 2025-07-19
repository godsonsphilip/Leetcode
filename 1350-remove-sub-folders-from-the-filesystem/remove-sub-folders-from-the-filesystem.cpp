class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());  //Sorting it in the lexicographical order so that parent directory comes first 
        ans.emplace_back(folder[0]);

        for(int i = 1; i<folder.size(); i++){
            if(folder[i].compare(0, ans.back().length(), ans.back())!=0  ||  folder[i][ans.back().length()]!='/'){ //We are comparing the last element of the ans vector to that of the current element in folder
                ans.push_back(folder[i]); //Pushing only the parent folders
            }
        }
        return ans;
    }
};