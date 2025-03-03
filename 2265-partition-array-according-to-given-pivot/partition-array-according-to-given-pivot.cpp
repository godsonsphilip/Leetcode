class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        int n = nums.size();
        //Filling the smaller elements into the result vector:
        for(int i = 0; i<n; i++){
            if(nums[i]<pivot){
                result.push_back(nums[i]);
            }
        }
        
        //Pushing the equal elements:
        for(int i = 0; i<n; i++){
            if(nums[i]==pivot){
                result.push_back(nums[i]);
            }
        }

        //PUshing the greater element:
        for(int i = 0; i<n; i++){
            if(nums[i]>pivot){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
