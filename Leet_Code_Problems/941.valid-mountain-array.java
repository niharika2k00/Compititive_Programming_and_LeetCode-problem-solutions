/*
 * @lc app=leetcode id=941 lang=java
 *
 * https://leetcode.com/problems/valid-mountain-array/
 * 
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
    public boolean validMountainArray(int[] arr) {

        int len = arr.length, i = 0;
        int MaxElement = Arrays.stream(arr).max().getAsInt();

        if (len < 3)
            return false;

        // Start can't be more
        if (arr[0] > arr[1])
            return false;

        // Upward the slope
        while (i + 1 < len && arr[i] < arr[i + 1])
            i++;

        if (i == 0 || i == len - 1)
            return false;

        // Down the slope
        while (i + 1 < len && arr[i] > arr[i + 1])
            i++;

        return (i == len - 1) ? true : false;
    }
}
// @lc code=end
