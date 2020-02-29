// First Attemp
// Time: 99.56%, Memory: 100.00%
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> res;
        vector<string> tmp;
        for (auto str : strs){
            string strTmp = str;
            sort(strTmp.begin(), strTmp.end());
            if(!m.count(strTmp)){
                int last = res.size();
                m[strTmp] = last;
                res.push_back(tmp);
                res[last].push_back(str);
            }
            else{
                res[m[strTmp]].push_back(str);
            }
        }
        return res;        
    }
};

// Hash the vector!
// Didn't think of it!
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        vector<vector<string>> anagrams;
        string tmp;
        for(auto str : strs){
            tmp = str;
            sort(tmp.begin(), tmp.end());
            table[tmp].push_back(str);
        }
        for(auto anagram : table){
            anagrams.push_back(anagram.second);
        }
        return anagrams;
    }
};
