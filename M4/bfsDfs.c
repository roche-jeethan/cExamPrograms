// Write only BFS and DFS functions

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
struct Node{
    int vertex;
    struct Node *next;
}; typedef struct Node *NODE;

struct Graph{
    int numVertices;
    NODE adjLists[MAX];
    bool visited[MAX];
}; typedef struct Graph *GRAPH;

NODE create(int v){
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
GRAPH createGraph(int vertices){
    GRAPH graph = (GRAPH)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    for(int i=0;i<vertices;i++){
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}
void addEdge(GRAPH graph, int src, int dest){
    NODE newNode = create(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = create(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void printGraph(GRAPH graph){
    for(int i=0;i<graph->numVertices;i++){
        NODE temp = graph->adjLists[i];
        printf("Vertex %d: ",i);
        while(temp){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
void bfs(GRAPH graph, int startVertex){
    int queue[MAX];
    int front = 0, rear = 0;
    graph->visited[startVertex] = true;
    queue[rear++]=startVertex;
    while(front<rear){
        int current = queue[front++];
        printf("%d\n",current);
        NODE temp = graph->adjLists[current];
        while(temp){
            int adj = temp -> vertex;
            if(!graph->visited[adj]){
                graph->visited[adj] = true;
                queue[rear++] = adj;
            }
            temp = temp->next;
        }
        printf("\n");
    }
}
void dfs(GRAPH graph, int vertex){
    NODE adjList = graph->adjLists[vertex];
    NODE temp = adjList;
    graph->visited[vertex] = true;
    printf("%d\n",vertex);
    while(temp!=NULL){
        int connected = temp->vertex;
        if(!graph->visited[connected]){
            dfs(graph, connected);
        }
        temp = temp->next;
    }
}
int main(){
    GRAPH graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    printf("BFS Traversal: \n");
    bfs(graph, 0);
    for(int i=0;i<graph->numVertices;i++){
        graph->visited[i] = false;
    }
    printf("DFS Traversal: \n");
    dfs(graph, 0);
    return 0;
}