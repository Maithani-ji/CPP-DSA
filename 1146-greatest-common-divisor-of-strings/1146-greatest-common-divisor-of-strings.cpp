class Solution {
public:
    string gcdOfStrings(string str1, string str2) {// since both string is repeatition of gcd string ie AB - ABABAB , ABAB
                                                     
                                                     
                                                    
        
        
        
        if(str1+str2==str2+str1)// if both string on adding is same then gcd can be taken out
        {
            return str1.substr(0,gcd(str1.size(),str2.size()));//using gcd math function on both string's size, give gcd number, 
        }//                                                    then use it on in one string's substring from 0 to gcd , since gcd
        //                                                     element repeat itself to form both string will give gcd string using 
        //                                                     substr(0,gcd);
        else return "";// if not same then no gcd 
    }
};