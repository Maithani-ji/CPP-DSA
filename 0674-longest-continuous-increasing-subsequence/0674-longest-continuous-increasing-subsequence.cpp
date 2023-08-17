class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
       if(nums.size()==0)
       {
           return 0;
       }
       else if(nums.size()==1) //if size 1 return automatically 1
       {
           return 1;
       }
       
        int c=1; // current longest lenght
        int m=0; // max longest subarray lenght

        for(int i=0;i<nums.size()-1;i++) // for array grater than 1
        {
            if(nums[i]<nums[i+1]) // if next greater increse counter +1
            {
                c++;
                m=max(m,c);//store max length till indices of longest subarray
            }
            else{ //else restart the counter
            c=1;
             m=max(m,c);} //and store max size of longest sub sequence of array like {2,2,2,2,2}
        }
        return m;
        
    }
};