class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        int max = INT_MIN; // for storing the max of the array or mountain top
         
        int mountain = -1;// storing max index
        for(int i=0;i<arr.size();i++){ // max element and its indices found
            if(arr[i]>max){
                max=arr[i];
                mountain =i;
            }
        }
        if(mountain==0 || mountain==arr.size()-1) return false;//if max found at 0 or arr.size()-1 - > not a mountain

            for(int i=0; i<mountain; i++){// check from 0 to mountain - if i th val >= than i+1 th , not a mountain
                if(arr[i]>=arr[i+1]){
                    return false;
                }
            }
            for(int j=mountain+1; j<arr.size(); j++){//check from mountain to size-1 if ith val >= i-1th , not a mountain
                if(arr[j]>=arr[j-1]){
                    return false;
            }
        }
        return true;
    }
};