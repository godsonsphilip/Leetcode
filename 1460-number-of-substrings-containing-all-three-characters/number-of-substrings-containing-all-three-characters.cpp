class Solution {
public:
    int numberOfSubstrings(string s) {
        //Sliding Window technique:
       int count = 0;
       int a = 0, b = 0, c = 0;
       int n = s.size();
       int left = 0;
       for(int right = 0; right<n; right++){
        if(s[right]=='a') a++;
        else if(s[right]=='b') b++;
        else if(s[right]=='c') c++;

        while(a>0 && b>0 && c>0){
            count += n-right; //This counts the number of substrings satisfying condition which starts at left and ends at right:

            if(s[left]=='a')   a--;
            else if(s[left]=='b') b--;
            else if(s[left]=='c') c--;
            left++;
        }   
       }
       return count;
    }
};