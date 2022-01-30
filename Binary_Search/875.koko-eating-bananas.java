/*
 * @lc app=leetcode id=875 lang=java
 *
 * [875] Koko Eating Bananas
 * 
 * https://leetcode.com/problems/koko-eating-bananas/
 * 
 */

// @lc code=start
class Solution {
    //          BONARY SEARCH APPROACH
    public int minEatingSpeed(int[] piles, int h) {

        int max = Arrays.stream(piles).max().getAsInt();
        // System.out.println(max);
        int end = max, start = 1, mid = 0;

        while (end >= start) {
            mid = (start + end) / 2;

            if (isPossibleToEat(piles, mid, h)) //  If possible then try Checking with the less one 
                end = mid - 1;
            else
                start = mid + 1;
        }

        return start;
    }

    public boolean isPossibleToEat(int[] piles, int mid, int hrs) {
        int i = 0, totalHrs = 0, len = piles.length, divide = 0;

        for (i = 0; i < len; i++) {
            divide = piles[i] / mid; //  7 / 3  = 2
            totalHrs = totalHrs + divide;

            if (piles[i] % mid != 0) //  7 % 3 = 1 (remainder) so 1 more totalHrs required
                totalHrs++;
        }

        return totalHrs > hrs ? false : true;
    }
}
// @lc code=end
