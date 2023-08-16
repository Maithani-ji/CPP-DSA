class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //constaint given 
        if(nums.size()==0) return 0;
        
        //using two pointer approach 
        int i=0;
        //using i and j as 2 pointers 
        
        for(int j=1;j<nums.size();j++)
        {  // iterating j for finding same and unique elements
            if(nums[i]==nums[j])   //if found same then move j ahead till we found different
            {
                continue;
            }
            else
            {    //found different then movie i ahead which is duplicate and replace with the unique element we got
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1; //last unique indices + 1 for the lentgh f unique values
    }
};