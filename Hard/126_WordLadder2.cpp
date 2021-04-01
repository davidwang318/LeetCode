// Slightly modified version. More ituitive to me
/*
The key is level order traversal -> mark visited after that level
*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Preprocess
        unordered_set<string> wordSet {wordList.begin(), wordList.end()};
        if (wordSet.find(endWord) == wordSet.end()) return {};
        
        // Necessary data
        unordered_map<string, vector<string>> parent;
        unordered_map<string, int> visited; // 0 not visited, 1 visiting, 2 visited
        queue<string> q {{beginWord}};
        const int len = beginWord.size();
        
        // Perform BFS
        bool found = false;
        while(!q.empty() && !found) {
            int qSize = q.size();
            vector<string> visitingWord; // container for marking words
            while (qSize-- > 0) {
                const string pWord = q.front(); q.pop();
                string cWord = pWord;                
                for (int i = 0; i < len; ++i) {
                    const char ch = cWord[i];
                    for (int j = 'a'; j <= 'z'; ++j) {
                        if (j == ch) continue;
                        // unique
                        cWord[i] = j;
                        // found
                        if (cWord == endWord) found = true;
                        // not in the list
                        if (wordSet.find(cWord) == wordSet.end()) continue;
                        // in the list
                        if (visited.count(cWord)){
                            if(visited[cWord] == 2) continue; // already visited
                        }
                        else{
                            q.push(cWord); // first visit
                            visited[cWord] = 1;
                            visitingWord.push_back(cWord);
                        }
                        parent[cWord].push_back(pWord); // second visit
                    }
                    cWord[i] = ch;
                }
            }
            for (const auto& word : visitingWord)
                visited[word] = 2;
        }
    
        // DFS backtrack
        vector<vector<string>> res;
        if (found) {
            vector<string> curr {endWord};
            getPaths(endWord, beginWord, parent, curr, res);
        }
        return res;   
    }
private:
    void getPaths(const string& word, 
                  const string& beginWord, 
                  const unordered_map<string, vector<string>>& parents,
                  vector<string>& curr,
                  vector<vector<string>>& ans) {        
        
        if (word == beginWord) {
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }
        
        for (const string& p : parents.at(word)) {
            curr.push_back(p);
            getPaths(p, beginWord, parents, curr, ans);
            curr.pop_back();
        }        
    }
};

// Inspired by HuaHua 
// Time: O(n * 26^len) Space: O(n + kp) k:number of path p: path length

// DFS trial: Time Limit Exceed 
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};
        vector<string> path {beginWord};
        vector<bool> visited (wordList.size(), false);
        vector<vector<string>> res;
        int level = INT_MAX;
        dfs(res, path, visited, wordList, beginWord, endWord, level);
        vector<vector<string>> minRes;
        for (const auto& r : res) if(r.size() == level) minRes.push_back(r);
        return minRes;
    }
private:
    void dfs(vector<vector<string>>& res, vector<string>& path, vector<bool>& visited, 
             vector<string>& wordList, string& curWord, string& endWord, int& level) {
        if (curWord == endWord) {
            if (level > path.size()) level = path.size();
            res.push_back(path);
            return;
        }
        for (int i = 0; i < wordList.size(); ++i) {
            if (visited[i]) continue;
            if (isConnect(wordList[i], curWord)) {
                path.push_back(wordList[i]);
                visited[i] = true;
                dfs(res, path, visited, wordList, wordList[i], endWord, level);
                path.pop_back();
                visited[i] = false;                
            }
        }
        return;
    }
    bool isConnect(string& s1, string& s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) ++cnt;
            if (cnt > 1) return false;
        }
        return true;
    }
};