class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        sort(nums.begin(),nums.end());//we first sort the array 

       int total=0;//initialise total to 0, ie how much addition we should do to make it unique
        for(int i=1;i<nums.size();i++)//traverse from 1 , since we need the use of preivous value
        {
            if(nums[i]<=nums[i-1])//we check if previous value is >= current
            {
                total+=nums[i-1]-nums[i]+1;// if yes then we increment the toal with previous-current value to make it equal and //                                            +1 to make it greater ie unique , therefore total+=prev-current+1
                nums[i]=nums[i-1]+1;//we need to update the current to prev +1 ,to make it unique and for checking with next val
            }
        }
        return total;
        
    }
};