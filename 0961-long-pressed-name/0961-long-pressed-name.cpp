class Solution {
public:
    bool isLongPressedName(string na, string ty) {

        int i=0;
        int j=0;
        int n = ty.size();
        
        while(j!=n)//using two pointer , one in na and other in ty from 0 
        {
            if(i<na.size() && na[i]==ty[j])//if both char matches , then we move forward ie na and ty
            {
                i++;
            }
            else if( j==0 || ty[j]!=ty[j-1])//if not matche ,then check 2nd pointer , if curr value is ! = previous value or 2nd pointer is not matched at its 0th index , then no , not a long pressed name
             {return false;}           
            j++;// if 2nd pointer contains long press name  ie elseif not works , then move forward till it matches with 1st pointer , and 1st pointer < its name size

            

        }
        return i==na.size(); //if 1st pointer gets matches till last size of name , then true
        
    }
};