class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        int n= dom.size();//storing dom size
        
    //     for(int i=0;i<n;i++)//sorting values within arrays for smoother process
    //     {
    //         sort(dom[i].begin(),dom[i].end());
    //     }
    //     int c=0;//coutning pair variable
    //     map<vector<int>,int>m;//making map of array and int value

    //     for(int i=0;i<n;i++)//inserting array with their frequency in map
    //     {
    //         m[dom[i]]++;
    //     }

    //     for(auto i:m)//searching map for freq of element if found return how much pair it can make using formula-n*n-1/2
    //     {
    //         if(m.count(i.first))//if found any count ... count can be used as, count(arr.begin(),arr.end(),2)->find freq of 2 in arr.
    //         {
    //             c+=((i.second)*(i.second-1))/2;// use formula n*m-1/2 for no of pair it can make 
    //         }
    //     }
    //     return c;
    // 
        //                  using same approach for just 2 element in array , above is general approach 
     map<pair<int,int>,int> seen;
        int result = 0;
        for(auto& v:dom){//traversing array
            if(v[0] > v[1]){ // checkin g and generally swapping all element to make 1st one bigger than other
                swap(v[0], v[1]);
            }
            seen[make_pair(v[0],v[1])]++;//making pair of element with theri frequency
        }
        for(auto& [key, value] : seen){ // traversing , map and using frequency formula to add pairs of those frequencies to result
            result += value*(value-1)/2;
        }
        return result;


     }
};