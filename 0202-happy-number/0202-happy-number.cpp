class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1)
        { 
            if(seen.count(n))
            {
                return false;
            }
            seen.insert(n);
        int num=n;
        int sum=0;
            while(num)
            {
                int d=num%10;
                sum+=d*d;
                num=num/10;

            }
            n=sum;


        }
        return n==1?true:false;
        
    }
};