// My solution. Can do better
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (s1.empty()) front = x;
        s1.push(x);
        return;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int top = s2.top(); s2.pop();
        front = s2.empty()? -1 : s2.top();
        while(!s2.empty()) {
            s1.push(s2.top()); 
            s2.pop();
        }
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1, s2;
    int front;
};

// The key is the if condition in the shiftStack() function
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        return;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shiftStack();
        int top = s2.top(); s2.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        shiftStack();
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    void shiftStack() {
        if (!s2.empty()) return;
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return;
    }
    stack<int> s1, s2;
};
