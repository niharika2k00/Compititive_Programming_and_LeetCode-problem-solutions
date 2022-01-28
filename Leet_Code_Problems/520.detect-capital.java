/*
 * @lc app=leetcode id=520 lang=java
 *
 * https://leetcode.com/problems/detect-capital/
 * 
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
    public boolean detectCapitalUse(String word) {

        int len = word.length(), i, count = 0;
        int firstletter = (int) word.charAt(0);

        if (len == 1)
            return true;

        for (i = 0; i < len; i++) {
            if ((int) word.charAt(i) >= 97 && (int) word.charAt(i) <= 122)
                count++;
        }

        // All capital OR all small
        if (count == 0 || count == len)
            return true;

        // means first letter in Capital
        if ((firstletter >= 65 && firstletter <= 90) && count == len - 1)
            return true;

        return false;
    }
}
// @lc code=end
