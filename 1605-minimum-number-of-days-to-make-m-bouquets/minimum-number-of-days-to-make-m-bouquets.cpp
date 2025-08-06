class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((double)n / k < m)
            return -1;
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int low = mini, high = maxi;
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (number(bloomDay, mid, k) >= m) {
                high = mid - 1;
                ans = mid;
            } else
                low = mid + 1;
        }
        return ans;
    }

    int number(vector<int> bloom, int mid, int k) {
        int n = bloom.size();
        int ans = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (bloom[i] <= mid) {
                count++;
                if (count == k) {
                    ans++;
                    count = 0;
                }
            }

            else {

                count = 0;
            }
        }
        return ans;
    }
};