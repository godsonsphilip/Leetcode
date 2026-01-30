class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> result, temp;
        
        for(auto& i: nums) {
            if(i>=0) temp.push_back(i);
        }
        int n = temp.size();
        if(n==0 or k==0) return nums;
        int rot = k%n;
        
        //Left-Shifting the temp array by rot times
        reverse(temp.begin(), temp.begin()+rot);
        reverse(temp.begin()+rot, temp.end());
        reverse(temp.begin(), temp.end());

        int j = 0;
        for(int& i: nums){
            if(i>=0) {result.push_back(temp[j]); j++;}
            else result.push_back(i);
        }

        return result;
    }
};