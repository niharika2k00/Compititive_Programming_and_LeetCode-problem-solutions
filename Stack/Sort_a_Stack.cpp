/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

               Video Link :     https://www.youtube.com/watch?v=XNAv8NrAwng

 Time Complexity :
________________________________________
----------------------------------------
 */

#include <bits/stdc++.h>

//  Here MIN - HEAP required
void insertCorrectPosition(int val, stack<int> &stack)
{
    if (stack.empty() || val > stack.top())
        stack.push(val);

    else
    {
        int top = stack.top();
        stack.pop();
        insertCorrectPosition(val, stack);
        stack.push(top);
    }

    return;
}

//  Main Function
void sortStack(stack<int> &stack)
{
    if (stack.empty())
        return;

    if (!stack.empty())
    {
        int temp = stack.top();
        stack.pop();
        sortStack(stack);
        insertCorrectPosition(temp, stack);
    }
    return;
}