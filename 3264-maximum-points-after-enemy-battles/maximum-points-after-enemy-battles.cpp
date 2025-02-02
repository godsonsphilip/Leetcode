class Solution {
public:
    long long maximumPoints(vector<int>& arr, int en) {
        int i = 0;
        int j = arr.size()-1;
        long long points = 0;
        long long energy = en;
        sort(arr.begin(),arr.end());
        if(energy < arr[0]) return 0;
        while(i<=j){
            if(energy >= arr[i]){
                points+= energy/arr[i];
                energy = energy % arr[i];
            }else{
                energy+= arr[j];
                j--;
            }
        }
        return points;
    }
};