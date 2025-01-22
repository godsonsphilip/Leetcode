class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        // Initial Condition:
        vector<vector<int>> result(m, vector<int>(n,-1));

        queue<pair<int, int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    result[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            int h = result[r][c];
           

            //Defining the neighbours:
            vector<int> dx = {-1,1,0,0};
            vector<int> dy = {0,0,1,-1};

            for(int i = 0; i<4; i++){
               
                  int row = r+dx[i], col = c+dy[i];
                  if(row==m || col ==n || row<0 || col<0 || result[row][col]!=-1) continue;
                  result[row][col] = h+1;
                  q.push(make_pair(row,col));
                
            }
        }
        return result;
    }
};