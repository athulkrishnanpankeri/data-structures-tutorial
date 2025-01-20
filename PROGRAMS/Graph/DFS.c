#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure to represent a graph
typedef struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to initialize the graph
void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph (undirected graph)
void addEdge(Graph* g, int u, int v) {
    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1; // Since the graph is undirected
}

// Recursive DFS function
void DFS(Graph* g, int v, int visited[]) {
    // Mark the current node as visited
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[v][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

int main() {
    Graph g;
    int visited[MAX_VERTICES] = {0};  // Array to keep track of visited vertices

    // Initialize the graph with number of vertices
    int vertices = 6;  // Change the number of vertices as needed
    initGraph(&g, vertices);

    // Add edges to the graph
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 5);

    // Start DFS from vertex 0
    printf("Depth First Search starting from vertex 0: \n");
    DFS(&g, 0, visited);

    return 0;
}
