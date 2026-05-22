/*
Problem: LeetCode 169 – Majority Element

Approach:
1. Use Boyer-Moore Voting Algorithm.
2. Maintain:
   - candidate → potential majority element
   - count → current vote count
3. Traverse array:
   - If count becomes 0:
       → choose current element as candidate.
   - If current element equals candidate:
       → increment count.
   - Else:
       → decrement count.
4. Final candidate will be majority element.

Key Idea:
- Majority element appears more than n/2 times,
  so it survives all cancellations.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (int num : nums) {
            // If count becomes 0, choose a new candidate
            if (count == 0) {
                candidate = num;
            }
            // Increase or decrease count based on match
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};
