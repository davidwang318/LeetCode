/**
Important things to know: static, lambda, sort.
Put the taller one first, because the shorter one won't affect the second number of the taller one.
So we can make sure the relative position based on the second indices.
**/
class Solution {
public:
    /**
    // stl::sort required to have a static function for sorting
    static bool wayToSort(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    };
    **/
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // sort(people.begin(), people.end(), wayToSort);
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        for (auto p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};

// Space complexity: O(1)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        for (int i = 0; i < people.size(); i++) {
            vector<int> tmp = people[i];
            if(tmp[1] != i){
                people.erase(people.begin()+i);
                people.insert(people.begin()+tmp[1], tmp);
            }
        }
        return people;
    }
};
