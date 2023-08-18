class Solution {
public:
    int findLUSlength(string a, string b) {
       
       if(a==b)//find longest UN COMMON subsequence , so if both elements are same then , no uncommon subsequence ,so return -1
       {
           return -1;
       }
       return max(a.size(),b.size());//if both are diffferent then return the lentgh of the biggest length string.
       
    }
};