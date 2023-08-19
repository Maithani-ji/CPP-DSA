class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { //using binary search , since whole array is sorted like an array .

        int s=0;
        int j=matrix[0].size();
        int k= matrix.size();
        int l=(j*k)-1;

        while(s<=l)//start is 0 and end is row*col
        {
            int mid=s+(l-s)/2;//we find the mid as imaginary // taking 2d as a 1d array // with mid we use below formula
            
            if(matrix[mid/j][mid%j]==target)//we use mid/col  mid%col for rowth and colth value of that mid
            {
                return true;
            }
            else if(matrix[mid/j][mid%j]>target)//same as above 
            {
                l=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return false;

        
        
    }
};