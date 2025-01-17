class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        //Parity of 1's count: O(n) S.C: O(1)
        // int c = count(derived.begin(), derived.end(), 1);
        // return ((c&1) ? false : true);

        //Cummulative XOR: O(n) S.C.: O(1)
        int result = derived[0];
        for(int i = 1; i<derived.size(); i++){
            result^= derived[i];
        }
         return (result==0) ? true : false;
    }
};