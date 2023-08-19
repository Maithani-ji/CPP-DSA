// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) { // using given condn that array contain n+1 integers range from 1 to n

//         for(int i=0 ; i<nums.size();i++)// therefore using above condition we use array values as index to convert
//         //                                 that index value negative if found that value non negative.
//         //                                 if found that index value -ve , means we already have converted it to -ve hence
//         //                                 that array element acting as index is duplicate
//         {
//             if(nums[abs(nums[i])]>0)// using abs because element acting as index and cannot be -ve
//             {
//                 nums[abs(nums[i])]*=-1;// if non negative that index elment turn it to -ve
//             }
//             else
//             return abs(nums[i]);// if that is -ve then give the abs of array element acting as index im return
//         }
//         return -1;
        
//     }
// };

// USE LINKED LIST LOOP CONCEPT 
class Solution {
public:
    int findDuplicate(vector<int>& nums){
        int slow = nums[0];
        int fast = nums[0];

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast) {
                break;
            }
        }

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};