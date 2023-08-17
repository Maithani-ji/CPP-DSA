class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

                // TOEPLITZ matrix has every diagonal from row 1 same left to right  

            int m=matrix.size();
            int n=matrix[0].size();
        for(int i=0;i<m-1;i++)// m-1 because last column element have no diagonal but part of previous diagonal if toeplitz
        {
            for(int j=0;j<n-1;j++)// n-1 because last row has no diagonal l-r  but part of previous diagonal if teoplitz
            {
                if(matrix[i][j]!=matrix[i+1][j+1])//toeplitz matrix formula m[i][j]==m[i+1][j+1] while traversing for 
                //                                   every element
               {
                    return false;
               }
            }
        }
        return true;}

        
    
};

