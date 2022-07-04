/*
 * @lc app=leetcode id=1053 lang=cpp
 *
 * [1053] Previous Permutation With One Swap
 */

// @lc code=start
class Solution
{
public:
    vector<int> prevPermOpt1(vector<int> &arr)
    {

        int i, count = 0;
        vector<int> CopyVec(arr); // coping the vector
        sort(arr.begin(), arr.end());
        // CopyVec =  arr;

        for (i = 0; i < CopyVec.size; i++)
        {
            if (arr[i] != CopyVec[i])
                count++;
        }

        if (count == 2)
            return CopyVec;
        else
            return arr;
    }
};
// @lc code=end
