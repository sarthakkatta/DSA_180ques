/*
Problem: LeetCode 1 – Two Sum

Approach:
1. Use hashmap to store:
   - value → index
2. Traverse the array:
   - Compute required value:
       more = target - nums[i]
3. Check if required value already exists in hashmap:
   - If yes → return indices.
4. Otherwise:
   - Store current number and its index in hashmap.
5. If no pair found → return {-1, -1}.

Key Idea:
- Hashmap allows finding complement in O(1) time.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0; i<n;i++){
            int num = nums[i];
            int more = target - num;
            if(mpp.find(more) != mpp.end()) {
                return {mpp[more], i};
            }
            mpp[num] = i;
        }
        return {-1,-1};
    }
};
