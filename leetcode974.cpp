/*
Problem: LeetCode 974 – Subarray Sums Divisible by K

Approach:
1. Use prefix sum + hashmap.
2. Compute running sum and its remainder with k:
   - rem = sum % k
   - If rem < 0 → adjust by adding k (to handle negatives).
3. If same remainder is seen before:
   - Subarray between those indices is divisible by k.
   - Add frequency of that remainder to count.
4. Store/update remainder frequency in map.
5. Initialize mp[0] = 1 for subarrays starting from index 0.

Key Idea:
- If two prefix sums have same remainder,
  their difference is divisible by k.

Time Complexity: O(N)
Space Complexity: O(K) / O(N)
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;     
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;
            // handle negative remainder
            if(rem < 0) rem += k;
            // if remainder already seen
            if(mp.find(rem) != mp.end()) {
                count += mp[rem];
            }
            
            mp[rem]++;
        }
        return count;
    }
};
