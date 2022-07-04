/*
 * @lc app=leetcode id=917 lang=java
 *
 * [917] Reverse Only Letters
 * 
 * https://leetcode.com/problems/reverse-only-letters/
 * 
 */

// @lc code=start
class Solution {
    public String reverseOnlyLetters(String s) {

        char ch[] = s.toCharArray();
        int right = s.length() - 1, left = 0;

        while (left < right) {
            if (Character.isAlphabetic(ch[left]) && Character.isAlphabetic(ch[right])) // Both ALPHABET
            {
                char temp = ch[left];
                ch[left] = ch[right];
                ch[right] = temp;

                right--;
                left++;
            }

            else if (!Character.isAlphabetic(ch[left])) // Both NOT ALPHABET
                left++;

            else if (!Character.isAlphabetic(ch[right])) //  Left --> NOT ALPHABET   , Right --> ALPHABET
                right--;
        }

        return new String(ch);
    }
}
// @lc code=end
