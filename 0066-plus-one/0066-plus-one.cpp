class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {
        
        int n=dig.size(); 
        for(int i=n-1;i>=0;i--)
        {
            if(dig[i]!=9)  //if last element is not 9 simply increment 1 and stop
            {
                dig[i]++;
                break;
            }
            else
            {               //if 9 then simply put 0 because 9+1=10 which 1 gets carry
                dig[i]=0;
            }
        }
        if(dig[0]==0)       //if all given 9 in an array then simply check first element ,if after increment its 0
        {                       
            reverse(dig.begin(),dig.end());
            dig.push_back(1); //// reverse and push back 1 to end 
             reverse(dig.begin(),dig.end());  //and then reverse again to make the atray original

        }
        return dig;
    }
};