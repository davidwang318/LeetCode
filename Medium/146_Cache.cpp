// Hard! Be ware of list & splice
// Time: 69.95%, Memeory: 62.20%
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto getIt = m.find(key);
        if(getIt == m.end()) return -1;
        l.splice(l.begin(), l, getIt -> second);
        return getIt -> second -> second;
    }
    
    void put(int key, int value) {
        auto putIt = m.find(key);
        if(putIt != m.end()) l.erase(putIt -> second);
        l.push_front({key, value});
        m[key] = l.begin();
        if(l.size() > cap){
            m.erase(l.rbegin()->first);
            l.pop_back();
        }
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    int cap = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Revisit
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()){
            return -1;
        }
        else {
            l.splice(l.begin(), l, it -> second);
            return it -> second -> second;
        }
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it == m.end()) {
            if (l.size() == cap) {
                m.erase(m.find(l.back().first));
                l.pop_back();
            }
            l.push_front({key, value});
            m[key] = l.begin();
        }
        else {
            it -> second -> second = value;
            l.splice(l.begin(), l, it -> second);
        }
        return;
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    int cap = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
