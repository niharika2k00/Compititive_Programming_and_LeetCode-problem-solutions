/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution
{
public:
    //  METHOD - 1
    //  Using the Build - in function
    void nextPermutation(vector<int> &nums)
    {
        int len = nums.size();
        bool val = next_permutation(nums.begin(), nums.end());
        if (val)
        {
            for (auto it : nums)
                cout << it << " ";
        }
    }

    //  METHOD - 2
    // Using Customized function
    /*
           Steps :
        1) find the element before peak from END where  arr[i] < arr[i + 1]
        2) find an element(j) JUST greater than arr[i]. So search from Right Side
        3) swap ( i , j )
        4) then reverse the elements.

        Like in arr = [1 3 5 4 2]
                          5
                       3      4
                    1             2

            Here, arr[i] = 3
                  arr[j] = 4
                  swap (i , j)  ==>  [1 4 5 3 2]
                  reverse   [1 4 2 3 5]
     */

    void nextPermutation(vector<int> &nums)
    {
        int len = nums.size(), i = len - 2, j = len - 1; // [1 3 5 4 2]

        //  Find the element before Peak
        while (i >= 0 && nums[i] >= nums[i + 1]) //  to find  arr[i] < arr[i + 1]
            i--;

        if (i >= 0)
        {
            while (nums[j] <= nums[i]) // find just the greater element than the arr[i] i.e. 4
                j--;

            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end
