class Solution {
public:
    int minFlipsMonoIncr(string s) {//we using greedy approach to , find local optimum solution , ie at each iteration we check if it is easy to flip 1 or zero to make it monotnically increasing , for more understanding read the code

        int flip0=0;// we use flip0 to flip 0 after we get one , to make it inc monotnic
        int count1=0;// we keep the count of ones too , ie==> if 1's are less than the number of 0 we flipped , so we only flip 1 to make it 0 , like 0011000 -> in this we find 1's less than 3 0's to make it inc monotonic , thats why we just flip 1's which are less 

        for(auto c: s)//we iterate the string 
        {
            if(c=='1')// we check if we get one, we keep the count of number of ones we get
            {
               count1++;
            }

           else {// if we get 0 , we check ,  which is min , number of ones we got till now or the number of zeroes we have flipped
                flip0 = min(flip0+1, count1);//if 1's < o's flipped , we change the flip0 to flip1 ,ie we flipped 1's and not 0
            }
        }
        return flip0;
        
    }
};