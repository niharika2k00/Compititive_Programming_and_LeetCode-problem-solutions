/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 *
 * https://leetcode.com/problems/course-schedule-iii/
 *
 * VIDEO : https://www.youtube.com/watch?v=i95fpO1z2Fo
 *
 */

// @lc code=start
class Solution
{
public:
    bool static compare(vector<int> &a, vector<int> &b)
    {
        // compare  ASCENDING  according to the second element. [LastDay].
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>> &courses)
    {
        int len = courses.size(), time = 0;
        if (len == 0)
            return 0;

        sort(courses.begin(), courses.end(), compare);
        priority_queue<int> maxHeap;

        for (auto vec : courses)
        {
            if (vec[0] <= vec[1]) // Not Possible when duration > lastDay
            {
                time += vec[0];
                maxHeap.push(vec[0]);

                if (time > vec[1]) // remove the max element means the one that's taking MORE TIME
                {
                    time -= maxHeap.top();
                    maxHeap.pop();
                }
            }
        }

        return maxHeap.size();
    }
};
// @lc code=end

/*
                                        Explanation ||  Intuition  ||  Approach
                                    ------------------------------------------------

    courses = {{4 11} , {8 12} , {7 18} , {10 21} , {5 22} , {  7 22} }       // already Sorted

    


 */