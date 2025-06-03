class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n and ratings[i]>ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }

            int bottom = 0;
            while(i<n and ratings[i]<ratings[i-1]){
                bottom++;
                sum += bottom;
                i++;
            }
            bottom++;
            if(bottom>peak) sum += bottom - peak;
        }
        return sum;
    }
};