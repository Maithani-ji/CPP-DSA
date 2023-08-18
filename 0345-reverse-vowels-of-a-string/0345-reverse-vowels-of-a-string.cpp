class Solution {
public:
   
    bool isvowel(char ch) {
    ch = tolower(ch); // Convert the character to lowercase to handle both uppercase and lowercase vowels
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;

        while(i<j)//using two pointer and check from front and back the vowels
        {
            if(!isvowel(s[i]))//if in front we dont get any vowel we move forward
            {
                i++;
            }
            if(!isvowel(s[j]))//if in back we dont get any vowel , we move backword
            {
                j--;
            }
            if(isvowel(s[i]) && isvowel(s[j]))//if at both both we got vowel , we swap and move i ++ and j --
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
        
    }
};