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
#include <climits>

using namespace std;

#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define loop1(n) for (ll i = 0; i < (n); i++)
#define loop2(n) for (ll i = 1; i <= (n); i++)
#define test \
  ll t;      \
  cin >> t;  \
  while (t--)

bool isPalindrome(string str, int start, int end)
{
  while (end >= start)
  {
    if (str[start++] != str[end--])
      return false;
  }
  return true;
}

int helper(string &str, int i, int j)
{
  if (i >= j)
    return 0;

  if (isPalindrome(str, i, j))
    return 0; // means no partition req, the whole substring is palindrome

  int mini = INT_MAX;

  for (int k = i; k < j; k++)
  {
    int temp = 1 + helper(str, i, k) + helper(str, k + 1, j);
    mini = min(mini, temp);
  }

  return mini;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str = "aabb";
  int len = str.size();
  cout << helper(str, 0, len - 1);

  return 0;
}
