/*
Problem: LeetCode 268 – Missing Number

Approach:
1. Compute expected sum of numbers from 0 to n:
   - sum = n * (n + 1) / 2
2. Compute actual sum of elements in array.
3. Missing number:
   - expected sum - actual sum
4. Return the result.

Key Idea:
- One number is missing from range [0, n].

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualsum = n * (n + 1) / 2;
        int calculated = 0;
        for(int i = 0; i < nums.size(); i++){
            calculated += nums[i];
        }
        int ans = actualsum - calculated;
        return ans;
    }
};
