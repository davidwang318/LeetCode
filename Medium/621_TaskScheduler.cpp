// Very hard for me. Need review.
// Time: 29.53%, Memory: 29.79%
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for (auto task : tasks) m[task]++;
        priority_queue<int> q;
        for (auto i : m) q.push(i.second);
        int res = 0;
        while(!q.empty()){
            vector<int> tmp;
            int blockSize = n+1;
            while(!q.empty() && blockSize--){
                tmp.push_back(q.top()-1); q.pop();
            }
            for(auto j : tmp){
                if(j) q.push(j);
            }
            res += q.empty() ? (n+1 - blockSize) : n+1;
        }
        return res;
    }
};
