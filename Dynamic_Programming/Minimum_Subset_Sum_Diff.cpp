
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

int MinimizeDiff(vector<int> vec, int len, int totalSum, int subArr1Sum)
{
    int consider, notConsider;

    // Base Case            when iterator reaches the first Index  +   LEN  =  0 arr has nly 1 element
    if (len == 0)
        return abs(totalSum - 2 * subArr1Sum);

    consider = MinimizeDiff(vec, len - 1, totalSum, subArr1Sum + vec[len - 1]);
    notConsider = MinimizeDiff(vec, len - 1, totalSum, subArr1Sum);

    return min(consider, notConsider);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{1, 6, 11, 5};
    int len = vec.size(), totalSum = accumulate(vec.begin(), vec.end(), 0);

    cout << MinimizeDiff(vec, len, totalSum, 0) << endl;

    return 0;
}

/*
        ::  Test Case  ::
     -------------------------
Input:  arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11


   Explanations :
   TotalSum = 23
   subarr1(S1) + subarr2(S2) = totalSum(TS)    (if S2 sum is more)

   Difference :
   S2 -  S1 =  Minimize Diff
   (TS - S1) - S1  = Minimize Diff

   [ TS - 2S1 ]= Minimize Diff

 */