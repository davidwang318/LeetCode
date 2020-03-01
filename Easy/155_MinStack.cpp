// First Attemp. Feels good to have think of using List.
// Time: 91.94%, Memory: 100.00%
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(minList.empty() || x <= minList.front()) minList.push_front(x);
        return;        
    }
    
    void pop() {
        if(s.top() == minList.front()) minList.pop_front();
        s.pop();
        return;
    }
    
    int top() {
        return s.top();        
    }
    
    int getMin() {
        return minList.front();        
    }
private:
    stack<int> s;
    list<int> minList;
};
