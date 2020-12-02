class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const vector<int> dirs {0, -1, 0, 1, 0};
        const int rows = heights.size();
        const int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        using Node = pair<int, int>; // Node represents the row/col index
        priority_queue<pair<int, Node>, vector<pair<int, Node>>, greater<pair<int, Node>>> q;
        q.emplace(0, make_pair(0, 0));
        dist[0][0] = 0;
        while(!q.empty()){
            auto [minCost, cor] = q.top(); q.pop();
            if (visited[cor.first][cor.second]) continue; // The cost of the node may be updated by other node
            visited[cor.first][cor.second] = true;
            for(int i = 0; i < 4; i++){
                const int r = cor.first + dirs[i];
                const int c = cor.second + dirs[i+1];
                if(r < 0 || c < 0 || r >= rows || c >= cols) continue;
                const int cost = max(abs(heights[cor.first][cor.second] - heights[r][c]), minCost);
                if (cost < dist[r][c]){
                    dist[r][c] = cost;
                    q.emplace(cost, make_pair(r, c));
                }
            }
        }
        return dist.back().back();
    }
};
