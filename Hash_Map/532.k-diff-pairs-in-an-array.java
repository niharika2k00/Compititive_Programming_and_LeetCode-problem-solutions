/*
 * @lc app=leetcode id=532 lang=java
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
    public int findPairs(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int i, res = 0, len = nums.length;

        for (i = 0; i < len; i++)
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);

        for (int it : map.keySet()) {
            if (k > 0 && map.containsKey(it + k) || k == 0 && map.get(it) > 1)
                res++;
        }

        return res;
    }
}
// @lc code=end
