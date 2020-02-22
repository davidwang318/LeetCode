// First Attempt. Using two queue.
// Time: 73.45%, Space: 88.89%
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> qCur, qSuc;
        TreeNode* cur = NULL;
        qSuc.push(root);
        while(!qSuc.empty()){
            int cnt = 0;
            double total = 0;
            swap(qCur, qSuc);
            while(!qCur.empty()){
                cur = qCur.front(); qCur.pop();
                total += cur -> val;
                cnt ++;
                if(cur -> left) qSuc.push(cur -> left);
                if(cur -> right) qSuc.push(cur -> right);            
            }
            res.push_back(total/cnt);
        }       
        return res;
    }
};

// Use size, always forget!
// Time: 92.76%, Space: 88.89%
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            int len = q.size();
            double sum = 0;
            for (int i = 0; i < len; i++){
                root = q.front(); q.pop();
                sum += root -> val;
                if(root -> left) q.push(root -> left);
                if(root -> right) q.push(root -> right);
            }
            res.push_back(sum/len);
        }       
        return res;
    }
};

// BFS solution.
// Time: 73.45%, Space: 100.00%
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;
        vector<int> cnt;
        dfsAverage(root, sum, cnt, 0);
        for(int i = 0; i < cnt.size(); i++){
            sum[i] /= cnt[i];
        }
        return sum;
    }
    
    void dfsAverage(TreeNode* root, vector<double>& sum, vector<int>& cnt, int level){
        if(!root) return;
        if(sum.size() < level+1){
            sum.push_back(0);
            cnt.push_back(0);
        }
        sum[level] += root -> val;
        cnt[level] ++;
        dfsAverage(root -> left, sum, cnt, level+1);
        dfsAverage(root -> right, sum, cnt, level+1);
        return;
    }
};
