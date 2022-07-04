
//  CodeStudio
// https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-16/problems/17651?leftPanelTab=0
//    Using BFS

#include <bits/stdc++.h>

int rightShift(int num)
{
    auto str = to_string(num);
    rotate(str.begin(), str.begin() + str.size() - 1, str.end());
    return stoi(str);
}

int minimumCoins(int n, int x)
{
    // Write your code here.
    const int INF = 1e9;
    vector<int> dis(10 * n, INF);
    vector<int> visited(10 * n, 0);

    dis[1] = 0, visited[1] = 1;
    queue<int> pq;
    pq.push(1);

    // 	 BFS Loop
    while (!pq.empty())
    {
        int curr = pq.front();
        pq.pop();

        // 		 If reeached 'N' then stop
        if (curr == n)
            break;

        // 		first operation (multiply)
        if (1LL * curr * x < 10 * n && !visited[curr * x])
        {
            visited[curr * x] = 1;
            pq.push(curr * x);
            dis[curr * x] = dis[curr] + 1; // +1 operation
        }

        // 		if  single digit and  starting with 0
        if (curr <= 10 || curr % 10 == 0)
            continue;

        // 		 second operation
        int shift = rightShift(curr);
        if (shift < 10 * n && !visited[shift]) // after shuffle if its still inside the range and not visited
        {
            visited[shift] = 1;
            pq.push(shift);
            dis[shift] = dis[curr] + 1;
        }
    }

    if (dis[n] == INF)
        return -1;
    else
        return dis[n];
}
