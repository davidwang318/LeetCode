// Space: O(1)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        len = M.size();
        if (len < 2) return len;
        int res = 0;
        for (int i = 0; i < len; i++){
            if(M[i][i]){
                res++;
                dfs(M, i);
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& graph, int fIdx){
        if(!graph[fIdx][fIdx]) return;
        graph[fIdx][fIdx] = 0;
        for(int i = 0; i < len; i++){
            if(graph[fIdx][i]) dfs(graph, i);
        }
        return;
    }
    int len = 0;
};
