
/*
 * @lc app=leetcode id=476 lang=cpp
 * [476] Number Complement
 */

// @lc code=start
class Solution
{
public:
    vector<int> convertToBinary(int num)
    {
        vector<int> temp;
        while (num != 0)
        {
            temp.push_back(num % 2);
            num = num / 2;
        }
        return temp;
    }

    int findComplement(int num)
    {
        vector<int> binary;
        binary = convertToBinary(num);
        int i, len = binary.size(), j = 0, result = 0;

        // Complement Part
        for (i = 0; i < len; i++)
        {
            if (binary[i] == 0)
                binary[i] = 1;
            else
                binary[i] = 0;
        }

        // Converting to Decimal
        for (i = len - 1; i >= 0; i--)
            result = result + binary[i] * pow(2, j++);
        // result = result * 2 + binary[i];

        return result;

        // --------------------------------
        // METHOD -2
        // -------------------------------
        /*  int findComplement(int num)
         {
             int x = log2(num) + 1;
             bitset<32> b(num);

             for (int i = 0; i < x; i++)
                 b.flip(i); // reversing the bits one by one

             return b.to_ulong(); // Convert bitset to unsigned long.
         } */
    }
};
// @lc code=end
