class CustomStack {
    int target;          // Maximum allowed size of the stack
    std::vector<int> ans; // Vector to store stack elements
    
public:
    // Constructor initializes the maximum allowed size
    CustomStack(int maxSize) {
        target = maxSize;
    }
    
    // Pushes an element onto the stack
    void push(int x) {
        if (ans.size() < target) { // Check if the stack is not full
            ans.push_back(x);      // Push the element onto the vector
        }
    }
    
    // Pops an element from the stack and returns it
    int pop() {
        if (ans.size() == 0) {
            return -1; // Handle empty stack, return -1
        }
        int x = ans.back(); // Get the last element of the vector
        ans.pop_back();     // Remove the last element
        return x;           // Return the popped element
    }
    
    void increment(int k, int val) {
        // if(k>s){
        //     int i=0;
        // while(i<=s)
        // {
        //     ans[i]+=val;
        //     i++;
        // }
        // }
        // else{
        //  int i=0;
        // while(i<k)
        // {
        //     ans[i]+=val;
        //     i++;
        // }
        //                or

          int limit = min(k, (int)ans.size()); // // Determine the range to increment
        for (int i = 0; i < limit; i++) {
            ans[i] += val;// Increment each element within the limit with val
        }
        }
    
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */