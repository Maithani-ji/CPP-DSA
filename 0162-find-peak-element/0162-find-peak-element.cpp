class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)// for only 1 element , that elemetn is peak
        {
            return 0;
        }
        int l=0;
        int h= nums.size()-1;

        while(l<=h)//using binary search with modification
        {
            int m= l+(h-l)/2;// by finding m we check  m-1<m>m+1 if yes return m

            if(m==0 )// first corner case if first element is greater than next or case when  if 2 elements in nums 
            //        and m is 0  , then we only check m>m+1
            { if( nums[m]>nums[m+1])  return m; // if true return m
              else l=m+1;//else l=m+1 - 
            }
            else if(m==nums.size()-1)// if m is last element , check m>m-1
            {
                if(nums[m]>nums[m-1]) return m;//if yes return m
                else h=m-1;// else h=m-1 
            }

            else {
                if(nums[m]>nums[m-1] && nums[m]>nums[m+1])// case when m-1<m>m+1
            {
                    return m;//if true return m
            }
            else if(nums[m]<nums[m+1])//else move to that side where m is less than ie if m<m+1
            {
                l=m+1;//then l=m+1
            }
            else h=m-1; } // else move to m-1 ie h=m-1
            
        }
        return -1;
        
    }
};