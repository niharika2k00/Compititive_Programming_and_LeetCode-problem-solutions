/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.interviewbit.com/problems/allocate-books/
              https://www.codingninjas.com/codestudio/problem-details/allocate-books_1090540
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

/*
There are ‘m’ number of students and the task is to allocate all the books to their students. Allocate books in such a way that:
    1. Each student gets at least one book.
    2. Each book should be allocated to a student.
    3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the MINIMUM number of pages assigned to a student is minimum.
*/

bool isPossible(vector<int> &books, int student, int mid)
{
    int i, totalPage = 0, studentCount = 1;

    for (i = 0; i < books.size(); i++)
    {
        if (totalPage + books[i] <= mid)
            totalPage += books[i];

        else
        {
            studentCount++;
            if (studentCount > student || books[i] > mid)
                return false;

            totalPage = 0; // pages for the next student, reinitialises with 0.
            totalPage += books[i];
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> books{10, 20, 30, 40};
    int student = 2, sum = 0, start = 0, end = 0, ans = INT_MIN, mid = 0;
    sum = accumulate(books.begin(), books.end(), 0);
    end = sum;

    cout << sum << endl;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (isPossible(books, student, mid)) //  Left Part
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1; // Shift Rightward as MID higher.
    }

    cout << ans << " is the maximum number of pages assigned to a student is minimum." << endl;

    return 0;
}

/*
           ::  INPUT   ::

      2
      4 2
      5 5 5 5
      4 2
      10 20 30 40


            ::  OUTPUT   ::
       10
       60

   NOTE : This code is same as Painter's Partition Problem

   Link : (https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2)

 */