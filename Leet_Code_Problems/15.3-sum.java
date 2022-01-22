
/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> result = new LinkedList<>();
        int i, high = nums.length - 1, low = 0, sum = 0;
        Arrays.sort(nums);

        for (i = 0; i < nums.length - 2; i++) {
            if (nums[i] <= 0) {
                if (i == 0 || nums[i] != nums[i - 1]) {
                    low = i + 1;
                    high = nums.length - 1;
                    sum = -nums[i];

                    // Two Pointer Loop
                    while (low < high) {
                        if (nums[low] + nums[high] == sum) {
                            result.add(Arrays.asList(nums[i], nums[low], nums[high]));

                            //Avoiding duplicates.
                            while (low < high && nums[low] == nums[low + 1])
                                low++;

                            //Avoiding duplicates.
                            while (low < high && nums[high] == nums[high - 1])
                                high--;

                            low++;
                            high--;
                        }
                        else if (nums[low] + nums[high] < sum)
                            low++;

                        else
                            high--;
                    }
                }
            }
        }

        return result;
    }
}
// @lc code=end
