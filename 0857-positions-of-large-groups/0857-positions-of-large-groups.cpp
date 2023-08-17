class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {

        if(s.size()<3)
        {
            return {};
        }


        int c=0;// using counter to count number of same alphabet
        int m=-1;//using to store start index od character
        int n=s.size();
        vector<vector<int>> ans;//array for storing ans
        for(int i=0;i<n;i++) // check of to i+1 thats why till n
        { 
            if(s[i]==s[i+1]) // if element next is same
            {  c++; // counter
                if(m<0)// if start of alphabet is not stored
                {
                    m=i; //start index of that alphabet
                }


            }
            else{  // if not same next element 
                if(c>=2)// (a,a,a) count 2
                {
                   
            ans.push_back({m,i});//push back the start and end pos of alphabet , end is when next elemtn is not same
            }
            c=0;m=-1;

            //MOT NEEDED

            // if(s[n-2]==s[n-1] && c>=2)// corner case , when (a,a,a) - loop n-1 running therefore check last 
            // //                                    and last second if count >=2
            // {  
            //     ans.push_back({m,n-1});
            // }
             
         }
        }
        return ans;

        
    }
};