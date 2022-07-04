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

    // Time Complexity : O(n logn)
    // Space Complexity : O(1)
    public int findDuplicate(int[] nums) {
        int len = nums.length, i;
        Arrays.sort(nums);

        for (i = 1; i < len; i++)
            if (nums[i - 1] == nums[i])
                return nums[i];

        return -1;
    }

    // Most OPTIMIZED Approach
    // Time Complexity : O(n)
    // Space Complexity : O(1)
    public int findDuplicate(int[] nums) {
        int slow = 0, fast = 0;
        slow = nums[0];
        fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]]; // 2 Step Jump
        } while (slow != fast);

        fast = nums[0]; // Reassign with the first index
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
}
// @lc code=end
