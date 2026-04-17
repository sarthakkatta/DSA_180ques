/*
Problem: LeetCode 303 – Range Sum Query - Immutable

Approach:
1. Precompute prefix sum array:
   - prefix[i] stores sum of first i elements.
   - prefix[i+1] = prefix[i] + nums[i]
2. For any query [left, right]:
   - Sum = prefix[right + 1] - prefix[left]
3. This allows answering queries in O(1) time.

Key Idea:
- Preprocessing enables fast range sum queries.

Time Complexity:
- Constructor: O(N)
- Query: O(1)

Space Complexity: O(N)
*/

class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
