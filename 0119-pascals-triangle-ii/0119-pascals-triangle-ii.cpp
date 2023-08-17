class Solution {
public:
    vector<int> getRow(int rowIndex) { //GENERATE a pascal triangle's a given ROW elements
        
        int n=rowIndex+1; //given indices , add +1 to make it length
        vector<int> x; //initialise a vector
        int ans=1; // initialize ans with 1 as it is constant for any row
        x.push_back(ans); // push 1 at first element

        for(int i=1;i<n;i++) //going form 1 indices to last n-1
        {                      // formula for generating a row's pascal triangle 'column'-> 
                                //  ans=ans*(row(n)-column(i))/column(i)-> using nCr 
            ans=(int)((long)ans * (n-i)/i); // 1st type cast it in LONG cause of * and / and then retypecast it 
                                                      //into INT
            
            x.push_back(ans); //inserting ans to array
        }
        
        return x;
    }
};