class MinStack {

    stack<int> mn, st; // Two stacks: one for maintaining minimum values and one for the main stack.
public:
    MinStack() {
        // Constructor, no explicit initialization needed.
    }
    
    void push(int val) {
        if (mn.empty())
            mn.push(val); // Initialize the minimum stack with the first element.
        else
            mn.push(min(val, mn.top())); // Push the current minimum between val and the top of mn.
      
        st.push(val); // Push the value onto the main stack.
    }
    
    void pop() {
        st.pop(); // Pop the value from the main stack.
        mn.pop(); // Pop the corresponding minimum value from the minimum stack.
    }  
    
    int top() {
        return st.top(); // Return the top value of the main stack.
    }
    
    int getMin() {
        return mn.top(); // Return the top value of the minimum stack (the current minimum).
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */