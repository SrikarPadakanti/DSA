LCM And GCD - GFG

Given two integers a and b, the task is to compute their LCM and GCD and return an array containing their LCM and GCD.

Examples:

Input: a = 5 , b = 10
Output: [10, 5]
Explanation: LCM of 5 and 10 is 10, while their GCD is 5.
Input: a = 14 , b = 8
Output: [56, 2]
Explanation: LCM of 14 and 8 is 56, while their GCD is 2.
Input: a = 1 , b = 1
Output: [1, 1]
Explanation: LCM of 1 and 1 is 1, while their GCD is 1.
Constraints:
1 <= a, b <= 109


//Bruteforce: Taking min of a&b, iterating for GCD. LCM = (a*b)/GCD
  class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        
        int gcd;
        for(int i = min(a, b); i > 0; i--){
            if(a % i == 0 && b % i == 0){
                gcd = i;
                break;
            }
        }
        int lcm = (a * b)/ gcd;
        return {lcm, gcd};
    }
};

//Optimal: Usind Euclidean algorithm-{ GCD(a,b) = GCD(a-b,b) where a>b }
//Further optimization: rather than doing (a-b, b) till a remains > b, doing a % b
class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        //Optimal using Euclidean algorithm
        int gcd, ab = a * b;
        
        while(a > 0 && b > 0){
            if(a > b){
                a %= b;
            }
            else {
                b %= a;
            }
        }
        if(a == 0)
            gcd = b;
        else
            gcd = a;
        
        int lcm = (ab)/ gcd;
        return {lcm, gcd};
    }
};
