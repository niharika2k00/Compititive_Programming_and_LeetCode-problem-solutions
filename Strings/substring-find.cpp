
#include <bits/stdc++.h>
using namespace std;

// Function to print all sub strings
//    s.substr(start_index , len_of_substring)
void subString(string s, int n)
{
    for (int i = 0; i < n; i++)          // start index
        for (int j = 1; j <= n - i; j++) //  Length of sub string
            cout << s.substr(i, j) << endl;
}

// Driver program to test above function
int main()
{
    string s = "abcd";
    subString(s, s.length());

    return 0;
}
