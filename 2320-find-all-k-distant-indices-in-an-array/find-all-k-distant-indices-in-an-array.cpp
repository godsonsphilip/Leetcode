class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> result;
        vector<int> vis(n,0);
        vector<int> temp;
        for(int i = 0; i<n; i++){
            if(nums[i]==key){
                for(int j = 0; j<n; j++){
                    if(abs(i-j)<=k and vis[j]==0){
                        result.push_back(j);
                        vis[j] = 1;
                    }
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};