/*
Problem: LeetCode 1480 – Running Sum of 1D Array

Approach:
1. Initialize a variable `sum = 0`.
2. Traverse the array:
   - Add current element to sum.
   - Update nums[i] with current sum.
3. Return the modified array as running sum.

Example:
Input:  [1,2,3,4]
Output: [1,3,6,10]

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0; 
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            nums[i] = sum; 
        }
        return nums;
    }
};
