class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     sort(intervals.begin(),intervals.end()); // sorting all for better efficiency if not given sorted
        if(intervals.size()==0)// if size is 0 , return null
        {
            return {};
        }
        vector<vector<int>> mm; // storing the merged intervals

        vector<int> temp;//creating temp array to store meged elements,& check if other element lies in them or not   
        temp= intervals[0];//creating temp with first value of intervals

        for( auto it : intervals)// traversing in intervals
        {
                if(it[0] <= temp[1] )//checks current values first element with tems's last element, if its <= then it 
                //                   belong to that temp values
                {
                    temp[1]= max(temp[1],it[1]);// and max of both last element will become the upper bound of new  
                    //                             updated temp array values and again check upcoming values with its
                    //                             interval
                }
                else
                {
                    mm.push_back(temp);//else if not in between temp interval , ie its unique , push it to merged arr
                    temp=it;// and assign temp with new value
                }

        }
        mm.push_back(temp);// at last push temp , since at last it has some value , which is not pushed to merge arr
        //                     because of no further element to check 
        return mm;
        
        
    }
};