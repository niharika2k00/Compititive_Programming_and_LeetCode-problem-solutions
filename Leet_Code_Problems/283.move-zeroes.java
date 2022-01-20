/*
 * @lc app=leetcode id=283 lang=java
 *
 * [283] Move Zeroes
 * 
 */

// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {

        int len = nums.length, i, j, store = 0;

        if (nums[0] == 1 && len == 1)
            return;

        for (j = 0; j < len; j++) {
            if (nums[j] != 0) {
                nums[store] = nums[j];
                store++;
            }
        }

        for (i = store; i < len; i++)
            nums[i] = 0;
    }
}
// @lc code=end
