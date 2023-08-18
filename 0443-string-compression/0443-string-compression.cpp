class Solution { // using TWO pointers
public:
    int compress(vector<char>& cha) { 

        int i=0;//1st pointer gets 2nd pointer's previous value and count of that value
        int count=1;
        for(int j=1;j<=cha.size();j++)//2nd pointer // traverse the array , to check previous element is same or not
        {
            if(j==cha.size() || cha[j]!=cha[j-1])//if at last j or previous element is not same
            {
                cha[i]=cha[j-1];// replace char at i with j-1 when j founds differenet char at its j-1 posn
                i++;// increment i for storing char's count 
            
            if(count>=2)//as mentioned in quetion , that count of char should be > than 1 , if to be merged
            {
                for(auto k : to_string(count))// traverse in string (count) since count have to be appended at ith
                //                              position after its char , and count is iterated because can be >9,10,11
                {
                    cha[i]= k;// insert count digits to ith posn
                    i++;// and increment i for next char checking and its count 
                }
           
            } 
           count =0;// after a char with its count is appended , reinitialise count to 0
            }
            
            
                count ++;//  till j!=j-1  , keep incrementing count 
            
            
        }
        return i;// i will be at the position where new array will end after appending char with count
        
    }
};