class Solution {
public:
    int lengthOfLastWord(string s) {
        
       
   
    int c=0; //storing length of last word
    for (int i=s.size()-1;i>=0;i--) // iterating from 1st which is last 
    {
        if(s[i]==' ')//if char is space
        {  
            if(c==0) continue; // and count is not initiated ie starting space before word , continue to move forward till we got word
            else break;//else if got word and next char is space , break , we found the word
        }
        else
        c++;//counting of words length 

    }
    return c;
        
    }
};