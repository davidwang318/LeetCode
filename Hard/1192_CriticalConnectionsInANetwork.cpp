// Finding bridges
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create adjacency list
        g.resize(n);
        for (const auto& c : connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        
        // Create low-link, Id, visited list
        low.resize(n, 0); 
        ids.resize(n, 0);
        visited.resize(n, false);
        
        // Find Bridges
        vector<vector<int>> res;
        for(int i = 0; i < n; i ++) {
            if (!visited[i])
                dfs(i, -1, res);
        }
        return res;
    }
private:
    void dfs(int cur, int parent, vector<vector<int>>& res) {
        visited[cur] = true;
        id = id + 1;
        low[cur] = ids[cur] = id;
        
        for (const auto& to : g[cur]) {
            // Undirected graph must have backward edge
            if (to == parent) continue;
            if (!visited[to]) {
                dfs(to, cur, res);
                low[cur] = min(low[cur], low[to]);
                if (ids[cur] < low[to])
                    res.push_back({cur, to});
            }
            else
                low[cur] = min(low[cur], ids[to]);
            
        }
        return;        
    }
    int id = 0;
    vector<int> low, ids;
    vector<bool> visited;
    vector<vector<int>> g;
};
