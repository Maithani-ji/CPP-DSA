class Solution {
public:
    int maximumSwap(int num) {
        string s= to_string(num);//for general case // storing number to string
        vector<int>v(10,0);//creating vector of digit size

        for(int i=0;i<s.size();i++) v[s[i]-'0']=i; // traversing string, using string digits as indices of v vector and 
        //     those string digits indices as value.
        

        for(int i=0;i<s.size();i++)//traversing in string
        {
            for(int j=9;j>s[i]-'0';j--)//and checking each digit indices with vector v digits ie indices from back ie max to min , till when vector indices > s[i] digit 
            {
                if(v[j]>i)//if string digit indices < v digit(indices), that means string digit is a smaller no and 
                // greater no is found ahead of smaller no indices  and should 
                //      be swapped with the number at v[j[i]] number  
                {
                    swap(s[i],s[v[j]]);
                    return stoi(s);
                }
            }
            
        }
        return num;

    }
     
    
};