/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    void getReverse(vector<char> &s, int left, int right)
    {
        if (left >= right)
            return;

        swap(s[left], s[right]);
        getReverse(s, left + 1, right - 1);
    }

    void reverseString(vector<char> &s)
    {
        int left = 0, right = s.size() - 1;
        if (left >= right)
            return;

        /*   // Method 2
          while (left < right)
          {
              swap(s[left], s[right]);
              left++;
              right--;
          } */

        getReverse(s, left, right);
    }
};
// @lc code=end
