class Solution {
public:
    #define ll long long 
    int reverse(int x) {
        bool neg = x<0;
        string temp = to_string(abs((ll)x));
       std::reverse(temp.begin(), temp.end());
        if(stoll(temp)>numeric_limits<int>::max() or stoll(temp)< numeric_limits<int>::min()) return 0;
        int p = stoi(temp);
        if(neg) p = -p;
        return p;
        
    }
};