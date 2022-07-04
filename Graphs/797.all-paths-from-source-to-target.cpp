/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 *
 * https://leetcode.com/problems/all-paths-from-source-to-target/
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> totalPaths;

    void DFS(vector<vector<int>> &graph, vector<int> &curr, int vertex)
    {
        curr.push_back(vertex);

        if (graph.size() - 1 == vertex) // 0 - indexing
            totalPaths.push_back(curr);

        else
        {
            // Iterate over the Adjacency list
            for (auto it : graph[vertex])
                DFS(graph, curr, it);
        }
        curr.pop_back();
    }

    // Adjacent List is given
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> curr;
        DFS(graph, curr, 0);

        return totalPaths;
    }
};
// @lc code=end
