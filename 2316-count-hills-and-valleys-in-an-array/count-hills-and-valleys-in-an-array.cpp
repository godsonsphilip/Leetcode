class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<int> a;
        for(auto& i: nums){
            if(a.empty() or a.back()!=i){
                a.push_back(i);
            }
        }

        for(int i = 1; i<a.size()-1; i++){
            if(a[i]>a[i-1] and a[i] > a[i+1]) count++;
            else if(a[i]<a[i-1] and a[i]<a[i+1]) count++;
            
        }
        return count;
    }
};