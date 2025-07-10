class Solution {
public:

    vector<pair<int, int>> top3(vector<int> gaps){
        vector<pair<int, int>> result(3,{-1,-1});
        int n = gaps.size();
        for(int i = 0; i<n; i++){
            int val = gaps[i];
            int j = 1;
            if(result[0].first >gaps[i]) continue;
            result[0].first = gaps[i];
            result[0].second = i;
            while(j<3 and result[j].first < result[j-1].first){
               swap(result[j], result[j-1]);
               j++;
            }
        }
        return result;
    }

    bool exists(vector<pair<int, int>> t, int dur, int ind){

        for(int i = 2; i>=0; i--){
            if((t[i].first >= dur) and (t[i].second != ind and t[i].second != ind+1) ) return true;
            continue;
        }
        return false;
    }
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
       int n = startTime.size() ;
       int maxi = 0;
       vector<int> gaps(n+1, 0);
       gaps[0]  = startTime[0];
       for(int i=0; i<n-1; i++){
        gaps[i+1] = startTime[i+1] - endTime[i];
       }
       gaps[n] = eventTime - endTime[n-1];
       auto t = top3(gaps);
       for(int i = 0; i<n; i++){
        int dur = endTime[i] - startTime[i];
        if(exists(t, dur, i)){
            maxi = max(maxi, gaps[i] + gaps[i+1] + dur);
            continue;
        }
        maxi = max(maxi, gaps[i] + gaps[i+1]);
       }
       return maxi;
    }
};