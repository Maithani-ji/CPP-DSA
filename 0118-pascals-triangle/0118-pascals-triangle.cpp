class Solution {
public:
    vector<vector<int>> generate(int numr) {
        //using brute case N^2 ie going thorugh all rows with all columns

        vector<vector<int>> r(numr); // genreating empty vector of size nume ie  no of rows given

        for(int i=0;i<numr;i++) // going through each row
        {
                r[i].resize(i+1); // giving size to the vector within vector ie how much column in a row
                r[i][0]=r[i][i]=1; // assign start and end with 1 as it is shown

                for(int j=1;j<i;j++) // traversing columns after start and before end to fill them up , end=start=1
                {
                    r[i][j]=r[i-1][j-1] + r[i-1][j];// filling column with the previous rows j-1 and j sum
                }
        }
        return r; // returning two dimensional array

    }



    
};