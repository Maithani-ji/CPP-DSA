class Solution {
public:
    int countBinarySubstrings(string s) {
        //USING 2  pointer APPROACH
        int curr=1;// curr for current block having same previous elemnts , change when new element is found
        int prev=0;// prev for storing current block after founding another block
        int sum=0;//storing min of prev and current block , which gives no of substring can be made with that block
        for(int i=1;i<s.size();i++)//starting from 1 because , we know current block will have 1 ,since 1st elemnt is always a block
        {
            if(s[i]==s[i-1])//if previous elemtent matches then it is a part of block
            {
                curr++;// increment current , ie no of element in the block 
            }
            else// if not matches
            {
                sum+=min(curr,prev);//then min of curr and previous will give number of substring can be made with that block
                prev=curr;// then moving to new block , previous gets current value,
                curr=1; //and  current restarts from 1
            }
        }
        sum+=min(curr,prev); // using this again because // when the loop ends , it end with condition , not with previous value not 
                            // same, thats why , curr and previous have the value from last block and need to be added in sum .

        return sum;
    }
};