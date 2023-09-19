/*

                                                             //    GRAPHS   \\



#Difference b / w Explicit Graph &Implicit Graph-- ---->
• Explicit Graph :
    – All vertices are identified individually and represented separately.
    – All edges are identified individually and represented separately.

  • Implicit
#Difference b / w Explicit Graph &Implicit Graph-- ---->
• Explicit Graph :
    – All vertices are identified individually and represented separately.
    – All edges are identified individually and represented separately.

  • Implicit Graph :
    – Only a subset, possibly only one, of the vertices is given an explicit representation.(The others are implied.) or we can say it is a graph whose vertices or edges are not represented as explicit objects in a computer's memory, but rather are determined algorithmically from some more concise input.
    – Only a subset, and possibly zero, of the edges is given an explicit representation.
    – A set of “operators” is provided that can be used to construct “new” edges and vertices.

#𝑪𝒐𝒎𝒑𝒍𝒆𝒕𝒆 𝒈𝒓𝒂𝒑𝒉 : it is a simple undirected graph in which every pair of distinct vertices is connected by a unique edge. A vertex should have EDGES with all other Vertices.

                    Number of Vertices -->  n(n−1) / 2 edges


#𝑪𝒐𝒎𝒑𝒍𝒆𝒕𝒆 𝒅𝒊𝒈𝒓𝒂𝒑𝒉 : it is a directed graph in which every pair of distinct vertices is connected by a pair of
                                                 unique edges(one in each direction i.e.bi - directional edges).


#𝑺𝒊𝒎𝒑𝒍𝒆 𝒈𝒓𝒂𝒑𝒉 : A graph which has neither self loops nor multiple edges(parallel edges.) i.e.where each edge
                                                 connects two distinct vertices and no two edges connects the same pair of vertices is called a simple graph.
#𝑴𝒖𝒍𝒕𝒊𝒈𝒓𝒂𝒑𝒉 : Any graph which contains some multiple edges is called a multigraph.In a multigraph, no self loops
                                                 are allowed.
#𝑷𝒔𝒆𝒖𝒅𝒐 𝒈𝒓𝒂𝒑𝒉 : A graph in which self loops and multiple edges are allowed is called psuedograph.


-------------------------------------------
// -------    VERTICES    ---------- //
-------------------------------------------
#  Adjacent Vertex :  if two vertices in a graph are connected by an edge
#  Isolated Vertex : A vertex with degree 0 (NO indegree + outdegree)
#  Sink :  A vertex of a directed graph with no outgoing edges





# BFS (Breadth First Traversal) : Traverse layer by layer. Means iterate over the vertices FIRST, then traverse its neighbour(/adjacent) vertices.

# DFS (Depth First Traversal) : Traverse a vertex till its END.

      DAG -> Directed Acyclic Graph.







//   __________________________________________________________________________
//       -----------------  SHORTEST PATH ALGORITHM   ----------------
//   __________________________________________________________________________


#Important points:
Dijkstra-- -- > * when + ve weights are associated with edges in the graph.
                * Drawback : cant deal with - ve edges
                * Greedy Method

 Bellman - Ford-- -- > * when -ve weights and -ve cycles associated with edges in the Directed graph.
                      * for Negative Cycle not VALID.
                      * Relaxation upto (N - 1) times.
                      * Take the MINIMUM cost of the edge
                      * Dynamic Programming concept.

 Floyd Warshall-- -- > Shotest path between any pair of edges







//   __________________________________________________________________________
//      --------------  MINIMUN COST SPANNING TREE (greedy method)  ---------
//   __________________________________________________________________________

Spanning Tree -->
  - All edges needs to be connected
  - Vertex = Edge-1

Minimum Spanning Tree -->
  - Pick minimum cost in the edges weight
  - Hence use MinHeap
b 
                        - then take a vertices already connected to the selected edge
                        - always maintaing a tree as further connedted min vertice may not form a tree

Kruskal Algorithm --->  - Always select the min cost edge
                        - But if it forms a CYCLE then dont consider it





#Time complexities:
   BFS / DFS : O(V + E)
   Dijkstra : O( (N + E ) log N)   =>  O(N log N)
   Bellman - Ford : O(V.E) = O(n^2)
   Floyd - Warshall : O(V ^ 3)
   Topological Sort :  O(V + E)
