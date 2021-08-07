
// https://leetcode.com/contest/biweekly-contest-58/problems/delete-characters-to-make-fancy-string/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int i = 0, del, count = 1;
    string s = "aaabaaaa";
    string ans = ""; // empty string

    ans = ans + s[0];

    for (i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            count++;
        else
            count = 1;

        if (count < 3)
            ans = ans + s[i];
    }

    cout << ans;
    cout << "\n End";

    return 0;
}