class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector <string> v={".-","-...","-.-.","-..",".","..-.",//using array of morse codes to map it with the characters in string
        "--.","....","..",".---","-.-",".-..","--","-.","---",
        ".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
        "-.--","--.."};
        unordered_map <string,int> my;//using map to map morse code string with theri frequency
       
        for(int i=0;i<words.size();i++){//going through all the words in an array of string
             string s;// to make morse code string 
            for(int j=0;j<words[i].length();j++){ // going through word by traversing character by character
                s+=v[words[i][j]-'a'];//adding morse code mapped with particular character to s , by using above v vector 
                //                    [words[i][j]-'a' using this will give the index of that character's morse code in v
            }
            my[s]=1;//adding whole string of morse code to map with their frequecny, and forcefully mapping freq with 1 , 
            //       since no repeatition is allowed , and map wont store same morse code string as key ,repeatitively.
            
        }
      return my.size();//returning unique no of morse code in the string.
    }
};