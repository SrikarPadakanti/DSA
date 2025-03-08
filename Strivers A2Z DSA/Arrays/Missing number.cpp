268. Missing Number - Leetcode

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation:
n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.

//Approach1 
  //O(nlogn)time and O(1)space
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(nums[0] != 0)
            return 0;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1] + 1)
                return nums[i-1]+1;
        }
        return nums[n-1]+1;
    }
};

//Approach2 - optimal(1)
  //subtracting n num sun and array sum
  //O(N) time, O(1) space
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int nsum = n*(n+1)/2, sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        return nsum-sum;
    }
};

//Approach3 - optimal(2)
  //Using XOR
  //O(n) time O(1)space
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //XOR
        int xor1 = 0, xor2 = 0;
        for(int i = 0; i < nums.size(); i++){
            xor1 ^= nums[i];
            xor2 ^= i;
        }
        xor2 ^= nums.size();
        return xor1 ^ xor2;
    }
};
