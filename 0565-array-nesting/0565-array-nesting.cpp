class Solution {
public:
    int arrayNesting(vector<int>& A) {
        int res = 0, n = A.size();
        for (int i = 0; i < n; i++) {//traversing array
            if (A[i] >= 0) {//checking if it is not already marked
                int cnt = 0;//initialise count as 0 for every element , which make loop
                while (A[i] >= 0) {// till loop get !-ve , move forward
                    int temp = i;//storing temp the indx value, so during -ve marking it wont change
                    i = A[i];// storing that element value as index for next element for loop 
                    A[temp] = -1; // Mark the element as visited
                    cnt++;//count till not find the loop
                }
                res = max(res, cnt);//store the loop size
            }
        }
        return res;  
    }
};