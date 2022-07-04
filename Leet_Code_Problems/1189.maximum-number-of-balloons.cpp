/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int i, ans = 0;
        unordered_map<char, int> hashMap;

        for (i = 0; i < text.length(); i++)
            hashMap[text[i]]++;

        // If all the letters of BALLON present then only enters in the loop as otherwise it is not Possible.
        while (hashMap['b'] > 0 && hashMap['a'] > 0 && hashMap['l'] > 1 && hashMap['o'] > 1 && hashMap['n'] > 0)
        {
            hashMap['b'] -= 1;
            hashMap['a'] -= 1;
            hashMap['l'] -= 2;
            hashMap['o'] -= 2;
            hashMap['n'] -= 1;

            ans++;
        }

        return ans;
    }
};
// @lc code=end
