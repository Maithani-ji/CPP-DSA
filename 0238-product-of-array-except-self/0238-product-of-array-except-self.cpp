class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) { // using two vectors 1st store all element;s left multiplied value 
    //                                                    except self
    // 2nd to store all element's right multiplied value 
    //                                                    except self
          int n = nums.size();
        vector<int> l(n);
        vector<int> r(n);
        l[0] = 1;//initialising left start value as 1 , since 1st value has no left value
        r[n-1] = 1;//initialising right end value as 1 since last value has no right value

        for (int i = 1; i < n; i++) {// using previous product of left  * number present at that previous index in nums
            l[i] = nums[i-1] * l[i-1];// since at that indices left contains prod of previous no's except self
        }
        for (int i = n-2; i >= 0; i--) {//using forward product of right * number present at that forward indices in nums
            r[i] = r[i+1] * nums[i+1];// since at that indices right contains prod of forwards no's except self
        }

        vector<int> ans;// just multilying left and right vector elements to get ans element
        for (int i = 0; i < n; i++) {
            ans.push_back(l[i] * r[i]);
        }

        return ans;
    }       
    
};