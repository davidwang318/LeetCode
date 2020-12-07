struct BSTNode{
    int val;
    int count;
    int left_count;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(int val): val(val), count(1), left_count(0), left(nullptr), right(nullptr){}
    
    ~BSTNode() { delete left; delete right; }
    
    int lessEqualNum() const { return count + left_count; }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        std::reverse(nums.begin(), nums.end());
        std::unique_ptr<BSTNode> root(new BSTNode(nums[0]));
        vector<int> res {0};
        for (int i = 1; i < nums.size(); i++){
            res.push_back(insert(root.get(), nums[i]));
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
private:
    int insert(BSTNode* root, int num){
        if (root -> val == num){
            root -> count ++;
            return root -> left_count;
        }
        else if (root -> val > num){
            root -> left_count ++;
            if (!root -> left){
                root -> left = new BSTNode(num);
                return 0;
            }
            return insert(root -> left, num);
        }
        else{
            if (!root -> right){
                root -> right = new BSTNode(num);
                return root -> lessEqualNum();
            }
            return root -> lessEqualNum() + insert(root -> right, num);
        }
    }
};

// Using fenwick tree
class FenwickTree {    
public:
    FenwickTree(int n): sums_(n + 1, 0) {}
    
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const {        
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int x) { 
        return x & (-x); 
    }
    vector<int> sums_;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> sortNums {nums};
        sort(sortNums.begin(), sortNums.end());
        unordered_map<int, int> rankMap;
        int rank = 1;
        for (const auto& num : sortNums){
            if (rankMap.count(num)) continue;
            rankMap[num] = rank++;
        }
        reverse(nums.begin(), nums.end());
        FenwickTree fTree = FenwickTree(rankMap.size());
        vector<int> res;
        for (const auto& num : nums){
            fTree.update(rankMap[num], 1);
            res.push_back(fTree.query(rankMap[num]-1));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

