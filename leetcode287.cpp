/*
Problem: LeetCode 287 – Find the Duplicate Number

Approach:
1. Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare).
2. Treat array as a linked list:
   - Value at index acts as next pointer.
3. Phase 1:
   - slow moves one step
   - fast moves two steps
   - Detect meeting point inside cycle.
4. Phase 2:
   - Reset slow to start.
   - Move both one step at a time.
   - Meeting point becomes duplicate number.
5. Return duplicate element.

Key Idea:
- Duplicate number forms a cycle in index traversal.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
