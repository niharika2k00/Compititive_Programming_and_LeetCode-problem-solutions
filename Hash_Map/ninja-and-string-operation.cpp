

// https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-25/problems/19380

int isPossibleToMakeEqual(int n, vector<string> &s)
{
    // Write your code here.
    unordered_map<char, int> map;
    int i = 0, j = 0;

    //   Store in the HashMap
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < s[i].size(); j++)
            map[s[i][j]]++;
    }

    for (auto it : map)
    {
        if (it.second % n != 0)
            return 0;
    }

    return 1;
}
