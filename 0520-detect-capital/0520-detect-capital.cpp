class Solution {
public:
    bool detectCapitalUse(string word) { // we have to check either all lower case or all upper case 
        int n= word.size();//storing size of string 
        int c=0;//storing count of upper char , if it is equal to size , then true
        int d=0; //storing count of all lower case char, if its all lower case and = n 
        for(auto s:word)//traversing each word 
        {
            if(isupper(s))//checking each char is upper or not 
            {
                c++;
            }
            if(islower(s))//checking each char is lower or not 
            {
                d++;
            }
        }
        if(c==n || d==n )//c == n || d==n , then same number of capital as size  or same no of small as size
        {
            return true ;
        }
        else if(isupper(word[0]) && d==n-1)// if first char is capital and other else are lower case return true 
        {
            return true;
        }
        else return false;// else false

    }
};