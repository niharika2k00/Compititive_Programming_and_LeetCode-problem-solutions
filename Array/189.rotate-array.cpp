/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
 * https://leetcode.com/problems/rotate-array/
 */

// @lc code=start
class Solution
{
public:
    //  Rotate from Right -> Left
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        k = k % len;
        k = len - k;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
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
       -------------------------------------
     void reverse_range(int[] nums, int i, int j) {
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }


    void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}


        //  Rotate from  Left  -->  Right       input :  1 2 3 4 5      output : 3 4 5 1 2
        ----------------------------------------
        func(){

        reverse(nums.begin(), nums.begin() + k);  // vector
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());

        OR

        reverse(arr, arr + 2);    // plain array
        reverse(arr + 2, arr + n);
        reverse(arr, arr + n);

        }

 */