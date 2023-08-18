

//         class Solution {
// public:
//     int oddCells(int m, int n, vector<vector<int>>& indices) {
//         vector<vector<int>> mat(m,vector<int>(n,0));//creating 2d array to store increment array using indices
//         int t=indices.size();
//             for(int i=0;i<t;i++)//row traverse
//             {
//                 for(int j=0;j<n;j++)//traverse column for increasing perticular row value by 1 , indices 1st value represent matrow
//                 {
//                     mat[indices[i][0]][j]++;//incrasing mat's indices[i][0] whole row value by 1
//                 }
//                 for(int k=0;k<m;k++)//traverse row for increasing perticular columns value by,indices 2nd value represent matscolumn 
//                 {
//                     mat[k][indices[i][1]]++;//increment mat's indices[i][1] columns wale by 1
//                 }
            
//         }
//         int c=0;//counting number of odd values in array mat
//         for(int i=0;i<mat.size();i++)
//         {
//             for(int j=0;j<mat[i].size();j++)
//             {
//                 if(mat[i][j]%2==1)
//                 c++;
//             }
//         }
//         return c;
//     }
// };
                //                                   TC-m*n*t    Sc - m*n

                //optimised code using two different 1d array  T-m*n S-m+n


class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m,0);//creating row array with 0 value of size m 
        vector<int> col(n,0);//cresting col array with 0 value of size n

        for(auto i:indices)//traverse indices matrix
        {
            int r = i[0];//storing indices for row , to increment that row all value by 1
            int c = i[1];//storing indices for col , to increment that col all value by 1

            row[r]++;//incrementing r index row value ++ 
            col[c]++;//incrementing c index col value ++
        }
        int ctr = 0;//have count of odd value

        for(int i=0;i<m;i++)//traversing row
        {
            int cur = row[i];//stroing value of row

            for(int j=0;j<n;j++)//traversing col ,, traversing both row and col as 2d arrray but both are in 1d
            {
                int total = cur + col[j];//adding row and col to mix row and col value ,as it is in 2d
                if(total % 2 == 1)//if total is /by 2 ,not odd
                {
                    ctr++;
                }
            }
        }
        return ctr;

    }
};





