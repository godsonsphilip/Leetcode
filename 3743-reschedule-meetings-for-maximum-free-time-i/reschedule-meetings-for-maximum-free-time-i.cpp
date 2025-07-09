class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
          //Sliding Window with size k+1:
        int n = startTime.size();
        int maxi = 0;
        vector<pair<int, int>> m;
        for(int i = 0; i<n; i++){
            m.emplace_back(startTime[i], endTime[i]);
        }
        sort(m.begin(), m.end());
        vector<int> gaps(n+1,0);
        for(int i = 0; i<n; i++){
            if(i==0){
                gaps[i] = m[i].first;
                continue;
            }
            gaps[i] = m[i].first - m[i-1].second;
            if(i==n-1){
                gaps[i+1] = eventTime - m[i].second;
            }
            
        }

        int left = 0, right = k;
        int sum = accumulate(gaps.begin(), gaps.begin()+k+1, 0);
        maxi = max(sum, maxi);
        while(right<n+1){
            if(left!=0){
                sum += gaps[right];
                maxi = max(maxi, sum);
            }
             sum -= gaps[left];
             left++;
             right++;
        }
        return maxi;
    }
};