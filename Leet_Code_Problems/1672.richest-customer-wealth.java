/*
 * @lc app=leetcode id=1672 lang=java
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
class Solution {
    public int maximumWealth(int[][] accounts) {

        int len = accounts.length, maxWealth = 0, currWealth = 0;
        System.out.println(len);

        for (int[] cust : accounts) {
            currWealth = 0; // initialises0

            for (int money : cust) {
                currWealth = currWealth + money; // each row 's SUM '
            }

            maxWealth = Math.max(currWealth, maxWealth);
        }

        return maxWealth;
    }
}
// @lc code=end
