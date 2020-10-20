class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Case0: empty intervals
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int len = intervals.size();
        int start = len;
        // Find the start index
        for (int i = 0; i < len; i++){
            if (intervals[i][1] >= newInterval[0]) {
                start = i;
                break;
            }
        }
        // Case1: No start position
        if (start == len){
            intervals.push_back(newInterval);
            return intervals;
        }
        // Find the end index
        int end = len - 1;
        for (int i = start; i < len; i++){
            if (intervals[i][0] > newInterval[1]){
                end = i - 1;
                break;
            }
        }
        // Case2: No overlap 
        if (end < start){
            intervals.insert(intervals.begin()+start, newInterval);
            return intervals;
        }
        // Erase and insert
        newInterval[0] = min(newInterval[0], intervals[start][0]);
        newInterval[1] = max(newInterval[1], intervals[end][1]);
        intervals.erase(intervals.begin()+start, intervals.begin()+end+1);
        intervals.insert(intervals.begin()+start, newInterval);
        return intervals;
        
    }
};
