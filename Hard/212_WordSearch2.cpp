// My solution
struct TrieNode {
        bool is_word;
        vector<unique_ptr<TrieNode>> children;
        TrieNode():is_word(false), children(26){}
    };

class Trie{
public:
    Trie():root_(new TrieNode()){}
    void insert(const string& s){
        TrieNode* rootPtr = root_.get();
        for (const auto c : s){
            if (!rootPtr -> children[c - 'a'])
                rootPtr -> children[c - 'a'] = std::make_unique<TrieNode> ();
            rootPtr = (rootPtr -> children[c - 'a']).get();
        }
        rootPtr -> is_word = true;
    }
    int search(const string& s) const {
        // 0: no word, 1: possible, 2: yes
        TrieNode* rootPtr = root_.get();
        for (const auto c : s){
            if (rootPtr -> children[c - 'a'])
                rootPtr = (rootPtr -> children[c - 'a']).get();
            else
                return 0;
        }
        return rootPtr -> is_word? 2 : 1;
    }
    
    std::unique_ptr<TrieNode> root_;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty()) return {};
        rLen = board.size();
        cLen = board[0].size();
        // Insert the words
        trie = new Trie();
        for (const auto& s : words)
            trie -> insert(s);
        auto tPtr = trie -> root_.get();
        // Find the words using dfs;
        string s = "";
        vector<vector<bool>> visited (rLen, vector<bool> (cLen, false));
        for (int i = 0; i < rLen; i++){
            for (int j = 0; j < cLen; j++){
                dfs(board, tPtr, i, j, s, visited);
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& board, TrieNode* t, int rIdx, int cIdx, string& s,vector<vector<bool>>& visited){
        if (rIdx < 0 || cIdx < 0 || rIdx >= rLen || cIdx >= cLen ||!t -> children[board[rIdx][cIdx] - 'a'] || visited[rIdx][cIdx]) return;
        s += board[rIdx][cIdx];
        visited[rIdx][cIdx] = true;
        auto tChild = t -> children[board[rIdx][cIdx] - 'a'].get();
        if (tChild -> is_word) {
            res.push_back(s);
            tChild -> is_word = false;
        }
        for (int i = 0; i < 4; i++){
            dfs(board, tChild, rIdx+dirs[i], cIdx+dirs[i+1], s, visited);
        }
        visited[rIdx][cIdx] = false;
        s.pop_back();
        return;
    }
    vector<string> res;
    int rLen, cLen;
    Trie* trie;
    vector<int> dirs {0, 1, 0, -1, 0};
};
