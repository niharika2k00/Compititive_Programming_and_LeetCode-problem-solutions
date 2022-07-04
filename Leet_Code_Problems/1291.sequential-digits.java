/*
 * @lc app=leetcode id=1291 lang=java
 *
 * [1291] Sequential Digits
 */

// @lc code=start
class Solution {

    List<Integer> vec = new ArrayList<Integer>();

    public List<Integer> sequentialDigits(int low, int high) {
        int i;
        //  Range 1  to  9
        for (i = 1; i < 10; i++) {
            dfs(low, high, i, 0);
        }

        Collections.sort(vec);
        return vec;
    }

    void dfs(int low, int high, int i, int num) {

        if (low <= num && num <= high)
            vec.add(num);

        if (num > high || i > 9) // Out of Bounds
            return;

        dfs(low, high, i + 1, num * 10 + i);
    }
}
// @lc code=end
