class Solution {
public:
    string addBinary(string a, string b) {
        string s=""; //creating string variable to store element after addition
        int al=a.size()-1;//string a size
        int bl=b.size()-1;//string b size
        int c=0;//carry 
        
        while(al>=0 || bl>=0 ||c!=0)//if a>b or a>b or a&b both end and still carry left --> do the add operation
        {
                int sum=0;// local sum var
               if(al>=0){//if string a is not completed
                sum+= a[al--] -'0';}//       ****  can use " stoi()" but -'0' is efficient to convert char to int *****
                if(bl>=0){//if string b is not completed
                 sum+= b[bl--] -'0';}

                 sum+=c;//after sum using %2 to get ans in 1 or 0.. max value 2 so remainder 0 or 1
                 s+=sum%2 + '0';// convert int to char " ie +'0' " or can use ' to_string()'
                
                
                c=sum/2;// storing carry using /2 which gives qoutient as max value can be 2 so, 2/2=1 or 0
            

        }
        reverse(s.begin(),s.end());//reverse string as it above operation storing in opposite manner.
        return s;
        
    }
};