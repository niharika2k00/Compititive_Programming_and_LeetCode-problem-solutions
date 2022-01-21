import java.util.HashMap;

/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {

        int i, len = nums.length, diff = 0;
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        int arr[] = new int[2];

        for (i = 0; i < len; i++) {
            diff = target - nums[i];
            if (hashMap.containsKey(diff)) {
                arr[1] = i;
                arr[0] = hashMap.get(diff);
                break;
            }
            hashMap.put(nums[i], i);
        }

        return arr;
    }
}
// @lc code=end

/* 
     KEY -->  Value of Array 
     VALUE -->  Index
*/