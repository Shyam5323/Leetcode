class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        lru.splice(lru.begin(), lru, it->second.second);
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            it->second.first = value;
            lru.splice(lru.begin(), lru, it->second.second);
        } else {
            if (mp.size() == capacity) {
                int lru_key = lru.back();
                lru.pop_back();
                mp.erase(lru_key);
            }
            lru.push_front(key);
            mp[key] = {value, lru.begin()};
        }
    }

private:
    int capacity;
    list<int> lru;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
};
