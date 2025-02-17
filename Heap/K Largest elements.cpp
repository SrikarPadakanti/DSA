Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order. 

Examples:
Input: arr[] = [12, 5, 787, 1, 23], k = 2
Output: [787, 23]
Explanation: 1st largest element in the array is 787 and second largest is 23.

Input: arr[] = [1, 23, 12, 9, 30, 2, 50], k = 3 
Output: [50, 30, 23]
Explanation: Three Largest elements in the array are 50, 30 and 23.

Input: arr[] = [12, 23], k = 1
Output: [23]
Explanation: 1st Largest element in the array is 23.

Constraints:
1 ≤ k ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106


class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue <int, vector<int>, greater<int>>minh(arr.begin(), arr.begin()+k);
        
        for(int i = k; i < arr.size(); i++){
            if(minh.top() < arr[i]){
                minh.pop();
                minh.push(arr[i]);
            }
        }
        vector<int> res;
        while(!minh.empty()){
            res.push_back(minh.top());
            minh.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
