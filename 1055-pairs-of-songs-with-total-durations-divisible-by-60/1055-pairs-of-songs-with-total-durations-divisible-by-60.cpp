// class Solution {// approach is correct and OPTIMAL - giving run time due to integer overflow ,,correct it later 
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {

//         unordered_map<int,int>m;//using map to store values with frequency 
//         for(int i=0;i<time.size();++i)
//         {
//             time[i]=time[i]%60; // storing value pre % with 60 - to make the finding easier using 60-value -if 
//             //                  present then divisible by 60 , hence pair can be made
//             m[time[i]]++;    // storing moded value with frequency
//         }
//         int64_t c=0;// counting pair

//         for(auto i:m)
//         {
//             if(i.first==0 or i.first==30 ){// special case for 0 and 30 ,if 0 means there were value direct % by 60 
//             // therefore they can made a pair if >1 freq.. if 30 then number of 30 can be /ble by 60 so they can 
//             // make their own pair >1 freq
//                  c+=((i.second-1)*(i.second))/2; // formula for self pair -> n(n-1)/2
                    
//             }
//             else if(i.first<30 and m.count(60-i.first))//using less than 30 , to reduce duplicacy like 20 -2, 40-1
//                 // first for 20 it will give 2 pair and again for 40 it will give 2 pair which total to 4 ie wrong 
//                 // ,since we already got their number of pair from 20 using 20 freq 2 and (60-20)40's 1 ie 2*1
//                 // therefore we will go only till < 30 since 0 and 30 are special case  -- after 30 it will duplicate
//                 // using less than 30 numbers like 40 will find 60-40 ie 20 which already done.
//                 {
//                     c+= (m[i.first])*(m[60-i.first]);// till less than 30 .for val n and for 60-val n -> n*n 
//                 }
            
            
//         }
//           return  (c);
        
//     }
// };

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, long long> m;
        for(int i : time) m[i % 60]++;

        long long ans = 0, i = 1, j = 59;
        if(m[0] > 1) ans += (m[0] * (m[0] - 1)) / 2;
        if(m[30] > 1) ans += (m[30] * (m[30] - 1)) / 2;
        while(i < j) {
            if(m[i] && m[j]) ans += m[i] * m[j];
            i++, j--;
        }
        return ans;
    }
};
