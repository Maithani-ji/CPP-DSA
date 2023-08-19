class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {//max no of partition/splitting of array from between to make the partition which later to be sorted and after concatenatng the sorted partition  , the concatenated should be a sorted original array , mean we have to make max meaningful partition , which after concatenating gives sorted array.

        int mx=0;//we use chaining method , ie using value of array as indx it covers, ie that value covers how many index.
        int count =0;// we chose the max value , which shows max number of indices it covers.

        for(int i=0 ; i<arr.size();i++)//we traverse in arrray
        {
            mx=max(arr[i],mx);//we store max value , which shows the index it covers ex 4321, 4 is the max , hence it covers
            //                   all 4 indexes , thus count is 1 and partition to be sorted is one

            if(i==mx)//ex 10234, when i will be equal to max , it will increase the count , ie 1 is max and it cover 0 value
            //         thus at 0 value count will increment , then at 2 and 3 and 4 , since among them ,they only cover
            //         themselves and not forward values as index  like value 1 , hence count will get increment to 4.
            {
                count++;

            }

        }
        return count;
        
    }
};