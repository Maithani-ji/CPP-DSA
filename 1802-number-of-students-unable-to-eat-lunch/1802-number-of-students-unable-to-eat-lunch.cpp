class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sa) {
        queue<int> st; // Queue to store students in the initial order.
        queue<int> qu; // Queue to store students in the desired order.
        bool flag = false; // Flag to track if all students are accommodated.

        // Populate the student queues with the provided data.
        for (auto c : s) {
            st.push(c);
        }
        for (auto c : sa) {
            qu.push(c);
        }

        int count = 0; // Counter to track rotations.

        // Continue until all students are accommodated or conditions met.
        while (!flag) {
            if (qu.empty()) {
                return 0; // If the desired order queue is empty, return 0.
            }

            if (qu.front() == st.front()) { // If matching students are found.
                st.pop(); // Remove the student from the initial order queue.
                qu.pop(); // Remove the student from the desired order queue.
                count = 0; // Reset the rotation counter.
            } else {
                int x = st.front();
                st.pop();
                st.push(x); // Rotate the queue by moving the front student to the end.
                count++;

                if (count == qu.size()) { // If rotations match desired order size.
                    flag = true; // Set the flag to exit the loop.
                }
            }
        }

        return qu.size(); // Return the count of remaining students in the desired order queue.
    }
};
