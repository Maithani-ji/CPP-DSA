class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        if(nums.size()==0)
        {
            return 0;
        }

        unordered_map<int , int> c,s,e; // map of count , start indx and end indx of AN ELEMENT. To calculate max frequency of element or elements and min subarray of those elements start and end.
        
        int m=0; // storing max frequency of an element
        for(int i=0;i<nums.size();i++)
        {
            if(c[nums[i]]==0) // if element occuring first time 
            {
                s[nums[i]]=i; // start same indx
                e[nums[i]]=i; // end same indx
            }
            else // if occured more than 1 time
            {
                e[nums[i]]=i; // just change the ending indx
            }

            c[nums[i]]++; // and increase every elemtns count

            m=max(m,c[nums[i]]);// also taking max of an elemtns frequency among frequencies of elements

        }

                int mi=INT_MAX;// for storing max frequencies element's min subbarray length
        for(auto i : c) // using iterator to iterate element of count map
        {

                if(i.second==m)//if iterator second sub element get matched with max frequency
                { 
                    mi=min(mi,e[i.first]-s[i.first]+1); // store min lentgh of matched element among matched elements
                                                    // using end - size +1 , because subarray must include the max 
                                                    //frequency number
                }


        }
        return mi;

    }
};