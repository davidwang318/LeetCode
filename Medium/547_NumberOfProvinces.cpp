class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        // Adjacency list
        vector<vector<int>> adjList(len);
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (i == j) continue;
                if (isConnected[i][j]) adjList[i].push_back(j);
            }
        }
        // DFS
        vector<bool> visited (len, false);
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (visited[i]) continue;
            ++res;
            dfs(adjList, visited, i);
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int cur) {
        if (visited[cur]) return;
        visited[cur] = true;
        for (int i = 0; i < adjList[cur].size(); i++) {
            dfs(adjList, visited, adjList[cur][i]);
        }
        return;
    }
    
};