class Solution {
public:
    bool checkRecord(string s) {
        
        int aa=0;
        int ll=0; 
         int cc=0;    
        char a='A';
        for(int i=0; i<s.size();i++) // traversing string and checking equality with L and A OR wit char variable storing 'A'.
        {
          
            if(s[i]==a)// we can use char var to check string element
            {   
                ll=0;//if not 3 consecutive late then , ll resets to 0
                aa++;
            }
            if(s[i]=='L')//or we can direct check with character we want to check
            {
                ll++;//incrementing late .
                if(ll>=3)// if consecutive 3 lates then increment cc to know that yes , three consecutive late is there in string 
                {
                    cc=1;
                }
                
            }
            else{         // if only PLPLPLPL is there no absent then we have to counter ll to 0 
                    ll=0;
                }



        }
        if(aa<2 && cc<1)
        {
            return true;
        }
        else return false;
    }
};