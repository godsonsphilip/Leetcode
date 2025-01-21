class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // Optimised Approach: O(n+m);
        int n = nums2.size(), m = nums1.size();
        stack<int> st;
        unordered_map<int, int> myMap;
        for (int i = 0; i < m; i++) { // Hash Map to store the indices as values
                                      // for unique values of array1:
            myMap[nums1[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int curr = nums2[i];
            while (!st.empty() && curr > st.top()) {
                int p = st.top();
                st.pop();
                int index = myMap[p];
                nums1[index] = curr;
            }
            if (myMap.find(curr) != myMap.end()) {
                st.push(curr);
            }

            // If there is no greater element
            if (i == n - 1) {
                while (!st.empty()) {
                    int p = st.top();
                    st.pop();
                    int index = myMap[p];
                    nums1[index] = -1;
                }
            }
        }
        return nums1;

        // O(n*m) Approach:
        //  vector<int> result;
        //  int n = nums1.size();
        //  for(int i = 0; i<n; i++){
        //      int c = nums1[i];
        //      auto it = find(nums2.begin(), nums2.end(), c);
        //      int j = distance(nums2.begin(), it);
        //      if(j==nums2.size()-1){ result.push_back(-1); continue;}
        //      j++;
        //      while(j<nums2.size()){

        //         if(nums2[j]>c){

        //             result.push_back(nums2[j]);
        //             break;
        //         }
        //         j++;
        //     }
        //     if(j==nums2.size()) result.push_back(-1);
        // }
        // return result;
    }
};