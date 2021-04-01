// Best solution: cutting an onion
// Time: 71.94%, Space: 26.89%
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<int> res;
        vector<unordered_set<int>> adj(n);
        queue<int> q;
        for (auto edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) q.push(i);
        }
        while (n > 2) {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; ++i) {
                int t = q.front(); q.pop();
                for (auto a : adj[t]) {
                    adj[a].erase(t);
                    if (adj[a].size() == 1) q.push(a);
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};
// Brute force solution: TLE
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // construct adj list
        vector<vector<int>> adjList (n);
        for (const auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        // BFS search
        vector<int> height(n);
        int minHeight = INT_MAX;
        for (int i = 0; i < n; ++i) {
            height[i] = bfs(adjList, i);
            minHeight = min(minHeight, height[i]);
        }
        // Get the result
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (height[i] == minHeight) res.push_back(i);
        }
        return res;
    }
private:
    int bfs(vector<vector<int>>& adjList, int start) {
        queue<int> q {{start}};
        vector<bool> visited (adjList.size(), false);
        int heightCnt = -1;
        while (!q.empty()) {
            int qSize = q.size();
            while(qSize--) {
                int root = q.front(); q.pop();
                visited[root] = true;
                for (const auto child : adjList[root]) {
                    if (visited[child]) continue;
                    q.push(child);
                }
            }
            ++heightCnt;
        }
        return heightCnt;
    }
};