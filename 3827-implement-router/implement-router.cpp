class Router {
    int limit;
    deque<vector<int>> packets;
    unordered_set<string> seen;
    unordered_map<int, vector<int>> destMap;

public:
    Router(int memoryLimit) : limit(memoryLimit) {}

    bool addPacket(int src, int dst, int ts) {
        string key = to_string(src) + "#" + to_string(dst) + "#" + to_string(ts);
        if (seen.count(key)) return false;

        if (packets.size() == limit) {
            auto old = packets.front(); packets.pop_front();
            string oldKey = to_string(old[0]) + "#" + to_string(old[1]) + "#" + to_string(old[2]);
            seen.erase(oldKey);
            auto& vec = destMap[old[1]];
            vec.erase(lower_bound(vec.begin(), vec.end(), old[2]));
        }

        packets.push_back({src, dst, ts});
        seen.insert(key);
        destMap[dst].push_back(ts);
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};
        auto pkt = packets.front(); packets.pop_front();
        string key = to_string(pkt[0]) + "#" + to_string(pkt[1]) + "#" + to_string(pkt[2]);
        seen.erase(key);
        auto& vec = destMap[pkt[1]];
        vec.erase(lower_bound(vec.begin(), vec.end(), pkt[2]));
        return pkt;
    }

    int getCount(int dst, int start, int end) {
        auto& vec = destMap[dst];
        return upper_bound(vec.begin(), vec.end(), end) - lower_bound(vec.begin(), vec.end(), start);
    }
};
