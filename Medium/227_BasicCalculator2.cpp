class Solution {
public:
    int calculate(string s) {
        removeSpace(s);
        stack<int> st;
        char op = '+';
        int num = 0;
        for (int i = 0; i < s.size(); i ++){
            if(s[i] >= '0' && i != s.size()-1){
                num = num*10 + s[i] - '0';
            }
            else{
                if(i == s.size()-1) num = num*10 + (s[i] - '0');
                if(op == '+') st.push(num);
                else if(op == '-') st.push(-num);
                else{
                    int tmp = st.top(); st.pop();
                    tmp = op == '*'? tmp*num : tmp/num;
                    st.push(tmp);
                }
                num = 0;
                op = s[i];
            }
        }
        long res = 0;
        while(!st.empty()){
            res += st.top(); st.pop();
        }
        return res;
    }
private:
    void removeSpace(string& s){
        int cnt = 0;
        for (auto a : s){
            if (a != ' ') s[cnt++] = a;
        }
        s.erase(s.begin()+cnt, s.end());
    }
};
