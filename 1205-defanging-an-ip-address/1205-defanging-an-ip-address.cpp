class Solution {
public:
    string defangIPaddr(string address) {

        char c='.';//storing c to find it in address
        string s = "[.]";//stroing s to replace it with c

        int l = s.size();//storing size to use it while traversing and finding c
        int lc=1;// storing size of c 

        int i=0;//starting from index 0
        while((i=address.find(c,i))!=-1)//finding first occurence of c from i and storing that occured c indices to i
        {   //                          used -1 , to end the while , since find gives value 0-n, on false gives -1 
            address.replace(i,lc,s);// on ith index , we have to replace c character , ie replace lc character from i th index by "s"
            i+=l;//then after replacing ,increase the traversing positon to + l , for next occurence of c in string.

        }
       
        return address;
        
    }
};