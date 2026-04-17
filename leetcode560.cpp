/*
Problem: LeetCode 560 – Subarray Sum Equals K

Approach:
1. Use prefix sum + hashmap.
2. Maintain prefixsum while traversing array.
3. For each index:
   - Check if (prefixsum - k) exists in map:
       → If yes, add its frequency to count.
4. Store/update current prefixsum in map.
5. Initialize mp[0] = 1 to handle subarrays starting from index 0.

Key Idea:
- If prefixsum[j] - prefixsum[i] = k,
  then subarray (i+1 to j) has sum k.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1; 
        int prefixsum = 0, count = 0;
        for(int i=0; i <nums.size(); i++){
            prefixsum += nums[i];

            if(mp.find(prefixsum - k) != mp.end())
            count+=mp[prefixsum - k];

            mp[prefixsum]++;
        }
        return count;
    }
};
