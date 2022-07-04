/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int Xor = x ^ y, count = 0;

        // METHOD -1
        // bitset<8>(Xor).to_string();       //  binary string   000010
        return bitset<32>(x ^ y).count(); // number of 1's bcz it wil

        //    METHOD 2
        while (Xor > 0)
        {
            if (Xor % 2 == 1)
                count++;
            Xor = Xor / 2;
        }
        return count;
    }
};
// @lc code=end
