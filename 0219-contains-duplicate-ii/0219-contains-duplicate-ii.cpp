class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0) return false;
            unordered_map<int,int> m; // suing hash maps

            for(int i=0;i<nums.size();i++) // traversing through elements
            {
                if(m.count(nums[i])) // if that element exist in map
                {
                    if(abs(i-m[nums[i]])<=k) // then  check the indices - that map element stored indices <=k
                    {
                        return true; // if true return true

                    }

                }

                m[nums[i]]=i; // else keep on adding new element as key and  indices as its value 
                 //            and updating previous found duplicate element if its 
                                // above condition is not true
            }
            return false;


    }
};