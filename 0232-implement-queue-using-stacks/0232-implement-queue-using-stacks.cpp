class MyQueue {
private:
    stack<int> st1;  // Stack for enqueueing elements
    stack<int> st2;  // Stack for temporary storage during dequeue and peek operations

public:
    MyQueue() {
        // Constructor (no need to initialize anything here)
    }

    // Push operation to enqueue an element
    void push(int x) {
        // Move all elements from st1 to st2
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        // Push the new element onto st1
        st1.push(x);

        // Move elements back from st2 to st1
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    // Pop operation to dequeue and return the front element
    int pop() {
        if (st1.empty()) {
            return -1;  // Return some appropriate value to indicate underflow
        }

        int front = st1.top();
        st1.pop();
        return front;
    }

    // Peek operation to return the front element without removing it
    int peek() {
        if (st1.empty()) {
            return -1;  // Return some appropriate value to indicate underflow
        }

        return st1.top();
    }

    // Check if the queue is empty
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */