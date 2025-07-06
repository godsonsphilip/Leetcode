class FindSumPairs {
public:
    vector<int> n1, n2;
    map<int, int> myMap;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int i = 0; i < nums2.size(); i++) {
            myMap[nums2[i]]++;
        }
    }
    void add(int index, int val) {
        myMap[n2[index]]--; // remove old value from map
        n2[index] += val;   // update only that index
        myMap[n2[index]]++; // add new value to map
    }

    int count(int tot) {
        int n = n1.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int val = tot - n1[i];
            auto it = myMap.find(val);
            if (it != myMap.end())
                ans += myMap[val];
            else
                continue;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */