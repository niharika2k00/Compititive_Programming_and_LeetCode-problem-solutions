/*
 * @lc app=leetcode id=605 lang=java
 *
 * https://leetcode.com/problems/can-place-flowers/
 *  
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {

        int len = flowerbed.length, i, count = 0;

        for (i = 0; i < len; i++) {

            // Boundary Case + Condition
            if ((i == 0 || flowerbed[i - 1] == 0) && (i == len - 1 || flowerbed[i + 1] == 0) && flowerbed[i] == 0) {
                count++;
                flowerbed[i] = 1;
                i++; //  Shifts by 2
            }
        }

        if (n <= count)
            return true;

        return false;
    }
}
// @lc code=end

/* 
               Test Cases Sample :

        1)  [0,0,1,0,1] , n = 1         true
        2)  [1,0,0,0,0,1] , n = 2       false              
*/