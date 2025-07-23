class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int score = 0;
        if(n==0) return 0;
        string highPriority = (x>y) ? "ab" :  "ba";
        string low = (highPriority=="ab") ? "ba" : "ab";

        //First Pass;
        string result1 = removal(s, highPriority);
        int sum1 = ((n-result1.size())/2);
        int price = (highPriority=="ab") ? x : y;
        score += sum1 * price;

        //Second Pass:
        string result2 = removal(result1, low);
        int sum2 = ((result1.size() - result2.size())/2);
        int p = (low=="ab") ? x : y;
        score += p*sum2;

        return score;
    }


    string removal(string s, string target){
        stack<char> st;
        
       
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i]==target[1] and !st.empty() and st.top()==target[0]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

        string temp = "";
        while(!st.empty()){
            auto i = st.top();
            st.pop();
            temp += i;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};