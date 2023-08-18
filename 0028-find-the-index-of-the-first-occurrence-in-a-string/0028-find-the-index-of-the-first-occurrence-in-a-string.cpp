// class Solution {             //  USING INBUILT FUNCTION find() 
// public:
//     int strStr(string s2, string s1) {
//         return s2.find(s1) != string::npos ? s2.find(s1) : -1;
//     }
// };

class Solution {
public:
    int strStr(string hay, string need) {//use two pointer approach
        int i = 0;
        int n = hay.size();
        int j = 0;
        int nn = need.size();

        while (i != n) {//1st pointer traverse haystack array
            if (j != nn && hay[i] == need[j]) {//second pointer check with 1st pointer while traversing in needle array
                i++;//   if both matches ie from 2nd pointer starting , and keep matching till needle size, then return i-j
                j++;//    it will give strting of that needle string in haystack
            } else {
                i=i-j+1;//else if not matches after any character , move back till there , where u started searching ,and 
                //         from + 1 index
                j = 0;// if not matches j will start from oth index of needle
               
            }

            if (j == nn) {//if j==nn , that is found 
                return i - j; // return starting point of it , without going forward
            }
        }
        return -1;
    }
};
