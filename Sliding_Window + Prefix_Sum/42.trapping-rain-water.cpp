/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/
 *
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        //  Uisng PrefixMax  &   SuffixMax Vectors
        //  Time Complexity :   O(3n) ~ O(n)
        //  Space Complexity : O(n) + O(n)  ~ O(2n)
        int len = height.size(), water = 0;
        vector<int> prefixMax(len), suffixMax(len);

        //  Prefix Sum
        prefixMax[0] = height[0];
        for (int i = 1; i < len; i++)
            prefixMax[i] = max(prefixMax[i - 1], height[i]);

        //  Suffix Sum
        suffixMax[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i + 1], height[i]);

        for (int i = 0; i < len; i++)
            water += min(prefixMax[i], suffixMax[i]) - height[i];

        //  Time Complexity :   O(3n) ~ O(n)
        //  Space Complexity :  O(1)
        int len = height.size(), water = 0, l = 0, r = len - 1, leftMax = 0, rightMax = 0;

        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= leftMax)
                    leftMax = height[l]; // leftMax update

                else
                    water += (leftMax - height[l]);

                l++;
            }

            else
            {
                if (height[r] >= rightMax)
                    rightMax = height[r];

                else
                    water += (rightMax - height[r]);

                r--;
            }
        }

        return water;
    }
};
// @lc code=end
