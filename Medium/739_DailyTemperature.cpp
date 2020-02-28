// First Attemp.
// Need to pay more attension on the edge cases.
// Time: 98.41%, Memory: 100.00%
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size(), tMax = 0;
        vector<int> res(len, 1);
        for(int i = len-1; i >= 0; i --){           
            if(T[i] > tMax){
                tMax = T[i];
                res[i] = 0;
            }
            else{
                while(T[i] >= T[i+res[i]]){
                    if(!res[i+res[i]]){
                        res[i] = 0;
                        break;
                    }
                    res[i]+=res[i+res[i]];
                }
            }
        }
        return res;
    }
};

// Using stack
// Good use!
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        int len = T.size();
        vector<int> res(len, 0);
        for(int i = 0; i < len; i++){
            while(!s.empty() && T[i] > T[s.top()]){
                int idx = s.top(); s.pop();
                res[idx] = i - idx;
            }
            s.push(i);
        }
        return res;
    }
};
