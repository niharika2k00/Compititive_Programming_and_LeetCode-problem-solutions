#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

void ShowQueue(priority_queue<P, vector<P>, greater<P>> Q)
{
    priority_queue<P, vector<P>, greater<P>> queue = Q;
    while (!Q.empty())
    {
        cout << '\t' << Q.top().first << ' ' << Q.top().second << endl;
        Q.pop();
    }
}

void Prims(vector<P> adjList[], int source, int n)
{
    // priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> edgeWeight(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMst(n, false); // visited node track
    int sum = 0;

    edgeWeight[0] = 0;
    pq.push({0, 0}); //  {cost , node} --> as we are finding Min Cost, thus taking first parameter of MINHEAP as Cost

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int node = top.second;
        int wt = top.first;

        // check present in MST
        if (inMst[node] == true)
            continue;

        inMst[node] = true;
        sum += wt;

        for (auto it = adjList[node].begin(); it != adjList[node].end(); it++)
        {
            int dest = it->first;
            int cost = it->second;

            if (inMst[dest] == false && cost < edgeWeight[dest])
            {
                edgeWeight[dest] = cost;
                parent[dest] = node;
                pq.push({cost, dest});
            }
        }
    }

    cout << "\n *************    Prim's Minimum Spanning Tree (inMst) | Greedy Algorithm   ****************\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " -> " << i << " \n";

    cout << "Sum of MST: " << sum << "\n";
}

int main()
{
    int n = 5;
    vector<pair<int, int>> adjList[n];

    // Undirected Graph          0 --> (1 , 2) || source --> (destination, cost)
    adjList[0].push_back(make_pair(1, 2));
    adjList[0].push_back(make_pair(3, 6));
    adjList[1].push_back(make_pair(3, 8));
    adjList[1].push_back(make_pair(4, 5));
    adjList[1].push_back(make_pair(2, 3));
    adjList[2].push_back(make_pair(4, 7));

    Prims(adjList, 0, n);

    return 0;
}

/*
EXPLAINATIONS ::

        1)  Set the adjacency list  graph[src].push_back(make_pair(dest , cost))
        2)  Create MIN_HEAP  &  edgeWeight vector ( to store the cost )
        3)  Initialise  :
                            edgeWeight[0] = 0;
                            pq.push({0, 0});

        4)   While (!Queue.empty()){
                      Compare the weight/cost and of the connected/neighbouring nodes and push into Queue

        5) when the distance[cost] array is Set then traverse it

*/

/* it->first simply means(*it).first-- -- > It is a pointer pointing to your variable which has a member first, so to access first, you just dereference the pointer then use.to access the member
In the first loop, you use iterators to iterate over the container M. Iterators emulate pointers, and have to be dereferenced to give the value the iterator is "pointing" at. In fact, for that loop, it->first is really the same as (*it).first.

for (auto it : arr){ }
In this loop over the values in the container M. The loop itself uses iterators internally and dereferences them for us. This reference about "range-based for loops" might help you. */