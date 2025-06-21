class Solution {
public:
    int minimumDeletions(string word, int k) {
      int mini = INT_MAX;
      int n = word.length();
      vector<int> freq(26,0);
      for(char i: word){
        freq[i-'a']++;
      }

      for(auto& i: freq)  {
        int base = i;
        int temp = 0;
        for(auto& i: freq){
            if(i<base) temp += i;
            else if(i>=base and i<= base+k) continue;
            else{
                temp += i-base-k;
            }
        }
        mini = min(mini, temp);
      }

      return mini;
    }
};