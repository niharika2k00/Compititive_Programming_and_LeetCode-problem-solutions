/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * https://leetcode.com/problems/powx-n/
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    //  Time Complexity :  O(n)
    //  Space Complexity :  O(1)
    /*  double myPow(double x, int n)
     {
         double ans = 1.0;
         for (int i = 0; i < n; i++)
             ans = ans * x;

         if (n < 0) // negative
             ans = (double)1.0 / (double)ans;

         return ans;
     } */

    //  Time Complexity :  O(log n)
    //  Space Complexity :  O(1)
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long modifiedPow = n;

        if (modifiedPow < 0)
            modifiedPow = (-1) * n;

        while (modifiedPow)
        {
            if (modifiedPow % 2 == 0) //  Power Even   2^10
            {
                x = x * x;
                modifiedPow = modifiedPow / 2;
            }
            else //  Odd
            {
                ans = ans * x;
                modifiedPow = modifiedPow - 1;
            }
        }

        if (n < 0)
            ans = (double)(1.0) / (double)(ans);

        return ans;
    }
};
// @lc code=end
