class Solution {//optimal using heap,max heap of all elements and pop till kth time and at top of max heap answere will be found. gives nlogn time and n space 
//   using min heap for more optimisation of size k, and just store top k max elements in min heap and top element of min heap will be the kth largest .
public:
  int findKthLargest(vector<int>& nums, int k) {
    // Create a min-heap (priority queue) to store the k largest elements.
    priority_queue<int, vector<int>, greater<int>> minh;

    // Iterate through the elements in the input vector 'nums.'
    for (auto h : nums) {
        if (minh.size() < k) {
            // If the min-heap has fewer than k elements, push the current element onto the heap.
            minh.push(h);
        } else {
            if (minh.top() < h) {
                // If the top element (smallest) of the min-heap is smaller than the current element 'h',
                // pop the top element to maintain only the k largest elements and push 'h' onto the heap.
                minh.pop();
                minh.push(h);
            }
        }
    }

    // Return the top element of the min-heap, which is the kth largest element in 'nums.'
    return minh.top();
}
};
// class Solution {//brute force , use sorting  and then last kth digit will be the largest k 
// public:
//     int findKthLargest(vector<int>& nums, int k) {

//         sort(nums.begin(),nums.end(), greater<int>());//sort

//         return nums[k-1];//last kth number is the largest k 
        
//     }
// };