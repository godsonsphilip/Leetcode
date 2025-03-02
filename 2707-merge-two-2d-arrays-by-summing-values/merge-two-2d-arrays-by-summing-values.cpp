class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> result;
        int l = 0, r = 0;
        while(l<n1 && r<n2){
            if(nums1[l][0]==nums2[r][0]){
                result.push_back({nums1[l][0], nums1[l][1]+nums2[r][1]});
                l++;
                r++;
            }
            else {
                if(nums1[l][0]<nums2[r][0]){
                    result.push_back({nums1[l][0], nums1[l][1]});
                    l++;
                }

                else{
                    result.push_back({nums2[r][0], nums2[r][1]});
                    r++;
                }
            }
        }

        while(l<n1){
           result.push_back(nums1[l]);
            l++;
        }
         while(r<n2){
           result.push_back(nums2[r]);
            r++;
        }
        return result;
    }
};