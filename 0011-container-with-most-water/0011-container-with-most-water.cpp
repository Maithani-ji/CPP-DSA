class Solution {
public:
    int maxArea(vector<int>& h) { // if used 2nest array to go through all the cases -- T-n^2  S-1
                                    //       USING 2 POINTERS T-n S-1
        int m=INT_MIN;
        int i=0;// using 1st pointer from starting pillar for breadth calculation
        int j=h.size()-1; // using 2nd pointer from last pillar for breadth calculation
        while(i<j) //traversing till i<j
        {
            int a= abs(i-j) * min(h[i],h[j]);//taking area - using indices diff as breadth & min(h[i],h[j]) as height - since water
            //                                can only be store till min height among two pillar
            m=max(a,m); // calculating all max area where water can be stored and storing max of them .
            (h[i]<h[j])?i++:j--;// updating only  small pillar value , since biggest pillar will be same for other area which might 
            // give large area value with more than small pillar and less than biggest pillar.
        }
        return m;
        
    }
};