class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string result = s;
        int n = s.size();
        long long sum = accumulate(shifts.begin(), shifts.end(), 0LL);
        for(int i = 0; i<n; i++){
            int a = s[i] - 'a';
             a = (a + sum) % 26;
             result[i] = 'a' + a;
             sum -= shifts[i];
        }
        return result;
    }
};