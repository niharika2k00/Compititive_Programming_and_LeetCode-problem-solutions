import java.util.Stack;

/*
 * @lc app=leetcode id=402 lang=java
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
    public String removeKdigits(String num, int k) {

        int len = num.length(), i = 0;
        Stack<Character> stack = new Stack<Character>();

        for (i = 0; i < len; i++) {
            char ele = num.charAt(i);

            while (!stack.isEmpty() && k > 0 && ele < stack.peek()) {
                stack.pop();
                k--;
            }

            if (!stack.empty() || ele != '0')
                stack.push(ele);
        }

        // CASE : when the values are in INCEREASING order(Ex - 1 4 9 14), then none of the ele has been POPED OUT
        while (!stack.empty() && k > 0) {
            stack.pop();
            k--;
        }

        if (stack.empty())
            return "0";

        StringBuilder res = new StringBuilder(); // using this bcz in the String Class, there is NO REVERSE() func

        while (!stack.empty()) {
            char temp = stack.pop();
            res.append(temp);
        }

        res.reverse();

        //  Removes 0 if present at front.
        while (res.toString().startsWith("0"))
            res.deleteCharAt(0);

        return res.length() == 0 ? "0" : res.toString();
    }
}
// @lc code=end
