/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &a)
    {
        int j, answer = INT_MIN, len = a.size(), aiplusi = a[0] + 0;
        //   i < j
        //  a[i] + a[j] + i -j;
        //  (a[i] + i) + (a[j] - j)   <---- we have to maximise both the part

        for (j = 1; j < len; j++)
        {
            answer = max(answer, aiplusi + (a[j] - j));
            aiplusi = max(aiplusi, a[j] + j); // modified a[i] + i
        }

        return answer;
    }
};
// @lc code=end
