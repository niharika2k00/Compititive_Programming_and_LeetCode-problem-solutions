
#include <bits/stdc++.h>
using namespace std;

void getpermutation(string s, int index)
{
    if (index >= s.length())
    {
        cout << s << endl;
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        swap(s[index], s[i]);
        getpermutation(s, index + 1);
        swap(s[index], s[i]);
    }
}

int main()
{
    string s = "abc";
    cout << "All permutation of the string = " << endl;
    getpermutation(s, 0);
    return 0;
}