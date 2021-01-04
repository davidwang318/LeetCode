class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root_(new TrieNode()) {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        shared_ptr<TrieNode> cur = root_;
        for (auto& c : word) {
            if (! cur -> children[c - 'a'])
                cur -> children[c - 'a'] = shared_ptr<TrieNode> (new TrieNode());
            cur = cur -> children[c - 'a'];
        }
        cur -> isWord_ = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        shared_ptr<TrieNode> cur = root_;
        for (auto& c : word) {
            if (! cur -> children[c - 'a'])
                return false;
            cur = cur -> children[c - 'a'];
        }
        return cur -> isWord_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        shared_ptr<TrieNode> cur = root_;
        for (auto& c : prefix) {
            if (! cur -> children[c - 'a'])
                return false;
            cur = cur -> children[c - 'a'];
        }
        return true;
    }
private:
    struct TrieNode {
        bool isWord_;
        vector<shared_ptr<TrieNode>> children;
        TrieNode() :isWord_(false), children(26) {}
    };
    shared_ptr<TrieNode> root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
