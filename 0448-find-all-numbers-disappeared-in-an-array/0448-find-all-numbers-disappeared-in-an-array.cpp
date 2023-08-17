class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        // we can use set and check the values inside the range 1-n is present or not 

        // using marking of values with their indices and if present then turning the value at that value indices to
        // negative
        //if not negative then their indices is the number not present

        vector<int > ans;

        

        for(int i=0;i<nums.size();i++)
        {
            int ind= abs(nums[i])-1; // marking  abs( value)-1 -> indices -> value to negative 
            if(nums[ind]>0) // if its already  -ve  leave it 
            {
                nums[ind]*=-1;
            }
        }

        for(int i=0;i<nums.size();i++) // push non negative elements to ans array with +1
        {
            if(nums[i]>0)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};