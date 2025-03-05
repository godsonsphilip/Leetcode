#define ll long long
class Solution {
public:
    long long coloredCells(int n) {
       ll result = 1;
       ll i = 1;
       while(n-1!=0) {
            result += 4LL*i;
            i++;
            n--;
       }
       return result;
    }
};