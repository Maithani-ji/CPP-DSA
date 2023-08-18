class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        if(co.size()==2)
        {
            return true;
        }
        int x=co[1][0]-co[0][0];//storing first x2-x1
        int y=co[1][1]-co[0][1];//storing first y2-y1
        for(int i=1;i<co.size()-1;i++)//starting from 1 since we preivously used 2 elements for slope using next 2 ie from 1 index
        { // y2-y1(ie y)/x2-x1(ie x)= y3-y2/x3-x2  -> y*(x3-x2)=x*(y3-y2) ===> since checking slope can give 0 and cause runtime err
          
            if(x*(co[i+1][1]-co[i][1]) != y*(co[i+1][0]-co[i][0]) )// check the slope of 1st two and next traversing two 
            {
                return false;
            }
        }
        return true;
    }
};