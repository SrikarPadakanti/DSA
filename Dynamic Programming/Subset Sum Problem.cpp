Subset Sum Problem - GFG

Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104


class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool> prev(sum + 1, false), curr(sum + 1);
        prev[0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(j < arr[i - 1])
                    curr[j] = prev[j];
                else
                    curr[j] = (prev[j] || prev[j-arr[i-1]]);
            }
            prev = curr;
        }
        return prev[sum];
    }
};
