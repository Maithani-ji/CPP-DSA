//When the elements are the same as the candidate element, votes are incremented whereas when some other element is found (not equal to the candidate element), we decreased the count. This actually means that we are decreasing the priority of winning ability of the selected candidate, since we know that if the candidate is in majority it occurs more than N/2 times and the remaining elements are less than N/2. We keep decreasing the votes since we found some different element(s) than the candidate element. When votes become 0, this actually means that there are the equal  number of votes for different elements, which should not be the case for the element to be the majority element. So the candidate element cannot be the majority and hence we choose the present element as the candidate and continue the same till all the elements get finished. The final candidate would be our majority element. We check using the 2nd traversal to see whether its count is greater than N/2. If it is true, we consider it as the majority element.

class Solution { //   ONLY FOR MAJORITY MORE THAN [N/2] USE moore voting majority algorithm 
public:
    int majorityElement(vector<int>& nums) { // using MOORE VOTING ALGORTIHM
                                               //The Boyer-Moore voting algorithm is one of the popular optimal algorithms which is used to find the majority element among the given elements that have more than N/ 2 occurrences. This works perfectly fine for finding the majority element which takes 2 traversals over the given elements, which works in O(N) time complexity and O(1) space complexity.
        

        int c=0;
        int el=0;

        for( auto i:nums) // i is not indices but iterator wich point to element , or take it as a element
        {
            if(c==0)
            {
                el=i;
            }
            if(i==el)
            {
                c++;

            }
            else
            {
                c--;
            }

           
        }
         return el;
    }
};