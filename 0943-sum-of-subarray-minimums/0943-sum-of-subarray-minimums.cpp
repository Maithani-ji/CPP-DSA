// class Solution { T-n^2
// public:
//     int sumSubarrayMins(vector<int>& A) {
//         int n = A.size();
//         int sum = 0;

//         // Iterate through all possible subarrays
//         for (int i = 0; i < n; i++) {
//             int minVal = A[i];
//             for (int j = i; j < n; j++) {
//                 minVal = min(minVal, A[j]);
//                 sum += minVal;
//             }
//         }

//         return sum;
//     }
// };

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        const int MOD = 1e9 + 7;
        long long sum = 0;  // Using long long to avoid integer overflow

        stack<pair<int, int>> leftStack, rightStack;

        vector<int> left(n), right(n);

        // Calculate left[i] for each index
        for (int i = 0; i < n; i++) {
            while (!leftStack.empty() && leftStack.top().first > A[i]) {
                leftStack.pop();
            }
            left[i] = leftStack.empty() ? i + 1 : i - leftStack.top().second;
            leftStack.push({A[i], i});
        }

        // Calculate right[i] for each index
        for (int i = n - 1; i >= 0; i--) {
            while (!rightStack.empty() && rightStack.top().first >= A[i]) {
                rightStack.pop();
            }
            right[i] = rightStack.empty() ? n - i : rightStack.top().second - i;
            rightStack.push({A[i], i});
        }

        // Calculate contribution of each element to the final sum
        for (int i = 0; i < n; i++) {
            sum += (long long)A[i] * left[i] * right[i];
            sum %= MOD;
        }

        return static_cast<int>(sum);
    }
};

