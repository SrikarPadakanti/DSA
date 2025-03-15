Coin Change (Minimum Coins) - GFG

You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.

Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.

Examples:

Input: coins[] = [25, 10, 5], sum = 30
Output: 2
Explanation: Minimum 2 coins needed, 25 and 5  
Input: coins[] = [9, 6, 5, 1], sum = 19
Output: 3
Explanation: 19 = 9 + 9 + 1
Input: coins[] = [5, 1], sum = 0
Output: 0
Explanation: For 0 sum, we do not need a coin
Input: coins[] = [4, 6, 2], sum = 5
Output: -1
Explanation: Not possible to make the given sum.
 
Constraints:
1 ≤ sum * coins.size() ≤ 106
0 <= sum <= 104
1 <= coins[i] <= 104
1 <= coins.size() <= 103


class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        vector<int> dp(sum+1, INT_MAX);
        dp[0] = 0;
        
        for(int i = coins.size()-1; i >= 0; i--){
            for(int j = 1; j <= sum; j++){
                int y = INT_MAX, n = INT_MAX;
                if(j - coins[i] >= 0 && coins[i] > 0){
                    y = dp[j - coins[i]];
                    if(y != INT_MAX) y++;
                }
                if(i + 1 < coins.size())
                    n = dp[j];
                
                dp[j] = min(y, n);
            }
        }
        if(dp[sum] != INT_MAX) return dp[sum];
        return -1;
    }
};
