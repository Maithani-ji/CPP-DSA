class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

       unordered_map<int ,int>mp; // using map to store values with frequency

        for(auto i: deck)
        {
            mp[i]++;//..storing in map value and count
        }

        int a=0;
        for(auto i : mp)//to make a valid grouping , we have to find the GCD OR HCF of all frequency 
        { //            which gives smallest number divisible by all ,we can make grouping of element using that no.
        //              except 1 .
            a= gcd(a,i.second); // automatic gcd fumction in c++ else see the comment to get the gcd of an element

        }
        if(a>1)//gcd of all the frequencie shoul be greater than 1 , else if 1, no grouping of element is allowed.
        {return true;}
        else
        {
            return false;
        }}
    // int gcd(int a , int b)
    // {
    //     if(a%b==0)
    //     {
    //         return b;
    //     }
    //     else 
    //    return  gcd{b,a%b};
    // }
};