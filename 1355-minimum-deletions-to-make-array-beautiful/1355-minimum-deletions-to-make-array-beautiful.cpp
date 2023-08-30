class Solution {
public:
    int minDeletion(vector<int>& nums) {

        int cnt=0;  // Initialize a counter variable to keep track of deletions.

        // Loop through the vector until the second-to-last element.
        for(int i=0;i<nums.size()-1;i++)
        {
            // Check if the current index minus the count of deletions is even and
            // if the current element is the same as the next element.
            if((i-cnt)%2==0 && nums[i]==nums[i+1])
            {
                cnt++;  // Increment the counter to indicate a deletion.
            }
        }

        // Check if the final count of elements after deletions is odd.
        // If it is odd, it means one more deletion is needed to make it even.
        if((nums.size()-cnt)%2)
        {
            cnt++;  // Increment the counter.
        }

        return cnt;  // Return the total count of deletions needed.
    }
};
