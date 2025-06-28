class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int n1 = 0;
        sort(nums.begin(), nums.end());
        for(auto& i: nums){
            if(i<0) n1++;
        }

        if(n1>=k){
            int t = k;
            for(int i = 0; i<n1 and t>0; i++){
                nums[i] = -nums[i];
                t--;
            }
         sum = accumulate(nums.begin(), nums.end(), 0);
        
        }
       
        else{
            int t = k-n1;
            for(int i = 0; i<n1; i++){
                nums[i] = -nums[i];
            }
            if(t%2==0){
                sum = accumulate(nums.begin(), nums.end(), 0);
            }
            else{
                sum = accumulate(nums.begin(), nums.end(), 0);
                sum -= 2*(*min_element(nums.begin(), nums.end()));
            }
        }


        return sum;
    }
};