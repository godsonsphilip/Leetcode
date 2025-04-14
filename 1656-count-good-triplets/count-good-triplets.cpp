class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1;j<n; j++){
                for(int k = j+1; k<n; k++){
                    int p = abs(arr[i]-arr[j]);
                    int q = abs(arr[j]-arr[k]);
                    int r = abs(arr[i]-arr[k]);
                    if(p<=a and q<=b and r<=c) count++;
                }
            }
        }
        return count;
    }
};