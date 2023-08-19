class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {//since given array of size n contain value 1- n , therefore going 
    // all element as an index and turning that index value -ve , and if we found -ve value for other valued index , it is
    // duplicate.
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {//traversing through values
            int index = abs(nums[i])-1 ;//converting values as index 
            //since size is n & range of element is from 1-n including n , not n-1, that why -1 is done for index
            if (nums[index] < 0) {//if found that index already -ve , push that index -1 to ans array.
                ans.push_back(index+1 );
            } else { // if not -ve make it negative
                nums[index] = -nums[index];
            }
        }
        return ans;
    }
};