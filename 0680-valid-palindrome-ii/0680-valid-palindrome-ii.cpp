class Solution {
public:
            bool isp(string s, int i, int j)// function check i+1 to j and  i to j-1, since one value deletion(skip) is okay 
            {
                while(i<j) //check palindrom after 1 skip
                {
                    if(s[i]==s[j]){
                    i++;
                    j--;
                    
                    
                    }
                    else return false; // if found unmatched char then return false, since only 1 skip is allowed
                }
                return true; //else return true
            }


    bool validPalindrome(string s) { // normal palndrome check function
      
      
       int i=0;
       int j=s.size()-1;
       
       while(i<j)//using two pointer approach
       {
           if(s[i]!=s[j])// if found no matching character from back and front, either its from back or from its front, one deletion 

           //              is allowed

           { return isp(s,i+1,j) || isp(s,i,j-1);// so we start moving from front ++ and with same back or we start moving //                                            from back-- and  with same front  
                                 }
       
       else // if its a normal pallindrome 
       {
           i++;
           j--;
       }
       }
       return true;
      

        
    }
};