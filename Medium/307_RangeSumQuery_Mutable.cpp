// Answer from huahualeetcode
class BinaryIndexTree {
public:
    BinaryIndexTree(int n): biTree_(n+1, 0) {}
    void update(int idx, int delta){
        while (idx < biTree_.size()){
            biTree_[idx] += delta;
            idx += lowbit(idx);
        }
        return;
    }
    int query(int idx) const {
        int sum = 0;
        while (idx > 0){
            sum += biTree_[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
    
private:
    static inline int lowbit(int x) {return x & (-x);}
    vector<int> biTree_;  
};

class NumArray {
public:
    NumArray(vector<int>& nums): nums_(nums), tree_(nums_.size()) {
        for (int i = 0; i < nums_.size(); i ++){
            tree_.update(i+1, nums_[i]);
        }
    }
    
    void update(int i, int val) {
        tree_.update(i + 1, val - nums_[i]);
        nums_[i] = val;
    }
    
    int sumRange(int i, int j) {
        return tree_.query(j + 1) - tree_.query(i);
    }
private:
    vector<int> nums_;
    BinaryIndexTree tree_;
};
