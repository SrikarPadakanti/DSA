Ways to Reach the n'th Stair - GFG

There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).

Examples:

Input: n = 1
Output: 1
Explanation: There is only one way to climb 1 stair. 
Input: n = 2
Output: 2
Explanation: There are 2 ways to reach 2th stair: {1, 1} and {2}.  
Input: n = 4
Output: 5
Explanation: There are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.
Constraints:
1 ≤ n ≤ 44


class Solution {
  public:
    int countWays(int n) {
        // your code here
        int p1 = 1;
        int p2 = 1;
        for(int i = 2; i <= n; i++){
            int curr = p1 + p2;
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};
