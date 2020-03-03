// First Attempt. Using priority queue.
// Time: 54.80%, Memory: 36.36%
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for (auto r : matrix){
            for (auto c : r) q.push(c);
        }
        while(q.size() > k) q.pop();
        return q.top();
    }
};

// Great use of Binary search!
// Time: 83.40%, Memory: 9.09%
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while(left < right){
            int cnt = 0, mid = (right-left)/2 + left;
            for(auto row : matrix){
                cnt += std::upper_bound(row.begin(), row.end(), mid) - row.begin();
            }
            if(cnt >= k) right = mid;
            else left = mid+1;
        }
        return left;
    }
};
// Implement my upper_bound.
// Time: 84.40%, Memory: 9.09%
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while(left < right){
            int cnt = 0, mid = (right-left)/2 + left;
            for(auto row : matrix){
                cnt += count_upper(row, mid);
            }
            if(cnt >= k) right = mid;
            else left = mid+1;
        }
        return left;
    }
private: 
    int count_upper(vector<int> v, int target){
        if(v[0] > target) return 0;
        if(v.back() <= target) return v.size();
        int l = 0, r = v.size();
        while(l < r){
            int mid = (r-l)/2 + l;
            if(v[mid] <= target) l = mid+1;
            else r = mid;
        }
        return l;
    }
};
