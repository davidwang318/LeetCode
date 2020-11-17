class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet{wordList.begin(), wordList.end()};
        if (!wordSet.count(endWord)) return 0;
        queue<string> q {{beginWord}};
        unordered_map<string, int> pathCnt{{{beginWord, 1}}};
        while(!q.empty()){
            string targetWord = q.front(); q.pop();
            for(int i = 0; i < targetWord.size(); i++){
                string newWord = targetWord;
                for(char c = 'a'; c <= 'z'; c++){
                    newWord[i] = c;
                    if(newWord == endWord) return pathCnt[targetWord]+1;
                    if(wordSet.count(newWord) && !pathCnt.count(newWord)){
                        q.push(newWord);
                        pathCnt[newWord] = pathCnt[targetWord]+1;
                    }
                }
            }
        }
        return 0;
    }
};
