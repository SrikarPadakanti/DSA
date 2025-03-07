Given a string s, return the length of the longest palindromic subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.

A palindromic sequence is a sequence that reads the same forward and backward.

Examples:

Input: s = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the longest subsequence which is also a palindrome.
Input: s = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are palindromic and all have a length 1.
Input: s = "agbdba"
Output: 5
Explanation: The longest palindromic subsequence is "abdba", which has a length of 5. The characters in this subsequence are taken from the original string "agbdba", and they maintain the order of the string while forming a palindrome.
Constraints:
1 ≤ s.size() ≤ 1000
The string contains only lowercase letters.


class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        vector<int> curr(n), prev(n);
        
        for(int i = n-1; i >= 0; i--) {
            curr[i] = 1;
            for(int j = i+1; j < n; ++j){
                if(s[i] == s[j]){
                    curr[j] = prev[j-1] + 2;
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return curr[n-1];
    }
};
