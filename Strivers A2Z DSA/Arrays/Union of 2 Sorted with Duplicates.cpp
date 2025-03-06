Union of 2 Sorted with Duplicates - GFG

Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  <=  a.size(), b.size()  <=  105
-109  <=  a[i] , b[i]  <=  109


class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        int i = 0, j = 0, n = a.size(), m = b.size();
        vector<int> res;
        
        while(i < n && j < m) {
            if(a[i] <= b[j]) {
                if(res.size() == 0 || res.back() != a[i]){
                    res.push_back(a[i]);
                }
                i++;
            }
            else{
                if(res.size() == 0 || res.back() != b[j]){
                    res.push_back(b[j]);
                }
                j++;
            }
        }
        while(i < n){
            if(a[i] != res.back()){
                res.push_back(a[i]);
            }
            i++;
        }
        while(j < m){
            if(b[j] != res.back()){
                res.push_back(b[j]);
            }
            j++;
        }
        return res;
    }
};
