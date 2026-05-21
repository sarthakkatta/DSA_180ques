/*
Problem: LeetCode 2381 – Shifting Letters II

Approach:
1. Use Difference Array technique for efficient range updates.
2. For each query:
   - Extract start, end, direction.
   - direction == 1 → shift forward (+1)
   - direction == 0 → shift backward (-1)
3. Apply range update:
   - diff[start] += val
   - diff[end + 1] -= val (if within bounds)
4. Traverse string:
   - Maintain cumulative shift value.
   - Compute new character position:
       (current position + shift) % 26
5. Handle negative modulo by adding 26 if needed.
6. Update character and return final string.

Key Idea:
- Difference array avoids applying each shift individually over ranges.

Time Complexity: O(N + Q)
Space Complexity: O(N)
*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for(auto &q : shifts){
            int start = q[0];
            int end = q[1];
            int dir = q[2];

            int val = (dir == 1) ? 1 : -1;

            diff[start] += val;
            if (end + 1 < n)
                diff[end + 1] -= val;
        }

        int shift = 0;
        for (int i = 0; i < n; i++) {
            shift += diff[i];
            int newPos = (s[i] - 'a' + shift) % 26;
            // handle negative modulo
            if (newPos < 0)
                newPos += 26;

            s[i] = char(newPos + 'a');
        }
        return s;
    }
};
