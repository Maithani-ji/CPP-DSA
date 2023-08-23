class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sa) {

        queue<int>st;
        queue<int>qu;
        bool flag=false;
        for(auto c: s)
        {
            st.push(c);
        }
        for(auto c:sa)
        {
            qu.push(c);
        }
        int count=0;
        while(!flag)
        {
            if(qu.empty())
            {
                return 0;
            }
            if(qu.front()==st.front())
            {
                st.pop();
                qu.pop();
                count=0;
            }
            else
            {
                int x=st.front();
                st.pop();
                st.push(x);
                count++;
                if(count==qu.size())
                {
                    flag=true;
                }
            }
        }
        return qu.size();
        
    }
};