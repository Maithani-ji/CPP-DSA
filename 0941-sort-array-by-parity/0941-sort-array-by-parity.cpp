class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int n = nums.size();
        if(n==0)
        {
            return {};
        }

        for(int i=0, j=1 ; i<n && j<n ;)// use two pointers to traverse i=0 and j=1 
        {
            if(nums[i]%2==0)// if starting val at at i is  / 2 then just simply move forward beacause even number have to be in front
            {
                i++;
                j++;

            }
            else
            {
                if(nums[j]%2==0) // else  if at j it is /2 ,swap with position i, becasue even number have to be in front 
                {
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }
                else// else if i and j both not / by 2 .. move forward with j and i will be at same place if found j even in futurei
                //     we can swap it with stopped i and then it can inrement like 2 nd condition
                {
                    j++;
                }
            }
        }
        return nums;
        
    }
};