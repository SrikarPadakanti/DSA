You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB. For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k = 1.

Return the length of the longest possible word chain with words chosen from the given list of words in any order.

Examples:

Input: words[] = ["ba", "b", "a", "bca", "bda", "bdca"]
Output: 4
Explanation: One of the longest word chains is ["a", "ba", "bda", "bdca"].
Input: words[] = ["abc", "a", "ab"]
Output: 3
Explanation: The longest chain is {"a", "ab" "abc"}
Input: words[] = ["abcd", "dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
Constraint:
1 <= words.length <= 104
1 <= words[i].length <= 10
 words[i] only consists of lowercase English letters.


class Solution {
  public:
    bool static cmp(const string& a, const string& b) {
        return a.size() < b.size();
    }
    
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> dp;
        int res = 1;
        
        for(const string& w : words) {
            dp[w] = 1;
            for(int i = 0; i < w.size(); ++i) {
                string pred = w.substr(0, i) + w.substr(i+1);
                if(dp.find(pred) != dp.end()) {
                    dp[w] = max(dp[w], dp[pred] + 1);
                }
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};
