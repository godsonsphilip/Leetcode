class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> myMap;
        for(auto& i: answers){
            myMap[i]++;
        }

        int count = 0;
        for(auto& i: myMap){
            int a = i.first;
            a++;
            count += ceil((double)i.second/a)*a;
        }
        return count;
    }
};