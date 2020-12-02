class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // unknown: 0, visiting: 1, visited: 2
        visited.resize(numCourses, 0);
        // Construct adjacency list
        vector<vector<int>> graph(numCourses);
        for (const auto & v : prerequisites){
            graph[v[1]].push_back(v[0]);
        }
        // TopSort
        vector<int> topSort(numCourses, -1);
        int topIdx = numCourses - 1;
        for (int i = 0; i < numCourses; i++){
            if(!dfs(topSort, graph, i, topIdx)) return {};
        }
        return topSort;
        
    }
private:
    bool dfs(vector<int>& topOrder, vector<vector<int>>& graph, int node, int& topIdx){
        if (visited[node] == 1) return false;
        if (visited[node] == 2) return true;
        // mark current node as visiting
        visited[node] = 1;
        // dfs
        for(const auto n : graph[node]){
            if(!dfs(topOrder, graph, n, topIdx)) return false;
        }
        // Add to the order
        topOrder[topIdx--] = node;
        visited[node] = 2;
        return true;
    }
    vector<int> visited;
};
