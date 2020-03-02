// First Attempt, spend many time trying to fix upper bound binary search.
// Time: 94.79%, Memory: 100.00%
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size(), col = matrix[0].size(), targetRow = 0;
        // Binary search row for upper bound:
        int l = 0, r = row-1;
        if (row > 1){ 
            while(l <= r){
                int mid = (r-l)/2 + l;
                if(matrix[mid][0] == target) return true;
                if(matrix[mid][0] > target) r = mid-1;
                else l = mid+1;
            }
            if(l == 0) return false;
            targetRow = l-1;
        }
        // Binary search column:
        l = 0; r = col-1;
        while(l <= r){
            int mid = (r-l)/2 + l;
            if(matrix[targetRow][mid] == target) return true;
            if(matrix[targetRow][mid] > target) r = mid-1;
            else l = mid+1;
        }
        return false;
        
        
    }
};

// Turns out that I should set the right boundary equals to its size, not size-1
// Time: 99.75%, Memory: 100.00%
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size(), col = matrix[0].size();
        // Binary search row for upper bound:
        int l = 0, r = row;
        while(l < r){
            int mid = (r-l)/2 + l;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] > target) r = mid;
            else l = mid+1;
        }
        if(l == 0 && row > 1) return false;
        int targetRow = (l == 0)? l : l-1;
        // Binary search column:
        l = 0; r = col;
        while(l < r){
            int mid = (r-l)/2 + l;
            if(matrix[targetRow][mid] == target) return true;
            if(matrix[targetRow][mid] > target) r = mid;
            else l = mid+1;
        }
        return false;
        
        
    }
};
