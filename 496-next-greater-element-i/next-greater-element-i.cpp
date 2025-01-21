class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int n = nums1.size();
        for(int i = 0; i<n; i++){
            int c = nums1[i];
            auto it = find(nums2.begin(), nums2.end(), c);
            int j = distance(nums2.begin(), it);
            if(j==nums2.size()-1){ result.push_back(-1); continue;}
            j++;
            while(j<nums2.size()){
                
                if(nums2[j]>c){
                    
                    result.push_back(nums2[j]);
                    break;
                }
                j++;
            }
            if(j==nums2.size()) result.push_back(-1);
        }
        return result;
    }
};