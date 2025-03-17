class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> myMap;
        int n = nums.size();
        for(auto& i: nums){
            myMap[i]++;
        }

        //Checking whether the frequency oc each element is even or odd:
        for(auto& i: myMap){
            if(i.second %2 !=0) return false;
        }
        return true;
    }
};