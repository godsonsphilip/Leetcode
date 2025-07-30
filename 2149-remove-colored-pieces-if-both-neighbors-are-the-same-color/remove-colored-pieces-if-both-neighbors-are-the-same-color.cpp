class Solution {
public:
    bool winnerOfGame(string colors) {
        //Ultra-Brute-Force Solution:

        // int n = colors.size();
        // int ca1 = 0, cb1 = 0;
        // for(char i: colors){
        //     if(i=='A') ca1++;
        //     else cb1++;
        // }

        // if(n<=2 )  return false;
        // int count1 = 0, count2 = 0;
        // if(ca1==0) return false;
        // if(cb1==0) return true;
        // for(int i = 0; i<n; i++){
        //     if(i==0 or i==n-1) continue;
        //     if(colors[i]==colors[i+1] and colors[i]==colors[i-1]){
        //         if(colors[i]=='A'){ ca1--; count1++;}
        //         else {cb1--; count2++;}
        //     }
        // }
        // if(count1<=count2){
        //     if(ca1==0) return true;
        //     return false;
        // }
        // else{
        //     if(cb1==0) return false;
        //     return true;
        // }

        //Normal Brute Force Solution:
        int n = colors.size();
        int count3A = 0,count3B = 0;
        for(int i = 1; i<n-1; i++){
            if(colors[i]==colors[i+1] && colors[i]==colors[i-1]){
                if(colors[i]=='A') count3A++;
                else count3B++;
            }
        }
        return count3A>count3B;
    }
};