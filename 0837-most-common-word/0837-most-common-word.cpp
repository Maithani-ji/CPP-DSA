class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {

        string ans; // storing for max frequent word in para apart from banned list word
        unordered_map<string,int> ban;//storing banner words in map
        unordered_map<string,int> wrd;//storing each word of para in map
        

        for(auto i : banned)//inputting value of banned vector to ban map
        {
            ban[i]++;
        }
         int max=0;//initialisng max frquency with 0



         for(int i=0;i<para.size();i++)//iterate over each character of para
         {
             string s;//storing each character in s till it become a word

             while(i<para.size() && isalpha(para[i]))//storing character in s till it got no space
             {
                 para[i]=tolower(para[i]);//storing character by turning them to lowr case
                 s+=para[i];  //          concatenating character to s string sto make it a word
                 i++; // moving forward with character index

             }

             if(!ban.count(s) && s!="")//check if the word s is not in ban map and not an empty word ""
             {
                 wrd[s]++;//if true then , add word s in wrd map and increse its frequency 
                 if(max<wrd[s])//check wrd[s] frequency if greater than max frequ
                 {
                     max=wrd[s];// sotre that word freq to max freq
                     ans=s;// store that word to ans string ,if same frequency found ,first same frequency element is the answere
                 }
             }
         }

        return ans;

        
    }
};  //                          MORE EASY TO WRITE -- USING STRINGSTREAM SS(STR)-which cnverts paragrpah to word by word using 
//                                               while(ss >> temp ) // like an iterator is string temp- which store words of para 

// class Solution {
// public:
//     string mostCommonWord(string str, vector<string>& banned) {
//         unordered_map<string,int> hash;
//         for(auto& it : str) it = ispunct(it) ? ' ' : tolower(it);

//         cout<<str<<endl;

//         unordered_set<string> st(banned.begin(), banned.end());  
//         string res, temp;      
//         int maxi =0;
//         stringstream ss(str);
//         while(ss >> temp) hash[temp]++;
        
//         for(auto& it:hash){
//             if(it.second > maxi && !st.count(it.first)){
//                 maxi = it.second;
//                 res = it.first;
//             }
//         }
//         return res;
//     }
// };