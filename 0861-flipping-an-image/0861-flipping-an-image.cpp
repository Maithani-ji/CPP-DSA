

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size();
       
        int n=image[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<(n+1)/2;j++) // inner loop ie column loop working till half 
            //                            
            {
               int temp;
               //swapping of values ie reversing of row elemnts with (xor) ^1 -turn 1 to 0 and 0 to 1
               temp =image[i][j]^1; // storing before half columns element to temp variable. 
              image[i][j] =image[i][n-j-1]^1;//swapping with later half elemtns from back .using n-j-1 formula
              //                             which gives jth number element from back without traversing full col 
              //                             length
              image[i][n-j-1]=temp;// swapping of later half with before half
                
                
               
               
            }
        }
        return image;
    }
};