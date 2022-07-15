/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 *
 * https://leetcode.com/problems/next-greater-element-i/
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &arr1, vector<int> &arr2)
    {
        int len1 = arr1.size(), len2 = arr2.size();
        stack<int> st;
        unordered_map<int, int> hashMap; // stores the  [ele : nge] from arr2
        vector<int> res;

        for (int i = len2 - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr2[i])
                st.pop();

            if (!st.empty() && i < len2) // means nge exsist in the Stack
            {
                int nge = st.top();
                hashMap.insert({arr2[i], nge});
                st.push(arr2[i]);
            }

            st.push(arr2[i]);
        }

        for (int i = 0; i < len1; i++)
        {
            // cout << arr1[i] << endl;
            int ele = hashMap[arr1[i]]; //  hashMap[4]
            cout << ele << endl;
            res.push_back(ele ? ele : -1);
        }

        return res;
    }
};
// @lc code=end
