class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m= mat.size(); // m is row
        int n=mat[0].size();// n is column means how many colums has mat[0] 
        int mn = m*n;

        if(mn != (r*c)) // number of element should be same 
        {
            return mat;
        }

        vector<vector <int>> ans (r , vector<int>(c,0)); // 2D ARRAy " vector<vector <int>> ans (r,)" -> show outer 
                                                        // initalise vector of size r which is row , vector<int>(c,0)- 
                                                        //inner 
                                                        //vector initialise with size n.
        for(int i=0; i<mn;i++)
        {
            ans[i/c][i%c]=mat[i/n][i%n];// formula for assigning elelemnt from 1 array to other using row and column of their own 2D array
        }
        return ans;
    }
};