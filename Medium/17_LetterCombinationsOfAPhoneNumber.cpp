class Solution {
public:
    Solution(){
        digitMap[0] = {'a', 'b', 'c'};
        digitMap[1] = {'d', 'e', 'f'};
        digitMap[2] = {'g', 'h', 'i'};
        digitMap[3] = {'j', 'k', 'l'};
        digitMap[4] = {'m', 'n', 'o'};
        digitMap[5] = {'p', 'q', 'r', 's'};
        digitMap[6] = {'t', 'u', 'v'};
        digitMap[7] = {'w', 'x', 'y', 'z'};
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        string s;
        // dfsPhoneNumber(res, s, 0, digits);
        bfsPhoneNumber(res, 0, digits);
        return res;
    }
private:
    vector<vector<char>> digitMap = vector<vector<char>> (8, vector<char>());    
    void dfsPhoneNumber(vector<string>& res, string& str, int idx, string& digits){
        if (str.size() == digits.size()){
            res.push_back(str);
            return;
        }
        for (const auto i : digitMap[digits[idx] - '2']){
            str.push_back(i);
            dfsPhoneNumber(res, str, idx+1, digits);
            str.pop_back();
        }
        return;        
    }
    void bfsPhoneNumber(vector<string>& res, int idx, string&digits){
        if(idx == digits.size()) return;
        vector<string> resUpdate;
        for (const auto i : digitMap[digits[idx] - '2']){
            if(idx == 0) resUpdate.push_back({i});
            else{
                for (auto j: res) {
                    j.push_back(i);
                    resUpdate.push_back(j);
                }
            }
        }
        res = resUpdate;
        bfsPhoneNumber(res, idx+1, digits);        
    }
};
