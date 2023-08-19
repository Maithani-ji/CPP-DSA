class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        int col0=true;//use 1st row and col as array to mark if at that row and col , 0 have or not , but since row0col0
        //              merge with row we seperately mark it with true or false

        for(int i=0;i<n;i++)//traverse thorugh rows
        {   if(matrix[i][0]==0) col0=false; // if any row of 1st column has 0 , then mark the col0 false
            for(int j=1;j<m;j++)//traversing columms from 1 , since 0 col storing marking of 0,and 0 getting checked above.
            {
                if(matrix[i][j]==0)//if any value found 0 ,  even row or col , mark both that 0th col row and 0th row col 0
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=n-1;i>=0;i--)//then traverse from back , and start checking row and col with 0th row and col 
        {
            for(int j=m-1;j>=1;j--)//going till 1 since , col0 marker is reponsible for 0th column
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)// if marked 0 1st row and col , then turn that element to 0
                {
                    matrix[i][j]=0;
                }
              
            }
            
            if(!col0)//checking for 0th col elements of any row , ie col0 is marked ,if found any thne put 0 
            {
                matrix[i][0]=0;
            }
        }
        
    }
};

