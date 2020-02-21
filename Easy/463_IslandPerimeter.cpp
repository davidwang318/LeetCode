// Better to use 1 not 0 to count connection
// Time: 80.38%, Space: 85.71%
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0, area = 0;
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[0].size(); col++){
                if (grid[row][col]){
                    area ++;
                    if(row != 0 && grid[row-1][col]) cnt ++;
                    if(col != 0 && grid[row][col-1]) cnt ++;
                    if(row != grid.size()-1 && grid[row+1][col]) cnt ++;
                    if(col != grid[0].size()-1 && grid[row][col+1]) cnt++;
                }
            }
        }
        return 4*area - cnt;
    }
};
