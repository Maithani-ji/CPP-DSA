class Solution {
public:
    string reverseOnlyLetters(string s) { // using two pointer 

        int j=s.size()-1;//first pointer 
        int i=0;//using 2nd pointer

        while(i<=j) // since i <=j 
        {
            if(isalpha(s[i])){  //if s[i] is alphabet

            if(isalpha(s[j])) // true , then if s[j] is alphabet
            {
                swap(s[i],s[j]); //swap both the items
                i++; //increment i
                j--;//decreement j

            }
            else{
            j--;}}//if s[j] is not alphabet then decremetn j
            else{i++;}//if s[i] not alphabet increment i


        }
        return s;
        
    }
};