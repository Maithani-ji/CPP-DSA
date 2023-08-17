class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)
        {
            return false;
        }

        // sort(nums.begin(),nums.end());  BRUTE FORCE APPRAOCH - TIME nlogn  space 1
        // int k= nums.size();
        // for(int i=0;i<k-1;i++)
        // {
        //     if(nums[i]==nums[i+1])
        //     {
        //         return true;
        //     }
         
        // }
        // return false;

        //                    2nd appraoch USING SET or HASH MAP -- time same (n)  space (n)
                // using set -- stores unique element
        
        unordered_set<int> s(nums.begin(),nums.end());
            
        if(s.size() == nums.size())
        {
            return false ;
        }
        else
        {
            return true;
        }

            // using HASH MAP -- we can traverse element and store their frequency , if found greater than 1 , we can
                // return true else at last false

    }
};