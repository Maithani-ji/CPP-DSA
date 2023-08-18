// class Solution {
// public:
//     int countSegments(string s) {   T-n S-n+k since using stringstream

//         stringstream ss(s);//using string stream for extracting word from sentence
//         int c=0;//initializing counter for coutning words in a sentence
//         string word;//using temporary word to store words of a string 
//         while(ss>>word)//ss gives words to word one by one
//         {
//             c++;//whenever a word gets in increase the counter 

//         }
//         return c;       //return c 
//     }
// };
   //OPTIMISED
class Solution { //            T-n S-1
public:
    int countSegments(string s){
        int count = 0, n = s.length();
        if(n==1 && s[0]!=' ')   return 1;    //if size is one return one if that one is not space 
        for(int i = 1; i < n; i++){ // traverse array 
            if((s[i]==' ' && s[i-1]!=' ') || (i==n-1 && s[i]!=' ')) // if s[i] is space its previous should be a character and last 
            //                                                         index should be a char not a space to get count ++,
                count++;
        }
        return count;
    }
};