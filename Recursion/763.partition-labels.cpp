/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {

        vector<int> A(26, 0);
        vector<int> result;

        int i, start = 0, end = 0, size = s.length();

        //  a = 97
        for (i = 0; i < size; i++)
            A[s[i] - 'a'] = i;

        for (i = 0; i < size; i++)
        {
            end = max(end, A[s[i] - 'a']);

            // end is not set till the iterator reaches the END
            if (end == i)
            {
                result.push_back(end - start + 1);
                start = i + 1; // for the new partition
            }
        }

        return result;
    }
};
// @lc code=end
