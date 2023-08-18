
class Solution {
 public:
void duplicateZeros(vector<int>& A) {
        int n = A.size(), j = n + count(A.begin(), A.end(), 0);//storing array size=n and count of zero + size of array=j
        for (int i = n - 1; i >= 0; --i) {//traversing array from back , to accomadate spcae for extra 0's  
            if (--j < n)//if not zero element and --j>n , decrement i for making space for zeros ,if --j<n then put i val to j
                A[j] = A[i];
            if (A[i] == 0 && --j < n)//if val is 0 and --j<n then put 0 to val j; because other values are gone and space is made.
                A[j] = 0;
        }
    }
};


// // Solution (using swap())
// class Solution {
// public:
//     void duplicateZeros(vector<int>& nums) {
//         int count=0, n=nums.size();
//         for(int i=0; i<n; i++)
//         {
//             if(nums[i]==0 && (i+1)<n){
//                 for(int j=n-1; j>i+1; j--)
//                     swap(nums[j], nums[j-1]);
//                 nums[++i]=0;
//             }
//         }
//     }
// };

// // Solution 2 (Using insert and resize)
// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr) {
//         int i=0, n=arr.size();
//         while(i<n)
//         {
//             if(arr[i]==0)
//             {
//                 arr.insert(arr.begin()+i, 0);
//                 i += 2;
//             }
//             else
//                 i++;
//         }
//         arr.resize(n);
//     }
// };