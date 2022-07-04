#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// custom compare function
int com(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length();

    for (int i = 0; i < len1; i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }

    return 1;
}

void check(string s1, string s2, int len1, int len2)
{
    if (len1 != len2)
        return;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (com(s1, s2))
        cout << "Both strings are Anagram\n";

    else
        cout << "Strings are NOT Anagram\n";
}

int main()
{
    string s1 = "test";
    string s2 = "tt";

    int len1 = s1.length(), len2 = s2.length();
    check(s1, s2, len1, len2);

    return 0;
}