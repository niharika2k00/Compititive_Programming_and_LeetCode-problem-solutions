
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// formal parameter
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    int a, b;
    cout << "?? TYPE 2 NUMBER WHOSE GCD YOU WANT TO INVESTIGATE ??   ";
    cin >> a >> b;
    int ans = GCD(a, b); //  actual parameter
    cout << "GCD = " << ans;
}