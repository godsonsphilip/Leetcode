class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        if(is_sorted(arr.begin(), arr.end())) return result;
        vector<int> temp(n,0);
        for(int i = 0; i<n; i++){
            temp[i] = n-i;
        }

        for(int i = 0; i<n; i++){
            int val = temp[i];
            int index = -1;
            for(int j = 0; j<n; j++){
                if(arr[j]==val) {index = j; break;}
            }
            if(index==n-i-1) continue;
            reverse(arr.begin(), arr.begin()+index+1);
            result.push_back(index+1);
            reverse(arr.begin(), arr.begin() + n-i);
            result.push_back(n-i);
        }
        return result;
    }
};