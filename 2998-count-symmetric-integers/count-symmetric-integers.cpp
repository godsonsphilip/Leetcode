class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i<=high; i++){
            string a = to_string(i);
            int n = a.size(); //Calculates the count of digits in number 'i';
            if(n & 1) continue; //Checks whether the given number has odd number of digits;

            //We will manually check for each number, specifically their sum of both prefix and suffix
            //a.k.a. Brute Force Approach:
            

            //Checking the sum of prefix or first n digits:
            int psum = 0, ssum = 0;
            for(int i = 0; i<(n/2); i++){
                psum += a[i];
            }    
            for(int i = n/2; i<n; i++){
                ssum += a[i];
            }
            if(ssum == psum ) count++;
        }

        return count;
    }
};