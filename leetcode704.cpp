/*
Problem: Binary Search

Approach:
1. Initialize:
   - low = 0
   - high = last index
2. Repeat while low <= high:
   - Find middle index.
3. Compare arr[mid] with target k:
   - If equal → return true
   - If arr[mid] > k:
       → search left half
   - Else:
       → search right half
4. If element not found → return false.

Key Idea:
- Binary Search works on sorted arrays
  by reducing search space by half each step.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
  public:
    bool binarySearch(vector<int>& arr, int k) {
        // code here
        int high = arr.size() - 1;
        int low = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] == k) return true;
            else if(arr[mid] > k){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
};
