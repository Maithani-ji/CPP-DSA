class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        string aa=a; //store a in some variable to get added as orginal a not concatenated a
        int c=1;//count initialise as 1 because a is already initalise, we have to just repeat it to get substring as b
       int n= b.size()/a.size();// for how much repeatition we use b lentgh / a length ie 8 / 4 - 2 times to repeat a
       //                          to get b and +2 if half a in front or half a in end or in both front and back found
       for(int i=0;i<n+2;i++)// we use n+2 because we taking the posibility of having a's half in front and back too
       {
           if(a.find(b)!= string::npos)// if b is found as  a substring , then we break and print count , ie times a 
           //                             repeated
           {
               return c;
           }
         else{  // if b not found a's substring , add a to a as aa , to increase its size
             a+=aa;
           c++;} // and increaase count while repeating a
       }
       return -1;//else if not found return -1 
        
    }
};