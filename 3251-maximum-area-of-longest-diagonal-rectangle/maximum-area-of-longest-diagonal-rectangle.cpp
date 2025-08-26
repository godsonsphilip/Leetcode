class Solution {
public:
    double getDiag(vector<int> rect){
        double result = 0.0;
        result = sqrt(pow(rect[0],2) + pow(rect[1], 2));
        return result;
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxArea = 0, index = -1;double maxDiag = 0; 
        unordered_map<double, vector<int>> diagLengths;
        for(int i = 0; i<n; i++){
            double d = getDiag(dimensions[i]);
            diagLengths[d].push_back(i);
            cout<<diagLengths[d][0]<<endl;
            maxDiag = max(maxDiag, d);
        }


        for(auto& i: diagLengths[maxDiag]){
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            maxArea = max(maxArea, l*b);
        }
        return maxArea;
    }
};