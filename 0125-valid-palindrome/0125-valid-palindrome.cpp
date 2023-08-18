class Solution {
public:
    bool isPalindrome(string s) {

      

     int i=0; int e= s.size()-1;
     while(i<=e)//traversing using front and back using two pointer approach 
     {
        if(!isalnum(s[i])){ i++; continue;}// if from start any non alpha char , we skip indices +1 and continue
        if(!isalnum(s[e])) {e--; continue;}//if from last any non alpha char we skip the indices -1 and continue 
        if(tolower(s[i])!=tolower(s[e])) return false;//if any of the start and last not match return false
         else { i++; e--; }//else move farward with checking 
     }
            return true;//at last when loop ends and all character passes the loop ,return true.

    }
        
    
};