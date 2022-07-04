/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        k = k % len;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

/*
     Time Complexity :  O(n)
     Space Complexity : O(1)

        1) Reverse the whole vector
        2) Reverse First K elements
        3) Reverse the rest elements.


          //  Manual Reverse Function \\
     void reverse_range(int[] nums, int i, int j) {
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
 */