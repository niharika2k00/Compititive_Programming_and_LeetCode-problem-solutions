/*
 * @lc app=leetcode id=1871 lang=cpp
 *
 * [1871] Jump Game VII
 *
 * https://leetcode.com/problems/jump-game-vii/
 *
 */

// @lc code=start
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        // If 0 then can jump.
        int len = s.size(), pos = 0, k = 0;

        // If last char != 0 then FALSE
        if (s[len - 1] != '0')
            return false;

        // BFS  using  queue.
        queue<int> q;

        //  store the starting position, i.e. 0th index as according to the ques s[0] = 0 ALWAYS.
        q.push(0);

        while (q.size() != 0)
        {
            pos = q.front();
            q.pop();

            // condition present in the ques
            int i = max(pos + minJump, k);
            int j = min(pos + maxJump, len - 1);

            while (i <= j)
            {
                if (s[i] == '0')
                {
                    if (i == len - 1) // condition given
                        return true;

                    q.push(i); //  store next reach where s[i] == 0
                }
                i++;
            }

            k = pos + maxJump; // update the starting position
        }

        return false;
    }
};
// @lc code=end
