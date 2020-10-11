class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        generateParenthesis(n, 0, 0, res, str);
        return res;
    }
    void generateParenthesis(int n, int leftCnt, int rightCnt, vector<string>& res, string& str){
        if(str.size() == n*2){
            res.push_back(str);
            return;
        }
        if(leftCnt < n){
            str.push_back('(');
            generateParenthesis(n, leftCnt+1, rightCnt, res, str);
            str.pop_back();
        }
        if(rightCnt < leftCnt){
            str.push_back(')');
            generateParenthesis(n, leftCnt, rightCnt+1, res, str);
            str.pop_back();
        }
        return;
    }
};
