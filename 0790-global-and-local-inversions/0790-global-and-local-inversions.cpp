//If the absolute difference abs(A[i] - i) is greater than 1, it means that the element is too far from its correct position, indicating a global inversion. A global inversion occurs when an element A[i] is greater than an element A[j] where i < j, but in a sorted array, A[i] should come before A[j]. In such a case, the function returns false immediately, indicating that the array is not an ideal permutation.
//The logic behind this approach is based on the property of an ideal permutation. In an ideal permutation, the number of global inversions is equal to the number of local inversions, where a local inversion occurs when an element is greater than its adjacent element. Since every global inversion is also a local inversion, an array with only local inversions is guaranteed to be an ideal permutation.
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i= 0; i<nums.size(); i++)
        {//in Simple Words - local inversion checks next greater element ,if it true then it is also global inversion 
//             // AND to be same number of local and global inversion , global inversion should be local inversion. ie current element only be greater than next element, if found greater than next to next element ,then it will be global inversion and not local inversion .thus not same number of global and local inversion
            if(abs(nums[i]-i)>1)
            return false;
        }
        return true; //If the loop completes without finding any global inversions (i.e., all elements are within one position of their correct positions), the function returns true, indicating that the array is an ideal permutation.          

    }
};

// // the function checks if mx (the maximum element encountered so far) is greater than the element two positions ahead, nums[i+2]. If this condition is true, it means that we have found a global inversion where an element at index i is greater than an element two positions ahead at index i+2. In such a case, the function immediately returns false as the array is not an ideal permutation.
// class Solution {
// public:
//     bool isIdealPermutation(vector<int>& nums) {
// //If the loop completes without encountering any global inversions, it means that all the local inversions in the array are also global inversions, and the function returns true, indicating that the array is an ideal permutation.



//         int mx=-1;
//         for(int i=0;i<nums.size()-3;i++)
//         {
//             mx= max(mx,nums[i]);
//             if(mx>nums[i+2])//we are checking global inversion , if any present we return false because,
//             //                we are given local inversion is global inversion but global inversion is not local.-> 
//             // in Simple Words - local inversion checks next greater element ,if it true then it is also global inversion 
//             // AND to be same number of local and global inversion , global inversion should be local inversion. ie current element only be greater than next element, if found greater than next to next element ,then it will be global inversion and not local inversion .thus not same number of global and local inversion
//             {
//                 return false;
//             }
//         }
//         // 
//         return true;
//     }
// };