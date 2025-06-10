class Solution {
public:
    int maxDifference(string s) {
      int ans = 0;
      vector<int> freq(26,0);
      int odd = 1;
      int even = numeric_limits<int>::max();
      for(auto& i: s) freq[i-'a']++;
      for(int i = 0; i<26; i++){
        if(freq[i]%2) odd = max(odd, freq[i]);
        else if(freq[i]) even = min(even, freq[i]);
      }
      ans = odd -even;

      return ans;
    }
};
