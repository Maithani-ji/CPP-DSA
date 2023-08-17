class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int e=0,o=1; // using two pointer approach e starts from 0 and o starts from 1

        int n = nums.size();

        while(e<n && o<n) // till e and o < n
        {
            if(nums[e]%2==0)// if from starting 0 ie even indices founds even value move e to +2 
            {
                e+=2;
            }
            if(nums[o]%2==1)// if from o starting indices ie 1 found odd values at odd indices then move +2 for odd 
            {
                o+=2;
            }
            else // else if any not true , replace even indices element to odd indices element
            {
                swap(nums[e],nums[o]);
            }
        }
        return nums;
    }
};