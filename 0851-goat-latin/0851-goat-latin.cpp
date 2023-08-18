class Solution {
public:
    string toGoatLatin(string sentence) {

        unordered_set<char> c{'a','e','i','o','u','A','E','I','O','U'};//storing vowels in set , to not use if else 

        stringstream ss(sentence);//using stringstream ss(string) --> for tokenizing words from sentence
        string ans, suff, s;

        while(ss>>s)//traversing thorugh each word
        {
            suff+='a';//sufffix keep incrementing or concatenating on each iteration 
            if(!c.count(s[0]))//if its not a vowel , then do consonent condition 
            {
                s=s.substr(1)+s[0];// remove 1st character of word to last --> using substring
            }
            ans+= s+ "ma"+ suff + ' ';// add ma  and suffix to last as told in condtion
        }
        
        ans.pop_back();//removing last space
        return ans;
        
    }
};