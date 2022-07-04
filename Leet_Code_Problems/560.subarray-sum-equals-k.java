import java.util.HashMap;

/*
 * @lc app=leetcode id=560 lang=java
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
    public int subarraySum(int[] nums, int k) {
        int sum = 0, len = nums.length, i, j, count = 0, currSum = 0;

        //  BRUTE - FORCE , Time Complexity : O(n^2)
        /* for (i = 0; i < len; i++) {
            sum = 0;
            for (j = i; j < len; j++) {
                sum = sum + nums[j];
                if (sum == k)
                    count++;
            }
        } */

        //  OPTIMIZED APPROACH , Time Complexity : O(n)
        HashMap<Integer, Integer> hashMap = new HashMap<>();

        for (i = 0; i < len; i++) {
            currSum = currSum + nums[i];

            if (currSum == k)
                count++;

            if (hashMap.containsKey(currSum - k))
                count = count + hashMap.get(currSum - k); //  hashMap[curr-k]  means the value part of the element.

            hashMap.put(currSum, hashMap.getOrDefault(currSum, 0) + 1);
        }

        return count;
    }
}
// @lc code=end
