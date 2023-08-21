#include <vector>
#include <stack>

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;  // Stack to store indices of prices
        
        // Loop through each element in the 'prices' vector
        for (int i = 0; i < prices.size(); i++) {
            // While the stack is not empty and the current price is less than or equal to the price at the index stored in the stack's top
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                // Calculate the discount by subtracting the current price from the price at the index stored in the stack's top
                prices[st.top()] -= prices[i];
                // Remove the index from the stack since its discount has been calculated
                st.pop();
            }
            // Push the current index onto the stack
            st.push(i);
        }

        // Return the modified 'prices' vector containing the calculated final prices after discounts
        return prices;
    }
};
