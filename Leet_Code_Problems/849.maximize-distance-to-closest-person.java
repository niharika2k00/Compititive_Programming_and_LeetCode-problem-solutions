/*
 * @lc app=leetcode id=849 lang=java
 *
 * [849] Maximize Distance to Closest Person
 */

// @lc code=start
class Solution {
    public int maxDistToClosest(int[] seats) {

        int i, len = seats.length, prevFull = -1, futureFull = 0, result = 0;

        for (i = 0; i < len; i++) {
            if (seats[i] == 1)
                prevFull = i;

            else {
                // Get the NEXT Full seat
                while (futureFull < len && seats[futureFull] == 0 || futureFull < i)
                    futureFull++;

                int left = prevFull == -1 ? len : i - prevFull; // 
                int right = futureFull == len ? len : futureFull - i; // Right Gap/Distance to reach the NEXT filled chai
                result = Math.max(result, Math.min(left, right));
            }
        }

        return result;
    }
}
// @lc code=end
