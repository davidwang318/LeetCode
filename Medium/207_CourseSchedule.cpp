// DFS finding cycle
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> nodeVisited (numCourses, false), dfsVisited (numCourses, false);
        for(int i = 0; i < prerequisites.size(); i++){
            if(dfs(prerequisites, nodeVisited, dfsVisited, prerequisites[i][0])) return false;
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& prerequisites, vector<bool>& nodeVisited, vector<bool>& dfsVisited,int target){
        if(nodeVisited[target] && !dfsVisited[target]) return false;
        if(dfsVisited[target]) return true;
        nodeVisited[target] = dfsVisited[target] = true;
        for(int i = 0; i < prerequisites.size(); i++){
            if(prerequisites[i][0] == target){
                if(dfs(prerequisites, nodeVisited, dfsVisited, prerequisites[i][1])) return true;
            }
        }
        dfsVisited[target] = false;
        return false;
    }
};

// DFS Topological sort
// The key is to start from the node
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList (numCourses);
        for(const auto & req : prerequisites){
            adjList[req[0]].push_back(req[1]);
        }
        vector<bool> nodeVisited (numCourses, false), dfsVisited (numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(adjList[i].empty()) continue;
            if(dfs(adjList, nodeVisited, dfsVisited, i)) return false;
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& adjList, vector<bool>& nodeVisited, vector<bool>& dfsVisited, int target){
        if(nodeVisited[target] && !dfsVisited[target]) return false;
        if(dfsVisited[target]) return true;
        nodeVisited[target] = dfsVisited[target] = true;
        for(const auto node : adjList[target]){
            if(dfs(adjList, nodeVisited, dfsVisited, node)) return true;
        }
        dfsVisited[target] = false;
        return false;
    }
};
