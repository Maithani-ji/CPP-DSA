

// // USING TWO POINTERSv   // correct but giving tle for working test case


// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {

//         int count=0;

//         for(const string& word:words)// using two pointer
//         {
//             int i=0;// i pointer for string s
//             int j=0;// j pointer for word of words

//             while(i<s.size() && j <word.size())//we traverse s and word till both are true for traversing
//             {
//                 if(word[j]==s[i])//if we found matching in both s and word
//                 {
//                     j++;//we move forward in word to find for char to be matched
//                 }
//                 i++;// if not found then just increment on string character to find matching with word char
//             }
//             if(j==word.size())// at last if j is end , ie all word character found and j pointer crossed the last element
//             {
//                 count++;// then we found the word
//             }
//         }
//         return count;
        
//     }
// };

class Solution { //T-n+m*klogn  S-n+m*k   -------  without using mapping 
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        

        vector<vector <int>> chari(26);

        for(int i=0;i<s.size();i++)
        {
            chari[s[i]-'a'].push_back(i);
        }

        
        int count=0;
       

        for(int i=0;i<words.size();i++)
        {
                bool flag=true;
                 int lasti=-1;
                 for(auto it : words[i])
                 {
                     auto i=upper_bound(chari[it-'a'].begin(),chari[it-'a'].end(),lasti);

                     if(i==chari[it-'a'].end())
                     {
                         flag = false;
                         break;
                     }
                     else
                     {
                         lasti=*i;
                     }
                 }

                if(flag)
                {
                    count++;
                }
        }
        return count;
    }
};