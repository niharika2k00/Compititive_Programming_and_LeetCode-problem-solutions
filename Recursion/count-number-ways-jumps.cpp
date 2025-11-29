

// https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
#include <bits/stdc++.h>
using namespace std;

int countWays(int dist)
{
    int Z;
    if (dist == 0)
        return 1;
    if (dist == 1)
        return 1;
    if (dist < 0)
        return 0;

    Z = countWays(dist - 1) + countWays(dist - 2) + countWays(dist - 3);
    return Z;
}

int main()
{
    int distance = 4;
    cout << "Number of Ways he can jump to react his destination : " << countWays(distance);
}