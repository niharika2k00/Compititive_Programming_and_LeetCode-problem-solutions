/*
 * @lc app=leetcode id=1094 lang=java
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {

        // HashMap<Integer, Integer> hashMap = new HashMap<>();
        int lengthOfTrip[] = new int[1001];
        int currPassenger = 0, i;

        // 2D - Array
        for (int arr[] : trips) {
            lengthOfTrip[arr[1]] += arr[0]; //  add passsenger start time
            lengthOfTrip[arr[2]] -= arr[0]; //  delete at end / drop when they reach
        }

        for (i = 0; i < lengthOfTrip.length; i++) {
            currPassenger = currPassenger + lengthOfTrip[i];
            if (currPassenger > capacity)
                return false;
        }

        return true;
    }
}
// @lc code=end
