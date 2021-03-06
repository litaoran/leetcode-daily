class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> s;
    stack<int> s_min; // Always store the minimum value
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if (s_min.empty() || x <= s_min.top()) {
            s_min.push(x);
        }
        
    }
    
    void pop() {
        int x = s.top();
        if (s_min.top() == x) {
            s_min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s_min.top();
    }
};
