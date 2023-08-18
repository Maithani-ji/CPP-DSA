class Solution {
public:
    string reverseStr(string s, int k) {

       
        
        for(int i=0;i<s.size();i+=2*k)// takes 2*k times a jump 
        { // check at i , if there is even k elemtn from i which can be reverse 
            if(i+k<=s.size()){//after 2k jump of i,i+k<=n ie from i , there are 2 element which can reverse,reverse from 2k to 2k+k 
            
              reverse(s.begin()+i,s.begin()+i+k);// it can give answere for less than 2k lenth of string too. but greater than k size.
            
            }
            
            else  reverse(s.begin()+i,s.end()); // if size of string is < k, then reverse whole string -- written in question


        }

        return s;
        
    }
};