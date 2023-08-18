class Solution {
public:
    bool canConstruct(string r, string m) {

        int arr[26]= {0};//creating constant space for storing character frequency for magzine , like hash map but constant space


        for(auto c : m)//storing magizine char freq 
        {
            arr[c-'a']++;
        }
        for(auto c: r)// remvoing those char , whenevr we find those char in ransom note
        {
            if(arr[c-'a'] >0){// if on matching its >0 ie matched char of ransome note has frequency in mag
            arr[c-'a']--;}// then remvove char freq -- which matched
            else return false; // else return false if matched char freq <0 ie not present in magizine
        }

       return true;
    }
};