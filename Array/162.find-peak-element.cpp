/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/
 *
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int peakElement = arr[0], i, len = arr.size();

        //   Binary Search
        //   Time Complexity :  O(log n)
        //   Space Complexity :  O(1)
        int low = 1, high = len - 2;

        if (len == 1)
            return 0;

        if (len == 2)
            return (arr[0] > arr[1] ? 0 : 1);

        if (arr[len - 1] > arr[len - 2])
            return len - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;

            else if (arr[mid - 1] > arr[mid]) //  means mid present @ LEFT
                high = mid - 1;

            else if (arr[mid] < arr[mid + 1])
                low = mid + 1;
        }

        return -1;

        //   One Liner
        //   Time Complexity :  O( n)
        //   Space Complexity :  O(1)

        return max_element(arr.begin(), arr.end()) - arr.begin();

        //   Binary Search
        //   Time Complexity :  O( n)
        //   Space Complexity :  O(1)

        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                return i;
        }
        return len - 1;

        //   Time Complexity :  O(n)
        //   Space Complexity :  O(1)

        if (len == 0 || len == 1)
            return 0;

        if (len == 2)
            return (arr[0] > arr[1] ? 0 : 1);

        for (i = 1; i < len - 1; i++)
        {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
                peakElement = max(peakElement, arr[i]);
        }

        auto it = find(arr.begin(), arr.end(), peakElement);
        return it - arr.begin();
    }
};
// @lc code=end
