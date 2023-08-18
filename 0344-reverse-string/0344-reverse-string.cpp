class Solution {
public:
    void reverseString(vector<char>& s) {// use two pointer , from start and end , and swap elements from start and end
        
        int i=0;
        int l=s.size()-1;
        while(i<=l)
        {
            swap(s[i],s[l]);
            i++;
            l--;
        }
        
    }
};