class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        if (n % 2 == 1)
            return false;

        stack<int> st1, st2;
        int i = 0;
        while (i < n) {
            if ((s[i] == '(' || s[i] == ')') && locked[i] == '0') 
                st2.push(i);
            else if (s[i] == '(' && locked[i] == '1' )
                st1.push(i);
            else {
                if (i == 0 && s[i] == ')' && locked[i]=='1')
                    return false;
                
                else {
                    if (!st1.empty())
                        st1.pop();
                    else if (!st2.empty())
                        st2.pop();
                    else
                        return false;
                }
            }

            i++;
        }

        while (!st1.empty() && !st2.empty()) {
            if (st2.top() > st1.top()) {
                st1.pop();
                st2.pop();
            } else
                return false;
        }
        if (st1.empty())
            return true;
        return false;
    }
};
