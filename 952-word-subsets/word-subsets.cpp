#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<char, int> createMap(const string& word) {
        unordered_map<char, int> m;
        for (const auto& i : word) {
            m[i]++;
        }
        return m;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<unordered_map<char, int>> a;

        for (const auto& i : words1) {
            a.push_back(createMap(i));
        }

        // Creating a hashmap which stores the max frequency for each character
        // in words2
        unordered_map<char, int> t = createMap("");
        for (const auto& i : words2) {
            unordered_map<char, int> ans = createMap(i);
            for (const auto& j : ans) {
                t[j.first] = max(t[j.first], j.second);
            }
        }

        // Comparison of each word1 element to the max frequency map
        for (size_t i = 0; i < words1.size(); i++) {
            bool valid = true;
            for (const auto& p : t) {
                if (a[i][p.first] < p.second) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(words1[i]);
            }
        }

        return result;
    }
};