class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        vector<int> t1, t2;  //positive, negative

        //Given the fact, that neither of the two arrays, i.e., t1 and t2 are going tobe empty.
        //First fill in the positive number then the negative number and so on.....
        for(auto& i: nums){
            if(i>0){
                t1.push_back(i);
            }
            else{
                t2.push_back(i);
            }
        }

        for(int i = 0; i<(n/2); i++){
            result.push_back(t1[i]);
            result.push_back(t2[i]);
        }
        return result;
    }
};