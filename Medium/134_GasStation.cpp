// First Attempt
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        vector<int> diff (len*2, 0);
        for (int i = 0; i < len; i++) {
            diff[i] = diff[i+len] = gas[i] - cost[i];
        }
        for (int i = 0; i < len; i++) {
            if (diff[i] < 0) continue;
            int sumDiff = 0;
            for (int j = i; j < len + i; j++) {
                sumDiff += diff[j];
                if (sumDiff < 0) break;
            }
            if (sumDiff >= 0) return i;
        }
        return -1;        
    }
};

// clean code
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size(), start = 0, allSum = 0, curSum = 0;
        for (int i = 0; i < len; i++) {
            allSum += gas[i] - cost[i];
            curSum += gas[i] - cost[i];
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        return allSum >= 0? start : -1;
    }
};
