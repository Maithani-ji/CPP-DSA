// Define the BrowserHistory class
class BrowserHistory {

    vector<string> v; // Vector to store browsing history
    int pos; // Position marker to track the current position in history
    
public:

    // Constructor to initialize the browser history with a homepage URL

    BrowserHistory(string homepage) {
        v.push_back(homepage); // Add the homepage URL to the history
        pos = 0; // Initialize the position marker to 0
    }
    
    // Simulate visiting a new URL

    void visit(string url) {
        int s = v.size() - 1; // Get the index of the last element in history
        // Trim the history to match the current position
        while (s > pos) {
            v.pop_back(); // Remove URLs beyond the current position
            s--; // Decrement the size counter
        }
        v.push_back(url); // Add the new URL to the history
        pos++; // Update the current position marker
    }
    
    // Simulate going back a certain number of steps

    string back(int steps) {
        pos = pos - steps; // Update the position marker
        if (pos < 0) pos = 0; // Ensure the position doesn't go below 0
        return v[pos]; // Return the URL at the new position
    }
    
    // Simulate going forward a certain number of steps
    
    string forward(int steps) {
        pos = pos + steps; // Update the position marker
        if (pos > v.size() - 1) pos = v.size() - 1; // Ensure the position doesn't exceed history size
        return v[pos]; // Return the URL at the new position
    }
};

/*class BrowserHistory {
    stack<string> s;  // Stack to store the browsing history for back navigation
    stack<string> st; // Stack to store URLs for forward navigation
    
public:
    BrowserHistory(string homepage) {
        s.push(homepage); // Initialize the browsing history with the homepage
    }
    
    void visit(string url) {
        st = stack<string>(); // Clear the forward history stack
        s.push(url); // Add the new URL to the browsing history
    }
    
    string back(int steps) {
        string c;
        
        // Move back specified steps or until the browsing history is empty
        while (steps > 0 && !s.empty()) {
            c = s.top(); // Get the current URL
            st.push(c);  // Store the URL for possible forward navigation
            s.pop();     // Remove the URL from the current history
            steps--;     // Decrement the steps
        }
        
        if (!s.empty()) {
            return s.top(); // Return the current URL after moving back
        } else {
            s.push(c);       // Restore the top URL (since there's no history left)
            st.pop();        // Remove the URL from the forward history
        }
        
        return s.top();
    }
    
    string forward(int steps) {
        // Move forward specified steps or until the forward history is empty
        while (steps > 0 && !st.empty()) {
            string c = st.top(); // Get the URL from forward history
            s.push(c);           // Add the URL to the current history
            st.pop();            // Remove the URL from forward history
            steps--;             // Decrement the steps
        }
        
        return s.top(); // Return the current URL after moving forward
    }
};*/

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */