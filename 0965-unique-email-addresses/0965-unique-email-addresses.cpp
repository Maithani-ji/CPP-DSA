class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
            unordered_set<string> x;
        for(auto s:emails)// for string in a string array
        {
            string ss;// for storing string after operations , 
            for(auto c:s)// for characters in a particular string
            {
                if(c=='+'|| c== '@')//if +, after this no character till @ should be taken 
                {
                    break;//therefore break when + or @ comes.
                }
                if(c=='.')// if . then this'.' should be ignored
                {
                    continue;//therrfore we will not add it in the temporary string
                }
                ss+=c;//add remaining  character apart from . and + to temp string till @
            }
            ss+= s.substr(s.find('@'),s.size());//after storing unique local name , add it to the domain name. 
            x.insert(ss);//insert it in the set , to get unique elements
        }
        return x.size();
        
    }
};