class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size()); // using n  space storage for T-n 
        int l = 0, r = A.size() - 1; // using two pointer left and right 
        for (int k = A.size() - 1; k >= 0; k--) {// we have to fill from back of the new array from large to small
            if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--]; //if abs(left)>right element - > push back its square in array
            else res[k] = A[l] * A[l++]; // else push back left square element of array.
        }
        return res;
    }
};