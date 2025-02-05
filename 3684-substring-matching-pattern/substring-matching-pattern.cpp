class Solution {
public:
    bool hasMatch(string s, string p) {
        int index = p.find("*");
        if (index == -1) return s == p; // No wildcard case
        
        string prefix = p.substr(0, index);
        string suffix = p.substr(index + 1);

        int i = s.find(prefix);
        int j = s.rfind(suffix);

        return i != -1 && j != -1 && i + prefix.size() <= j;
    }
};
