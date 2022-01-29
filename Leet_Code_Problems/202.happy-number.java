/*
 * @lc app=leetcode id=202 lang=java
 *
 * [202] Happy Number
 */

// @lc code=start

/* 
	let's try different n:
	true  (1) -> 1
	false (2) -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4
	false (3) -> 9 -> 81 -> 65 -> 61 -> 37 (look at 2)
	false (4) -> (look at 2)
	false (5) -> 25 -> 29 -> 85 -> 89 (look at 2)
	false (6) -> 36 -> 45 -> 41 -> 17 -> 50 -> 25  (look at 5)
	true  (7) -> 49 -> 97 -> 10
	false (8) -> 64 -> 52 -> 29 (look at 5)
	false (9) -> 9 -> 81 -> 65 (look at 3)
	
	All other n >= 10, while computing will become [1-9], 
	So there are two cases 1 and 7 which are true.
	
	Notice, that all falses has the same path as 2 (loop).
	And 7 at the end becomes 1. 	
*/

class Solution {
    public boolean isHappy(int n) {

        int nextNum = 0;

        while (true) {
            nextNum = 0;

            // Runs the Loop untill a single digit value coems
            while (n != 0) {
                int rem = n % 10;
                n = n / 10;

                nextNum = nextNum + (int) Math.pow(rem, 2);
            }

            // Range  : 1  -  9
            if (nextNum >= 1 && nextNum <= 9) {
                if (nextNum == 1 || nextNum == 7) // means Happy Number
                    return true;
                else
                    return false;
            }

            else
                n = nextNum;
        }
    }
}
// @lc code=end
