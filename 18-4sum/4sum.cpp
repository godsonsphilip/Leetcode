class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i<n){
            if(i!=0 and nums[i]==nums[i-1]){
                i++;
                continue;
            }
            //Code Snippet for three sum:
            int j = i+1;
            while(j<n){
                if(j!=i+1 and nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                //Code Snippet for the two Sum:
                int left = j+1, right = n-1, val = nums[j];
                while(left<right){
                    if(left!=j+1 and nums[left]==nums[left-1]){
                        left++;
                        continue;
                    }
                    if(right!=n-1 and nums[right]==nums[right+1]){
                        right--;
                        continue;
                    }
                    if ((ll)nums[left] + nums[right] == (ll)target - val - nums[i])
{
                        result.push_back({nums[i], val, nums[left], nums[right]});
                        left++;
                        continue;
                    }
                   if ((ll)nums[left] + nums[right] > (ll)target - val - nums[i])
{
                        right--;
                        continue;
                    }
                    left++;
                }
                j++;
            }
            i++;
        }
        return result;
    }
};