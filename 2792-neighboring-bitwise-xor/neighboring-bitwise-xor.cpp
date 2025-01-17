class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // Brute Force Approach:
        int n = derived.size();
        vector<int> a1;
        // case-1: a1 starts with 1
        a1 = {1};
        for (int i = 1; i < n; i++) {
            a1.push_back(derived[i - 1] ^ a1[i - 1]);
        }
        int k = 0;
        if (derived[n - 1] == a1.back()^a1.front()) {
           
                k = 1;
        } 
        if(k) return true;

        
        a1 = {0};

        
        for (int i = 1; i < n; i++) {
            a1.push_back(derived[i - 1] ^ a1[i - 1]);
        }
         k = 0;
        if (derived[n - 1] == a1.front()^a1.back()) {
            k=1;
        }
        
            
        if(k) return true;
        return false;
        // Parity of 1's count: O(n) S.C: O(1)
        //  int c = count(derived.begin(), derived.end(), 1);
        //  return ((c&1) ? false : true);

        // Cummulative XOR: O(n) S.C.: O(1)
        //  int result = derived[0];
        //  for(int i = 1; i<derived.size(); i++){
        //      result^= derived[i];
        //  }
        //   return (result==0) ? true : false;
    }
};