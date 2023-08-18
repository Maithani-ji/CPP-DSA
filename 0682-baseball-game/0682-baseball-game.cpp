class Solution { 
public:
    int calPoints(vector<string>& op) {
        stack<int> st; // Create a stack to store scores
        
        for(auto ops : op) {
            if(ops[0] == 'C') {
                st.pop(); // Remove the last valid score
            } else if(ops[0] == 'D') {
                int temp = st.top(); // Get the last valid score
                st.push(2 * temp); // Double the last valid score and push onto stack
            } else if(ops[0] == '+') {
                int temp = st.top(); // Get the last valid score
                st.pop();
                int temp2 = st.top(); // Get the second last valid score
                st.push(temp); // Push back the last valid score
                st.push(temp + temp2); // Push the sum of last two valid scores
            } else {
                int val = stoi(ops); // Convert string to integer
                st.push(val); // Push the score onto stack
            }
        }
        
        int sum = 0;
        while(!st.empty()) {
            sum += st.top(); // Add each score to the total sum
            st.pop(); // Pop the processed score from the stack
        }
        return sum; // Return the total sum of scores
    }
};
