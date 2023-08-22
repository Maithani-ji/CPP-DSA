class MyStack {
    // Two queues to implement the stack
    queue<int> q1;
    queue<int> q2;

public:
    // Constructor (empty in this case)
    MyStack() {

    }

    // Push operation to add an element to the stack
    void push(int x) {
        // Move elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Add the new element to q1
        q1.push(x);

        // Move elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Pop operation to remove and return the top element from the stack
    int pop() {
        if (q1.empty()) {
            return -1; // Return some appropriate value to indicate underflow
        }

        int top = q1.front();
        q1.pop();
        return top;
    }

    // Top operation to return the top element without removing it
    int top() {
        if (q1.empty()) {
            return -1; // Return some appropriate value to indicate underflow
        }

        return q1.front();
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */