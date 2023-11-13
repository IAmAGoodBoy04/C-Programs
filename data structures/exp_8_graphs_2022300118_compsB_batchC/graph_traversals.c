// Implement BFS & DFS traversal for graphs.
// You need to make use of an adjacency matrix for representing the graph
// The structure below should allow you to handle both directed and undirected graphs.
// For traversals, the respective function should accept starting node for traversal and perform traversal (BFS/ DFS).

#include "queue.c"

GraphRep *init_graph(int num_vertices, bool is_directed){
    GraphRep* newgraph=malloc(sizeof(GraphRep));
    newgraph->edges=malloc(num_vertices*sizeof(bool*));
    newgraph->distance=malloc(num_vertices*sizeof(int));
    newgraph->color=malloc(num_vertices*sizeof(Color));
    newgraph->predecessor=malloc(num_vertices*sizeof(Vertex));
    newgraph->finish=NULL;//Finish is not initialised here itself as it is only needed for DFS
    for(int i=0;i<num_vertices;i++){
        newgraph->edges[i]=calloc(num_vertices,sizeof(bool));//initialise all positions in adjacency matrix to 0
        newgraph->distance[i]=-1;//distance==-1 -> node not connected
        newgraph->color[i]=WHITE;//initialise all nodes to white
        newgraph->predecessor[i]=INT_MAX;//predecessor>nV means no predecessor
    }
    newgraph->nV=num_vertices;
    newgraph->nE=0;
    newgraph->is_directed=is_directed;
    return newgraph;
}

void insert_edge(GraphRep *graph, Edge e){
    if(graph->edges[e.u][e.v]==0){
        graph->edges[e.u][e.v]=1;
        if(!graph->is_directed){
            graph->edges[e.v][e.u]=1;//add two ones to adjacency matrix only when graph is undireccted
        }
        graph->nE++;
    }
}

void remove_edge(GraphRep *graph, Edge e){
    if(graph->edges[e.u][e.v]!=0){
        graph->edges[e.u][e.v]=0;
        if(!graph->is_directed){
            graph->edges[e.v][e.u]=0;//have to remove bith ones when graph is undirected
        }
        graph->nE--;
    }
}


// NOTE: During both DFS and BFS traversals, when at a vertex that is connected with multiple vertices, always pick the connecting vertex which has the lowest value first
// Both traversals will always update the following attributes of the Graph:
// 1. source -> stores the value of the starting vertex for the traversal
// 2. type -> stores the traversal type (BFS or DFS)
// 3. color --> indicates if all vertices have been visited or not. Post traversal, all vertices should be BLACK
// 4. predecessor --> this array would hold the predecessor for a given vertex (indicated by the array index). 

// NOTE: BFS Traversal should additionally update the following in the graph:
// 1. distance --> this array would hold the number of hops it takes to reach a given vertex (indicated by the array index) from the source. 
void traverse_bfs(GraphRep *graph, Vertex source){
    graph->source=source;
    int bfsarr[graph->nV];
    graph->type=BFS;
    graph->color[source]=GRAY;
    graph->distance[source]=0;
    graph->predecessor[source]=INT_MAX;/*setting predecessor of source as null, since we can't use null with integers, we are using a large number instead,which is unlikely to be the an index*/
    Queue* bfsqueue=initialize_queue(graph->nV);
    Vertex temp;
    int index=0;
    enqueue(bfsqueue,source);
    while(!isEmpty(bfsqueue)){
        temp=dequeue(bfsqueue);//dequeue a node, this is our current grey vertex
        bfsarr[index]=temp;
        index++;
        for(int i=0;i<graph->nV;i++){
            if(graph->edges[temp][i]==1){
                if(graph->color[i]==WHITE){//process all adjacent vertices and enqueue them
                    graph->color[i]=GRAY;
                    graph->distance[i]=graph->distance[temp]+1;
                    graph->predecessor[i]=temp;
                    enqueue(bfsqueue,i);
                }
            }
        }
        graph->color[temp]=BLACK;//paint the current vortex black as we have explored all adjacent vertices
    }
    printf("The BFS traversal of the given graph originating from vertex %d is\n[ ",source);
    for(int i=0;i<index;i++){
        printf("%d ",bfsarr[i]);//printing the BFS traversal
    }
    printf("]\n");
}

