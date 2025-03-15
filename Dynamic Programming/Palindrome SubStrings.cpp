Palindrome SubStrings - GFG

Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. 

Examples

Input: s = "abaab"
Output: 3
Explanation: All palindromic substrings are : "aba" , "aa" , "baab".
Input: s = "aaa"
Output: 3
Explanation: All palindromic substrings are : "aa", "aa", "aaa".
Input: s = "abbaeae"
Output: 4
Explanation: All palindromic substrings are : "bb" , "abba" , "aea", "eae".
Constraints:
2 ≤ s.size() ≤ 103
string contains only lowercase english characters




class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n=s.length();
        int res=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for (int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                res++;
            }
        }
        for (int gap=2;gap<n;gap++){
            for (int i=0;i<n-gap;i++){
                int j=i+gap;
                if (s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    res++;
                }
            }
        }
        return res;
    }
};
