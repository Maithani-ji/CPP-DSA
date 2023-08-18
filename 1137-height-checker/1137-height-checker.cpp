class Solution {
public:
    int heightChecker(vector<int>& height) {

        vector<int> ex(height.begin(),height.end());//using  another array 
        int c=0;
        sort(ex.begin(),ex.end()); //sort other array
        for(int i=0;i<height.size();i++)//compare original and sorted array , and elements which dont match , increase the counter
        {
                if(height[i]!=ex[i])
                {
                    c++;
                }
        }
        return c;
        
    }
};