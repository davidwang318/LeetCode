class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val)) return false;
        m[val] = s.size();
        s.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m.count(val)) return false;
        m[s.back()] = m[val];
        swap(s[m[val]], s.back());
        m.erase(val);
        s.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return s[rand() % s.size()];
    }
    
    unordered_map<int, int> m;
    vector<int> s;
};
