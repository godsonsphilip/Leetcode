class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits(10, -1);
        string a = to_string(num);
        int n = a.size();

        //Discovers the last occurence of each digit:
        for(int i = 0; i<n; i++){
            digits[a[i]-'0'] = i;
        }

        //Try to swap for each digit with the largest digit from right extreme:
        for(int i = 0; i<n; i++){
            for(int j = 9; j>a[i]-'0'; j--){
                if(digits[j] > i){
                    swap(a[i], a[digits[j]]);
                    return stoi(a);
                }
            }
        }
        return num;
    }
};