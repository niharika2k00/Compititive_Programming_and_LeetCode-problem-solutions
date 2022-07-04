/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

              https://www.codingninjas.com/codestudio/problems/1062658?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // What is the MAXIMUM number of meetings that can be accommodated in the meeting room when only one meeting can be held at a particular time?
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(start) / sizeof(start[0]), i, lastMeetEnding = -1, result = 0;
    vector<pair<int, int>> vec;

    for (i = 0; i < n; i++)
        vec.push_back({end[i], start[i]});

    sort(vec.begin(), vec.end()); // sort on the basis of 1st element

    // [ End, Start ]
    for (i = 0; i < n; i++)
    {
        if (vec[i].second > lastMeetEnding)
        {
            lastMeetEnding = vec[i].first; //  store the last meeting end
            result++;
        }
    }

    cout << "Maximum number of Meeting can be held in 1 room at a time : " << result << endl;

    return 0;
}

int lastMeetEnd = -1, len = start.size(), count = 0;
vector<int> res;
vector<pair<int, int>> meet;

for (int i = 0; i < len; i++)
    //         meet.push_back({start[i] , end[i]});
    meet.push_back({end[i], start[i]});

for (int i = 0; i < len; i++)
{
    if (meet[i].second > lastMeetEnd) // start >  lastMeetEnd
    {
        lastMeetEnd = meet[i].first;
        res.push_back(i + 1);
        count++;
    }
}

cout << count << endl;
return res;
