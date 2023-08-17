class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // CAN use  TWO POINTERS with sorting T-nlogn S-1--> i=0,j=1:  move both ahead , if found j-i=k , k++ i++ 
        // count ++ , then , traverse- if j-1 and j same , j++ to ignore duplicate . If j-i < k or j-i>k use j++ or 
        // i++ 
        //using OPTIMISED approach but using extra space
        if(nums.size()==0)
        {
            return 0;
        }
        if(k<0) // if k given -ve
        {
            return 0;

        }

        unordered_map<int,int> m; //using map sinmce it gives search of element in O(1)

        for(auto i: nums) //inserting element with their count in hash map
        {
            m[i]++;  //element with count
        }

        int count=0;

        for(auto j : m) // traversing through map element not nums array , since array contain duplicate
        {
            if((!k && j.second >1) || (k && m.count(k+j.first))) //check case if k=0 , then if element >1  
            {                                                       // if k>0 , find k+j.first in hash map 
                count++;                                    // if present then its a pair - count(used as find) gives
                //                                             true if count >0 
            }
            
        }
        return count;
    }
};