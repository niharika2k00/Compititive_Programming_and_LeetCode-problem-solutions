/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
 Time Complexity :
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>

#include <iostream>

using namespace std;

#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define loop1(n) for (ll i = 0; i < (n); i++)
#define loop2(n) for (ll i = 1; i <= (n); i++)
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)

bool isPrime(lli num)
{
    if (num < 2)
        return false;
    if (num == 2)
        return true;

    for (lli i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;

    return true;
}

lli checkNextNumber(lli lcm, lli minEle)
{
    lli num, ans;

    for (lli i = 2; num < 10000000010; i++)
    {
        num = (lcm * i) + minEle;
        if (isPrime(num)) //  Prime & Smallest encountered
            return num;
    }

    return -1;
}

int getlcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

lli find_LCM(vector<lli> &vec, lli n)
{
    lli result = vec[0];

    for (lli i = 1; i < n; i++)
        result = getlcm(result, vec[i]);

    return result;
}

vector<lli> splitString(string str)
{
    vector<lli> arr;
    string tmp = "";

    for (lli i = 0; i < (lli)str.length(); ++i)
    {
        if (str[i] == ' ')
        {
            arr.push_back(stoi(tmp));
            tmp = "";
        }
        else
            tmp += str[i];
    }

    arr.push_back(stoi(tmp));
    return arr;
}

void solve()
{
    lli minEle = 0, LCM, i, minEven = 0, evenSpotted = 0;
    string str;
    getline(cin, str);

    vector<lli> vec = splitString(str);

    minEle = *min_element(vec.begin(), vec.end());
    vec.erase(remove(vec.begin(), vec.end(), minEle), vec.end()); // remove min ele

    // ------------------------
    //     Base  Case
    // ------------------------
    if (minEle % 2 == 0)
        minEven = 1;

    for (lli i = 0; i < (lli)vec.size(); i++)
    {
        if (vec[i] % 2 == 0)
        {
            evenSpotted++;
            break;
        }
    }
    // ------------------------

    if (minEven == 1 && evenSpotted == 1)
    {
        cout << "None";
        return;
    }

    LCM = find_LCM(vec, (lli)vec.size()); // gcd of the rest array

    //  If (LCM + q) Prime
    if (isPrime(LCM + minEle))
    {
        cout << (LCM + minEle);
        return;
    }

    lli val = checkNextNumber(LCM, minEle);

    if (val != -1)
        cout << val;

    else
        cout << "None";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // test
    // {
    solve();
    // }

    return 0;
}