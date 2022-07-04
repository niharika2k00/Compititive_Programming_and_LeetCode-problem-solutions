/*
 * @lc app=leetcode id=452 lang=java
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
    public int findMinArrowShots(int[][] points) {

        int len = points.length, i, arrows = 1, prevEnd;
        if (len == 0)
            return 0;
        if (len == 1)
            return 1;

        Arrays.sort(points, (a, b) -> a[1] - b[1]); // Sort with the Ending Diameter

        prevEnd = points[0][1];

        for (i = 0; i < len; i++) {
            if (points[i][0] <= prevEnd)
                continue;
            prevEnd = points[i][1];
            arrows++;
        }

        return arrows;
    }
}
// @lc code=end
