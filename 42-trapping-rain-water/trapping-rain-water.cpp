class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        //Prefix Max:
        vector<int> p(n,0), s(n,0);
        int m = 0, m1 = 0;
        for(int i = 0; i<n; i++){
            m = max(m, height[i]);
            m1 = max(m1, height[n-i-1]);  //For Suffix Max;
            p[i] = m; s[n-i-1] = m1;
        }
        
        int result = 0;
        for(int i = 0; i<n; i++){
            int o = min(p[i], s[i]);
            if(height[i]<o){
                result += o - height[i];
            }
        }
        return result;
    }
};