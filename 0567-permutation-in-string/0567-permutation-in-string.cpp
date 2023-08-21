// class Solution { gives tle 
// public:
//     bool checkInclusion(string s1, string s2) {
//         vector<int> freq(26, 0); // Frequency array for characters
        
//         // Calculate frequency of characters in s1
//         for (char c : s1) {
//             freq[c - 'a']++;
//         }
        
//         int windowSize = s1.size();
        
//         // Initialize sliding window
//         for (int i = 0; i <= s2.size() - windowSize; ++i) {
//             vector<int> windowFreq(26, 0);
            
//             // Calculate frequency of characters in current window
//             for (int j = i; j < i + windowSize; ++j) {
//                 windowFreq[s2[j] - 'a']++;
//             }
            
//             // Compare the frequency arrays
//             if (windowFreq == freq) {
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0); // Frequency array for characters in s1
        int s1Size = s1.size(), s2Size = s2.size();
        
        // Calculate frequency of characters in s1
        for (char c : s1) {
            freq[c - 'a']++;
        }
        
        int left = 0, right = 0, count = s1Size;
        
        // Initialize sliding window
        while (right < s2Size) {
            // Expand the window and decrement the character frequency
            if (freq[s2[right++] - 'a']-- > 0) {
                count--;
            }
            
            // Check if the window size is greater than s1Size
            if (right - left == s1Size) {
                // If all characters' frequencies are 0, return true
                if (count == 0) {
                    return true;
                }
                
                // Contract the window and increment the character frequency
                if (freq[s2[left++] - 'a']++ >= 0) {
                    count++;
                }
            }
        }
        
        return false;
    }
};


