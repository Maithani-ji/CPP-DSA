class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int n=nums.size();
        int mx,mn,curmx,curmn,total;
        mx=INT_MIN;
         mn=INT_MAX;
          curmx=0;
           curmn=0; 
            total=0;
       for(int i=0;i<n;i++)// using "modified" kadane's algo for max sum of subarray  and for min sum of subarray 
        {
            total+=nums[i];// storing total sum of array 

            curmx+=nums[i];//using kadanes to find the max sum subarray 
            mx= max(mx,curmx);
            curmx=max(0,curmx);


            curmn+=nums[i];//using min sum of subarray of array
            mn= min(mn,curmn);
            curmn= min(0,curmn);
          
           

        }
        if(total==mn)// if all given in array is negative , then the mx will be storing the smalles -ve value closer to 0.
        {
            return mx;
        }
        else // if having BOTH +ve and -ve , then either the max of subarray will be , inside the normal array ie mx, 
        //      or from last to start , ignoring middile ie , total-mn , ie min in mid ,and start and end makes max.
        return max(mx,total-mn);
        
        
    }
};

