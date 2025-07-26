class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        // 1. Using set:

        // set<int> r;
        // set<int> c;
        // int n=nums.size();
        // int m=nums[0].size();
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(nums[i][j]==0)
        //         {
        //             r.insert(i);
        //             c.insert(j);
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(r.count(i)>0 || c.count(j)) nums[i][j]=0;
        //     }
        // } 

        //Using row and Column arrays:   S.C. : O(2*n);
        int m = nums.size(), n = nums[0].size();
        // vector<int> rows(m, 0), cols(n, 0);
        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         if(nums[i][j]==0){
        //             rows[i]=1; cols[j]=1;
        //         }
        //     }
        // }

        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         if(rows[i] || cols[j]){
        //             nums[i][j] = 0;
        //         }
        //     }
        // }


        //Optimal Approach: S.C. : O(1);
        int col0 = 1;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(j==0){
                    if(nums[i][j]==0){
                        col0 = 0;
                        continue;
                    }
                }
                if(nums[i][j]==0){
                    nums[0][j]=0;
                    nums[i][0] = 0;
                }
            }
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(!nums[0][j] || !nums[i][0]){
                    nums[i][j] = 0;
                }
            }
        }

        for(int j = 1; j<n; j++){
            if(!nums[0][0]){
                nums[0][j]=0;
            }
        }
       

        for(int i = 0; i<m; i++){
            if(!col0){
                nums[i][0] = 0;
            }
        }

    }
};