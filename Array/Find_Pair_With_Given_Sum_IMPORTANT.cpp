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

//    SORTING + TWO POINTER
void findPair(vector<int> vec, int len, int X)
{
    int l = 0, r = len - 1, flag = 0, count = 0;
    sort(vec.begin(), vec.end());

    while (r > l)
    {
        if (vec[r] + vec[l] == X)
        {
            flag = 1;
            cout << "Pair Found in the arrray : " << vec[l] << " " << vec[r] << endl;
            count++;
            // break;
        }
        if (vec[r] + vec[l] > X)
            r--;
        else
            l++;
    }

    if (flag)
        cout << "Number of Pairs Found with Sum K  =>  " << count << endl;
    else
        cout << "Pair Not Found" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{1, 5, 3, 4, 2};
    int len = vec.size(), X = 7;

    findPair(vec, len, X);

    return 0;
}

/*
int i, rem = 0;
for (i = 0; i < n; i++)
{

    if (arr[i] <= x)
    {
        rem = x - arr[i];
        int term = *find(arr, arr + n, rem);
        if (term != 0) //  !0  -->  true
            return 1;
    }
}
return 0; */

// Find the Num of Pair having difference K   <-------   in HashMap Directory.