class Solution {//brute force , use sorting  and then last kth digit will be the largest k 
public:
    int findKthLargest(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());//sort

        return nums[nums.size()-k];//last kth number is the largest k 
        
    }
};