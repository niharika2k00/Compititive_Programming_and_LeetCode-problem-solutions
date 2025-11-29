
// https://www.geeksforgeeks.org/ways-remove-one-element-binary-string-xor-becomes-zero/
#include <bits/stdc++.h>
using namespace std;

int xorZero(string str)
{
    int one_count = 0, zero_count = 0, i, len = str.length();

    for (i = 0; i < len; i++)
        if (str[i] == '1')
            one_count++;
        else
            zero_count++;

    // If count of ones is EVEN then return count of zero
    // else count of one
    if (one_count % 2 == 0)
        return zero_count;
    return one_count;
}

int main()
{
    string str = "11111";
    cout << xorZero(str) << endl;
    return 0;
}
