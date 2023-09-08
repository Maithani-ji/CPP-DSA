class Solution {
public:
    vector<string> v; // A vector to store valid parentheses combinations

    // Recursive function to generate valid parentheses combinations
    void generate(int n, int cc, int co, string s = "") {
        // Base case: If we have used 'n' open and 'n' close parentheses, add the combination to the vector
        if (cc == n && co == n) {
            v.push_back(s);
            return;
        }

        // If we haven't used all open parentheses, add an open parenthesis
        if (co < n) {
            generate(n, cc, co + 1, s + "(");
        }

        // If we have used more open parentheses than close parentheses, add a close parenthesis
        if (cc < co) {
            generate(n, cc + 1, co, s + ")");
        }
    }

    // Function to generate valid parentheses combinations for a given 'n'
    vector<string> generateParenthesis(int n) {
        int co = 0; // Counter for open parentheses
        int cc = 0; // Counter for close parentheses
        generate(n, cc, co); // Start the generation process
        return v; // Return the vector containing valid combinations
    }
};