void dfs_visit(GraphRep* graph,Vertex source, int *time);
// NOTE: DFS Traversal should additionally update the following in the graph:
// 1. distance --> Assuming 1 hop to equal 1 time unit, this array would hold the time of discovery a given vertex (indicated by the array index) from the source. 
// 2. finish --> Assuming 1 hop to equal 1 time unit, this array would hold the time at which exploration concludes for a given vertex (indicated by the array index). 
void traverse_dfs(GraphRep *graph, Vertex source){
    graph->source=source;
    graph->type=DFS;
    graph->finish=calloc(graph->nV,sizeof(int));
    int time=0;
    printf("The DFS traversal of the given graph originating from vertex %d is \n[ ",source);
    dfs_visit(graph,source,&time);/*since there is a source node specified for the DFS function, we run DFS for that first, an then do it for any Ehite nodes left */
    for(int i=0;i<graph->nV;i++){//doing DS for any unvisited nodes
        if(graph->color[i]==WHITE){
            dfs_visit(graph,i,&time);
        }
    }
    printf("]\n");
}

void dfs_visit(GraphRep* graph,Vertex source, int *time){/*this is a helper function for the traverse_dfs function, with only those parts of the code which need to be executed recursively*/
// Recursive DFS traversal function
// Update attributes for the current vertex and explore adjacent nodes
    graph->distance[source]=*time;
    (*time)++;
    graph->color[source]=GRAY;
    printf("%d ",source);
    for(int i=0;i<graph->nV;i++){
        if(graph->edges[source][i]==1){
            if(graph->color[i]==WHITE){//Explore adjacent unexplored nodes first
                graph->predecessor[i]=source;
                dfs_visit(graph,i,time);
            }
        }
    }
    graph->finish[source]=*time; // Record the time of completion and mark the vertex as BLACK
    (*time)++;
    graph->color[source]=BLACK;
}  

// displays the path from the current 'source' in graph to the provided 'destination'. 
// The graph holds the value of the traversal type, so the function should let the caller know what kind of traversal was done on the graph and from which vertex, along with the path.
void display_path(GraphRep *graph, Vertex destination){
    if(graph->distance[destination]<0){
        printf("This node is unreachable from the source vortex\n");
        return;
    }
    if(graph->type==BFS){
        printf("BFS traversal was perfomed on this graph\n");
    }
    else{
        printf("DFS traversal was performed on this graph\n");
    }
    if(destination<0 || destination>graph->nV || graph->predecessor[destination]>graph->nV){
        if(destination==graph->source){
            printf("The destination is same as the source vortex");
        }
        else{
            printf("The destination is invalid!\n");
        }
    }//error cases
    int arr[graph->nV];
    int index=0;
    int current=destination;
    while(true){/*we just backtrack by following the predecessor array for a chain of nodes from the destination to the source*/
        arr[index]=current;
        current=graph->predecessor[current];
        if(current>graph->nV){
            break;
        }
        index++;
    }
    printf("The path from the source to the destination node %d is:\n",destination);
    printf("source -> ");
    for(int i=index;i>=0;i--){
        if(i>0){
            printf("%d -> ",arr[i]);
        }
        else{
            printf("%d <- destination\n",arr[i]);
        }
    }
}


// display the graph in the matrix form
void display_graph(GraphRep *graph){
    for(int i=0;i<graph->nV;i++){
        for(int j=0;j<graph->nV;j++){//printing the 2d adjacency matrix
            printf("%d ",graph->edges[i][j]);
        }
        printf("\n");
    }
}


int main() {
    GraphRep *graph = init_graph(7, true);
    Edge edges[] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2,3}, {3, 4}, {4, 5}, {5, 6}};
    for (int i = 0; i < sizeof(edges) /sizeof(edges[0]); i++) {
        insert_edge(graph, edges[i]);
    }
    printf("Original Graph (DFS graph):\n");
    display_graph(graph);
    traverse_dfs(graph, 0);
    display_path(graph, 6);
    GraphRep *graph2= init_graph(6, true);
    Edge edges2[] = {{0, 2}, {1, 3}, {2, 4}, {3, 5}, {4,5}, {0, 1}};
    for (int i = 0; i < sizeof(edges) /sizeof(edges[0]); i++) {
        insert_edge(graph2, edges2[i]);
    }
    printf("\nOriginal Graph (bfs graph):\n");
    display_graph(graph2);
    traverse_bfs(graph2, 0);
    display_path(graph2, 5);
return 0;
}