class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        //Parity of 1's count:
        int c = count(derived.begin(), derived.end(), 1);
        return ((c&1) ? false : true);
    }
};