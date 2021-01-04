// Hard question: O(log(n))
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty()){
            maxHeap.push(num);
            return;
        }
        if (num < maxHeap.top()) {
            maxHeap.push(num);
            if (maxHeap.size() - minHeap.size() > 1) {
                minHeap.push(maxHeap.top()); maxHeap.pop();
            }
        }
        else {
            minHeap.push(num);
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top()); minHeap.pop();
            }
        }
        return;        
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        return maxHeap.top();
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int> maxHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
