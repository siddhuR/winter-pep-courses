/*
Problem Statement

Manoj is a ship captain on a mission to explore a network of islands. 
The islands are connected through various routes, 
and Manoj wants to plan his exploration using depth-first traversal.


Given a map of the island network and a starting island,
 help Manoj write a program using depth-first traversal to explore the islands in a particular order.

 Input Format 
The first line of input consists of the number of islands in the network, 
	represented by V, and the number of routes between islands, represented by E, separated by a space.

The next E lines consist of two integers each: v and w, representing a route between island v and island w.

The last line of input consists of the starting island for the depth-first traversal, represented by startVertex.

 Output Format 
The output displays "Depth First Traversal starting from vertex [startVertex]:" 
followed by a space-separated list of island indices representing the order in which Manoj explores the islands using DFS.

Sample Input   
3 2
0 1
1 2
0

Sample Output

Depth First Traversal starting from vertex 0:
0 1 2 

*/
#include <stdio.h>

#define MAX_VERTICES 100

void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int v, int w) {
    adj[v][w] = 1;
}

void DFS(int adj[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; ++i) {
        if (adj[v][i] && !visited[i]) {
            DFS(adj, visited, V, i);
        }
    }
}

int main() {
    int V, E;
    scanf("%d", &V);
    scanf("%d", &E);

    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < E; ++i) {
        int v, w;
        scanf("%d %d", &v, &w);
        addEdge(adj, v, w);
    }

    int startVertex;
    scanf("%d", &startVertex);

    printf("Depth First Traversal starting from vertex %d:\n", startVertex);
    DFS(adj, visited, V, startVertex);

    return 0;
}
