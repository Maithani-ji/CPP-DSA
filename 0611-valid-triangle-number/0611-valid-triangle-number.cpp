class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end());//sorting the array for , since all will be in increasing order , and just we have to
        //                              focus on a+b>c not b+c>a or c+a>b
        int count =0;//storing no of triangle possible
        for(int i=nums.size()-1;i>=2;i--)// fixing the bigger element c from back every time , till 2 index, for a&b
        {
            int low =0;// a as low from start
            int high=i-1;// b as high from fixed -1

            while(low<high) // we search how many in between low and high ,whose sum gives > c
            {
                if(nums[low]+nums[high]>nums[i])//if greater 
                {   
                    count+=high-low; //store number of triangle possible , ie high - low give no of possible triangle 
                    high--;//then for next possible triangle , decrement high,to check if other triangle possble for high--
                }//  SINCE REPEATITION IS ALLOWED 
                else//if not greater, triangle condition fails , we move low forward ,to make the a+b sum greater
                {
                    low++;
                }
            }


        }
        return count;
        
    }
};