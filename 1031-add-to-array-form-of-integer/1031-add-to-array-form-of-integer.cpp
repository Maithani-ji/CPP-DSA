// class Solution {
// public:
//    vector<int> addToArrayForm(vector<int>& arr, int k) {
//         vector<int>ans; // using another array
//         int i=arr.size()-1;//start adding from back of the array
//         int carry=0;// to store carry remain after adddition
//        while(k>0 or i>=0){ //till i >=0 and k element adding is finished 
//            int sum=carry; // store carry in sum
//            if(i>=0)sum+=arr[i--]; // adding sum with arr[i] and decreasing i--
//            sum+=k%10; // adding k's value from back
//            carry=sum/10;//storing carry for upcoming addition
//            k/=10;//reducing k by removing back number ,after adding its back number to sum
//            ans.push_back(sum%10);// adding the non carry sum to ans array
//        }
//        if(carry)ans.push_back(carry);//if after all the adddition any carry left , push back it in the array
//        reverse(ans.begin(),ans.end());//as we are push backing it in ans array , we have to reverse it.
//         return ans;
//     }
// };

  // below is more optimal

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        int c=0;
        int i;
        for(i=n-1;i>=0 or k>0;i--){ // till i >=0 and k element adding is finished
            int r=k%10; // // adding k's value from back
            k/=10;//reducing k by removing back number ,after adding its back number to sum
            if(i>=0){// given number is larger than k
                int res=num[i]+r+c;//addd the carry , k -back element,and nums[i] to result variable;
                num[i]=res%10;// store res%10 to nums[i] iie number greater than 9 after additon
                c=res/10; // store carry from res 
            }
            else{// if num array is smaller than k element
                int res=r+c;//add remaining k digit and carry left from above to res variable
                num.insert(num.begin(),res%10); // and insert that res to brgin of num
                c=res/10;//storing carry if res left is larger than 9 for more remaining k
            }

        }
        if(c>0){
            num.insert(num.begin(),c); // at last if any carry left ,insert in beginning of nums
        }
        return num;
    }
};
