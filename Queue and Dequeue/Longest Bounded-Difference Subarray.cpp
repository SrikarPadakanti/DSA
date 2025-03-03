Given an array of positive integers arr[] and a non-negative integer x, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than x.
If multiple such subarrays exist, return the one that starts at the smallest index.

Examples: 

Input: arr[] = [8, 4, 2, 6, 7], x = 4 
Output: [4, 2, 6] 
Explanation: The sub-array described by index [1..3], i.e. [4, 2, 6] contains no such difference of two elements which is greater than 4.
Input: arr[] = [15, 10, 1, 2, 4, 7, 2], x = 5 
Output: [2, 4, 7, 2] 
Explanation: The sub-array described by indexes [3..6], i.e. [2, 4, 7, 2] contains no such difference of two elements which is greater than 5. 
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 109
0 <= x<= 109


class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        deque<int> minQ, maxQ;
        int n = arr.size(), start = 0, end = 0;
        int resStart = 0, resEnd = 0;
        while(end < n) {
            while(!minQ.empty() && arr[minQ.back()] > arr[end])
                minQ.pop_back();
            
            while(!maxQ.empty() && arr[maxQ.back()] < arr[end])
                maxQ.pop_back();
            
            minQ.push_back(end);
            maxQ.push_back(end);
            
            while(arr[maxQ.front()] - arr[minQ.front()] > x) {
                if(start == minQ.front())
                    minQ.pop_front();
                if(start == maxQ.front())
                    maxQ.pop_front();
                start += 1;
            }
            if(end - start > resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
            end += 1;
        }
        vector<int> res;
        for(int i = resStart; i <= resEnd; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
