class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i =m-1;
        int j= n-1;
        int k= m+n-1;
         
         while(j>=0)  //we use two pointers approach 
         {
             if( i>=0 && nums1[i]>nums2[j] )  // i pointer for nums1 and j for nums2 
             { nums1[k]=nums1[i];             // we use k size nums1 for elemnts to be added from both array to 
                                                // nums 1 
                 
                 k--;                           //we check i and j elements from last of arrays which is greater and 
                                                // put the greater one in the  k size nums from back 
                 i--;
             }
             else                               // and reduce k ,i ,j as they get filled and get emptied
             {
                 nums1[k]=nums2[j];
                 j--;
                 k--;
             }
         }
    }
};