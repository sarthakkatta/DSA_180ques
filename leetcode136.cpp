/*
Problem: LeetCode 136 – Single Number

Approach:
1. Initialize XOR variable as 0.
2. Traverse the array:
   - XOR current element with xorr.
3. Properties of XOR:
   - a ^ a = 0
   - a ^ 0 = a
4. All duplicate numbers cancel out.
5. Remaining value is the single number.

Key Idea:
- XOR efficiently removes paired elements.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i=0; i<nums.size(); i++){
            xorr = xorr ^ nums[i];
        }
        return xorr;
    } 
};
