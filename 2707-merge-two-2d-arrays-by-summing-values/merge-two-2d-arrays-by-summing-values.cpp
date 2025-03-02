class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        //First comparing with the frist matrix:
        for(int i = 0; i<nums1.size(); i++){
        bool key = false;
            for(int j = 0; j<nums2.size(); j++){
                if(nums1[i][0]==nums2[j][0]){
                    result.push_back({nums1[i][0], (nums1[i][1]+nums2[j][1])});
                    key = true;
                    break;
                }
            }
            if(!key){
                result.push_back({nums1[i][0], nums1[i][1]});
            }
        }

        for(int i = 0; i<nums2.size(); i++){
        bool k = true; 
            for(int j = 0; j<nums1.size(); j++){
                if(nums1[j][0]== nums2[i][0]){
                    k = false;
                    break;
                }
            }
            if(k){
                result.push_back({nums2[i][0], nums2[i][1]});
            }
        }
        
        sort(result.begin(), result.end());
        return result;
        
    }
};