class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        
        vector<int> temp;
        for (int i = 0; i < n-k+1; i++) {
            int count = 0;
            for(int j = i; j<i+k; j++){
                if(blocks[j]=='W'){
                    count++;
                }
            }
            temp.push_back(count);
        }
        int mini = *min_element(temp.begin(), temp.end());
        return mini;
    }
};