class MyCalendar {
public: 
    map<int ,int> m;// using map instead of unordered map , to store elements in sorted , which is efficienct fro cheking overlapping time.
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {//using concept of getting interval as 0, by giving start 1 and end -1, if any thing comes in between 1 interval , the sum will get more than 1 ex 10-20 : 1,-1, 15-30 -:1,-1-> 10,15,20,30- 1+1,-1-1 >1
        m[start]++;//initialising all start as 1
        m[end]--;//initialising all end as -1
        int sum=0;//storing their sum
        for(auto it :m)//
        {
            sum+=it.second;//summing the sorted element in map with start and end , with their respective 1 and -1
            if(sum>1)//if we get sum>1 then we found interval which overlapse
            {
                m[start]--;//reset  the start 1 and end -1
                m[end]++;
                return false;
            }
        }
        return true;



        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
