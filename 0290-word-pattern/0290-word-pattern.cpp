#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map<std::string, char> mp;
        std::istringstream iss(s);
        std::string word;
        int i = 0;
        int cn = 0;

        while (iss >> word) {
            cn++;
        }

        if (cn != pattern.size()) {
            return false;
        }

        // Reset the stringstream to its beginning
        iss.clear();
        iss.seekg(0);
        int arr[26]={0};
        while (iss >> word) {
            if (mp.find(word) == mp.end()) {
             if(arr[pattern[i]-'a']!=0)
             {
                 return false;
             }
             else{
                mp[word] = pattern[i];
                arr[pattern[i]-'a']=1;
                i++;}
            } else {
                if (mp[word] != pattern[i]) {
                    return false;
                }
                i++;
            }
        }

        return true; // Ensure both pattern and string are fully processed
    }
};
