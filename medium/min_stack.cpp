class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }

        stack.push_back(val);
    }
    
    void pop() {
        int val = stack.back();
        if (val == minStack.back()) {
            minStack.pop_back();
        }

        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }

    vector<int> stack;
    vector<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */