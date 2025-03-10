136. Single Number - Leetcode

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1


Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

//Bruteforce
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] == 0)
                mp[nums[i]]++;
            else
                mp.erase(nums[i]);
        }
        return mp.begin() -> first;
    }
};

//Optimal
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            res = res ^ nums[i];
        }
        return res;
    }
};
