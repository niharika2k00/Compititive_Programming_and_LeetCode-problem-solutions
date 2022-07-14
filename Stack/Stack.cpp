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

class Stack
{
    int size = 1000, top = -1;
    int *arr = new int[size];

public:
    //  Constructor
    Stack()
    {
        top = -1, size = 1000;
        arr = new int[size];
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }

    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }

    int Top()
    {
        return arr[top];
    }

    int Size()
    {
        return top + 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);

    cout << "Top of stack is : " << s.Top() << endl; // accessing data member
    cout << "Size of stack : " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;

    return 0;
}
