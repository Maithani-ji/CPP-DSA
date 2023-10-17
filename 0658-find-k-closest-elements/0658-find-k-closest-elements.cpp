class Solution {//optimal using binary search O(logn)
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();                // Get the size of the array.
        int s = 0;                         // Initialize the start of the range.
        int e = n - k;                     // Initialize the end of the range considering 'k' elements.

        while (s < e) {                    // Binary search to find the correct range.
            int mid = s + (e - s) / 2;     // Calculate the middle index.

            if (x - arr[mid] > arr[mid + k] - x) {
                // Adjust the range by comparing the distances from 'x' to the elements.
                s = mid + 1;                // Move the start to the right.
            } else {
                e = mid;                    // Move the end to the left.
            }
        }

        return vector<int>(arr.begin() + s, arr.begin() + s + k); // Return the k closest elements.
    }
};
/*
class Solution { Better Solution using 2 pointers O((n))
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;                 // Initialize the left pointer.
        int right = arr.size() - 1;   // Initialize the right pointer.

        while (right - left >= k) {   // Continue until the window size is k.
            if (x - arr[left] <= arr[right] - x) {
                // If the left element is closer or equal to x, move the right pointer to the left.
                right--;
            } else {
                // If the right element is closer to x, move the left pointer to the right.
                left++;
            }
        }

        // Create a vector containing k elements within the window.
        vector<int> result(arr.begin() + left, arr.begin() + left + k);
        return result;
    }
};

*/
/*class Solution {//brtue force using max heap O(nlogn)
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;

        for (int num : arr) {
            maxHeap.push({abs(num - x), num});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        sort(result.begin(), result.end()); // Sort the result in ascending order.

        return result;
    }
};
`   */