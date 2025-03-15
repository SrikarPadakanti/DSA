Longest Palindrome in a String - GFG

Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

Examples :

Input: s = “forgeeksskeegfor” 
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.
Input: s = “Geeks” 
Output: “ee”
Explanation: "ee" is the longest palindromic substring of "Geeks". 
Input: s = “abc” 
Output: “a”
Explanation: "a", "b" and "c" are longest palindromic substrings of same length. So, the first occurrence is returned.
Constraints:
1 ≤ s.size() ≤ 103
s consist of only lowercase English letters.


class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int n = s.size();
        if(n == 0) return "";
        
        int start = 0, maxlen = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= 1; j++){
                int low = i;
                int high = i + j;
                while(low >= 0 && high < n && s[low] == s[high]){
                    int currlen = high - low + 1;
                    if(currlen >maxlen){
                        start = low;
                        maxlen = currlen;
                    }
                    low--;
                    high++;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
