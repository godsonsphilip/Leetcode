class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> result(2, -1);
        vector<int> temp;
        for(int i = left; i<=right; i++){
            if(isPrime(i)){
                temp.push_back(i);
            }
        }
        if(temp.empty()||temp.size()==1) return result;
        //Here num1 and num2 has to be different:
        int l = -1;
        int mini = INT_MAX;
        for(int i = 1; i<temp.size(); i++){
            int diff = temp[i] - temp[i-1];
            
            if(diff<mini){
                mini = diff;
                l = i-1;  // Store the first index of the closest pair:
            }
        }

        result.front() = temp[l];
        result.back() = temp[l+1];
        return result;
    }
};