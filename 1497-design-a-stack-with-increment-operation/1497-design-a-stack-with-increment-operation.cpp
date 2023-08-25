class CustomStack {
    int s;
    int target;
    vector<int>ans;
public:
    CustomStack(int maxSize) {
        target=maxSize;
        s=0;
    }
    
    void push(int x) {
        if(s<target)
        {
            s++;
        ans.push_back(x);
        }
    }
    
    int pop() {
         if (s == 0) {
            return -1; // Handle empty stack
        }
        int x=ans.back();
        ans.pop_back();
        s--;
        return x;
    }
    
    void increment(int k, int val) {
        // if(k>s){
        //     int i=0;
        // while(i<=s)
        // {
        //     ans[i]+=val;
        //     i++;
        // }
        // }
        // else{
        //  int i=0;
        // while(i<k)
        // {
        //     ans[i]+=val;
        //     i++;
        // }
        //                or

          int limit = min(k, s); // Limit the increment range
        for (int i = 0; i < limit; i++) {
            ans[i] += val;
        }
        }
    
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */