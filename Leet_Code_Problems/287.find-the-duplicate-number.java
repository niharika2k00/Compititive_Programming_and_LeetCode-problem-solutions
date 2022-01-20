import java.util.Arrays;

/*
 * @lc app=leetcode id=287 lang=java
 *
 * https://leetcode.com/problems/find-the-duplicate-number/
 * 
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
    public int findDuplicate(int[] nums) {

        int len = nums.length, i;
        Arrays.sort(nums);

        for (i = 1; i < len; i++)
            if (nums[i - 1] == nums[i])
                return nums[i];

        return -1;
    }
}
// @lc code=end
