#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 10

// Structure to represent a node in the graph
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
void initGraph(struct Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
}

// Function to add an edge to the graph (undirected graph)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (since it's undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform BFS
void BFS(struct Graph* graph, int startVertex) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Mark the start vertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    rear++;
    queue[rear] = startVertex;

    while (front != rear) {
        // Dequeue a vertex from the queue
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        // Get all the adjacent vertices of the dequeued vertex
        struct Node* adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) {
            int adjVertex = adjList->vertex;

            // If the adjacent vertex has not been visited, mark it and enqueue it
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                rear++;
                queue[rear] = adjVertex;
            }
            adjList = adjList->next;
        }
    }
}

// Main function to test the BFS implementation
int main() {
    struct Graph graph;

    // Initialize the graph with 5 vertices (0 to 4)
    initGraph(&graph, 5);

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);

    // Perform BFS starting from vertex 0
    printf("Breadth-First Search (BFS) starting from vertex 0: ");
    BFS(&graph, 0);

    return 0;
}
