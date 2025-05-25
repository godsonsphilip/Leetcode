class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int maxLen = 0;
        int flag = 0;

        unordered_map<string, int> myMap;
        for(auto& i: words){
            myMap[i]++;
        }

        for(int i = 0; i<n; i++){
            string t = words[i];
            reverse(t.begin(), t.end());
            if(t==words[i]){
                
                if(myMap[t]==1 && flag==0){
                    flag = 1;
                    maxLen += 2;
                    myMap[t]--;
                }

               else if (myMap[t] >= 2) {
                    maxLen += 4;
                    myMap[t] -= 2;
                }
            }
           else if (myMap[t] > 0 && myMap[words[i]] > 0) {
                maxLen += 4;
                myMap[t]--;
                myMap[words[i]]--;
            }

        }

        return maxLen;
    }
};