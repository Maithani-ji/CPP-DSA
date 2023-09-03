
class Solution {
public:
    int clumsy(int n) {
        stack<int> st; // Initialize a stack to keep track of intermediate results.
        st.push(n); // Push the first operand onto the stack
        int j = 0; // Initialize an operator index.
        
        for (int i = n - 1; i > 0; i--) {
            if (j % 4 == 0) {
                st.top() *= i; // Multiplication: Multiply the top element by i and update it.
            } else if (j % 4 == 1) {
                st.top() /= i; // Division: Divide the top element by i and update it.
            } else if (j % 4 == 2) {
                // For addition and subtraction, just push the operand onto the stack.
                st.push(i); // Push the next operand (addition).
            } else {
                // For subtraction, push the operand as a negative value onto the stack.
                st.push(-i); // Push the next operand as a negative value (subtraction).
            }
            j++; // Increment the operator index to switch to the next operator in the pattern.
        }
        
        int result = 0; //calculate addition all the +ve and -ve val in stack to result 
        while (!st.empty()) {
            result += st.top(); // Add the top element to the result.
            st.pop(); // Pop the top element from the stack.
        }
        
        return result; // Return the final result, which is the evaluation of the clumsy expression.
    }
};

