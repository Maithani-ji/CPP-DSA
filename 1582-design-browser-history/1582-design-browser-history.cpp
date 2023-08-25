class BrowserHistory {
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
};


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */