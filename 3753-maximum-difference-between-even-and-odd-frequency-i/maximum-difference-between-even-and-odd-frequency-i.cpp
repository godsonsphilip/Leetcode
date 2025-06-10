class Solution {
public:
    int maxDifference(string s) {
       int ans = 0;
       int n = s.length();
       unordered_map<char, int> myMap;
       for(auto& i: s){
            myMap[i]++;
       }

        vector<int> odd, even;
       for(auto& i: myMap){
         int val = i.second;
         if(val%2) odd.push_back(val);
         else even.push_back(val);
       }

       sort(odd.rbegin(), odd.rend());
       sort(even.rbegin(), even.rend());

       int max1 = odd[0]-even[even.size()-1];
       ans = max1;
       return ans;
    }
};
