class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
                // in ques given last element should be 0 ,2 ways to go to last either skipping two bits or skip 1 bits 
        int i=0;
        while(i<bits.size()-1) // initialise iwith 0 and go till n-1 
        {
            i= (bits[i]==1)? i+2 : i+1; // if ith val is 1 move 2 skip else skip 1 
        }
        return i==bits.size()-1; // if i moves till size and not beyond that , then last character is one bit ie 0 0. not 1 0 , if it has been 1 0 then due to 1 , it gone past the bits size .
        
    }
};