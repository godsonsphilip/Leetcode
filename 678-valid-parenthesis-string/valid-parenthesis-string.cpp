class Solution {
public:
    // //Brute Force Approach, Using multiple stacks:
    bool checkValidString(string s) {
        //     int n = s.length();
        //     int oc = count(s.begin(), s.end(), '(');
        //     int cc = count(s.begin(), s.end(), ')');

        //     //Opening braces are greater than closing braces
        //     if(oc>cc){
        //         stack<int> st1, st2;
        //         int i = 0;

        //         //Traversing each element inthe string
        //         while(i<n){
        //             if(s[i]==')'){
        //                 if(!st1.empty()) st1.pop();
        //                 else if(!st2.empty()) st2.pop();
        //                 else return false;
        //             }

        //             if(s[i]=='('){
        //                 st1.push(i);
        //             }
        //             if(s[i]=='*') st2.push(i);
        //             i++;
        //         }

        //         while(!st1.empty() && !st2.empty() && st1.top()<st2.top()){
        //             st1.pop();
        //             st2.pop();
        //         }

        //         if(st1.empty()) return true;
        //         return false;
        //     }

        //     //Closing braces are greater than opening braces
        //     else if(cc>oc){
        //         stack<int> st1, st2, st3;
        //         int i = 0;

        //         //Traversing each element inthe string
        //         while(i<n){
        //             if(s[i]==')'){
        //                 st3.push(i);
        //             }

        //             if(s[i]=='('){
        //                 st1.push(i);
        //             }
        //             if(s[i]=='*') st2.push(i);
        //             i++;
        //         }

        //         while(!st1.empty() ){
        //            if(st3.top()>st1.top()){
        //             st1.pop();
        //             st3.pop();
        //            }
        //         }

        //         while(!st1.empty() && !st2.empty() && st2.top()<st3.top()){
        //             st2.pop();
        //             st3.pop();
        //         }

        //         if(st3.empty()) return true;
        //         return false;
        //     }

        //     else{
        //         stack<int> st1, st2;
        //         int i = 0;
        //         while(i<n){
        //             if(s[i]=='(') st1.push(i);
        //             if(s[i]==')') st2.push(i);
        //             i++;
        //         }

        //         while(st1.top()<st2.top() && !st1.empty() && !st2.empty()){
        //             st1.pop();
        //             st2.pop();
        //         }
        //         if(!st1.empty()) return true;
        //         return false;
        //     }

        // More Optimal Approach: Using Greedy Approach
        int leftMin = 0, leftMax = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                leftMin++;
                leftMax++;
            } else if (s[i] == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }

            if (leftMin < 0)
                leftMin = 0; // Corrected assignment
            if (leftMax < 0)
                return false;
        }

        if (leftMin == 0)
            return true;
        return false;
    }
};