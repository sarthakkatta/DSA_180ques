/*
Problem: Zero Array Transformation III

Approach:
1. Use two heaps:
   - Min-heap `past`:
       → stores end indices of already-used queries.
   - Max-heap `maxHeap`:
       → stores end indices of available queries.
2. Sort queries based on starting index.
3. Traverse array index by index:
   - Add all queries starting at current index into maxHeap.
4. Reduce nums[i] using already active queries:
   - nums[i] -= number of active queries.
5. If nums[i] is still > 0:
   - Use additional queries with farthest ending index first
     (greedy choice using maxHeap).
6. If nums[i] still cannot become 0:
   - Return -1.
7. Remove expired queries from `past`.
8. Final answer:
   - total queries - used queries.

Key Idea:
- Greedily use queries extending farthest to maximize removable queries.

Time Complexity: O((N + Q) log Q)
Space Complexity: O(Q)
*/

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Min-heap of used queries' end indices
        priority_queue<int, vector<int>, greater<int>> past;

        // Max-heap of available queries' end indices
        priority_queue<int> maxHeap;

        // Sort queries by start index
        sort(queries.begin(), queries.end());

        int j = 0;              // Pointer to queries
        int usedCount = 0;      // Number of queries actually used

        for (int i = 0; i < n; ++i) {
            // Push all queries starting at index i into maxHeap
            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);  // push only the end
                ++j;
            }

            // Apply effect of already-used queries
            nums[i] -= past.size();

            // Apply more queries if needed
            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                int r = maxHeap.top(); maxHeap.pop();
                past.push(r);
                usedCount++;
                nums[i]--;
            }

            // If we can't reduce nums[i] to 0
            if (nums[i] > 0)
                return -1;

            // Remove expired queries
            while (!past.empty() && past.top() == i) {
                past.pop();
            }
        }

        return queries.size() - usedCount;
    }
};
