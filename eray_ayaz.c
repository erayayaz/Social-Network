//Eray Ayaz
//150116053
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
struct FriendListNode{
    char relationship[100];
    struct FriendListNode *next;
};
struct People{
    char names[100];
    struct FriendListNode *head;
    int cost;
    double dCentrality;
    double cCentrality;
    double bCentrality;
};
struct Graph{
    int V;
    struct People *array;
    int *visited;
};
//This function create a graph
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    // Create an array of adjacency lists.  Size of array will be V
    graph->array =(struct People*) malloc(V * sizeof(struct People));
    graph->visited = malloc(V * sizeof(int));
    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
        graph->visited[i] = 0;
        graph->array[i].cost=0;
    }
    return graph;
}
//This function adds an edge to an undirected graph
void addEdge(struct Graph* graph,char *src,char *dest,int me)
{
    // Add an edge from src to dest.  A new node is added to the adjacency list of src.  The node
    // is added at the beginning
    struct FriendListNode* friendPointer = (struct FriendListNode*) malloc(sizeof(struct FriendListNode));
    strcpy(friendPointer->relationship,dest);
    friendPointer->next=NULL;
    strcpy(graph->array[me].names,src);

    friendPointer->next=graph->array[me].head;
    graph->array[me].head =friendPointer;

}
//This function print the graph
void printGraph(struct Graph* graph){

    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct FriendListNode* tempPointer;
        tempPointer = graph->array[v].head;
        printf("\n Adjacency list of vertex %s\n %s ",graph->array[v].names,graph->array[v].names);
        while (tempPointer)
        {
            printf("-> %s", tempPointer->relationship);
            tempPointer = tempPointer->next;
        }
        printf("\n");
    }
    printf("\n");
}
//This function find the how many friends they have and divide with number of people - 1
void degreeCenrality(struct Graph* graph){
    int counter=0;
    int i;

    for(i=0;i<graph->V;i++){
        struct FriendListNode* tempPointer;
        tempPointer = graph->array[i].head;
        while(tempPointer){
            counter++;
            tempPointer=tempPointer->next;
        }
        double standardizedScore;
        standardizedScore= ((double)counter / (graph->V-1));
        graph->array[i].dCentrality=standardizedScore;
        counter=0;
    }

}

void betwennessCentrality(struct Graph *graph, int n, int startNode){
    int i,y,nextNode=0,k,b,c,s,u,minDistance,count;
    int pred[10];
    int distance[10];
    int cost[10][10];
    int visited[10];
    double count10=0,count1=0,count2=0,count3=0,count4=0,count5=0,count7=0,count8=0,count9=0,count6=0;
    printf("Source          Target          Intermedia Nodes                Path\n");
    printf("------          ------          ----------------                ----\n");
    for(startNode=0;startNode<n;startNode++) {
        for (s = 0; s < n; s++) {
            struct FriendListNode *temp = graph->array[s].head;
            while (temp != NULL) {
                for (u = 0; u < n; u++) {
                    if (strcasecmp(temp->relationship, graph->array[u].names) == 0) {
                        graph->array[u].cost = 1;
                    }
                }
                temp = temp->next;
            }
            for (k = 0; k < n; k++) {
                cost[s][k] = graph->array[k].cost;
            }
            for (c = 0; c < n; c++) {
                graph->array[c].cost = 0;
            }
        }
        for (i = 0; i < n; i++) {
            for (y = 0; y < graph->V; y++) {
                if (cost[i][y] == 0) {
                    cost[i][y] = 999;
                }
            }
        }
        for (b = 0; b < n; b++) {
            pred[b] = startNode;
            distance[b] = cost[startNode][b];
            visited[b] = 0;
        }
        distance[startNode] = 0;
        count = 1;
        visited[startNode] = 1;
        while (count < n - 1) {
            minDistance = 999;
            for (i = 0; i < n; i++)
                if (!visited[i]) {
                    if (distance[i] < minDistance) {
                        minDistance = distance[i];
                        nextNode = i;
                    }
                }
            visited[nextNode] = 1;
            for (i = 0; i < n; i++)
                if (!visited[i])
                    if (minDistance + cost[nextNode][i] < distance[i]) {
                        distance[i] = minDistance + cost[nextNode][i];
                        pred[i] = nextNode;
                    }
            count++;
        }
        int r,x=0;
        for (i = 0; i < n; i++) {
            if (i != startNode) {
                //Print the source name and target name
                printf("\n%s        \t%s",graph->array[startNode].names,graph->array[i].names);
                r = i;
                printf("\t\t|");
                //Find the Intermedia nodes then print them.
                while (r != startNode) {
                    r = pred[r];
                    if (r == startNode){
                        printf("\t");
                        x++;
                        break;
                    }
                    else if (r != startNode) {
                        if (strcmp(graph->array[r].names, "Cem") == 0)
                            count10++;
                        else if (strcmp(graph->array[r].names, "Ayse") == 0)
                            count1++;
                        else if (strcmp(graph->array[r].names, "Belma") == 0)
                            count2++;
                        else if (strcmp(graph->array[r].names, "Edip") == 0)
                            count3++;
                        else if (strcmp(graph->array[r].names, "Dundar") == 0)
                            count4++;
                        else if (strcmp(graph->array[r].names, "Gamze") == 0)
                            count5++;
                        else if (strcmp(graph->array[r].names, "Ferit") == 0)
                            count6++;
                        else if (strcmp(graph->array[r].names, "Halit") == 0)
                            count7++;
                        else if (strcmp(graph->array[r].names, "Ilke") == 0)
                            count8++;
                        else if (strcmp(graph->array[r].names, "Jale") == 0)
                            count9++;
                        printf("%s,",graph->array[r].names);
                    }
                    printf("|");
                }
                if(x==1)
                    printf("            \t\t%s",graph->array[i].names);
                if(x!=1)
                    printf("%s",graph->array[i].names);
                r = i;
                //Print the paths
                while (r != startNode) {
                    r = pred[r];
                    printf("<-%s",graph->array[r].names);
                }
            }
            x=0;
        }
    }
    //This part calculate the betwenness centrality of nodes
    int divide=(n-1)*(n-2);
    int divider=divide/2;
    printf("\n");
    double standardized10,standardized1,standardized2,standardized3,standardized4,standardized5,standardized6,standardized7,standardized8,standardized9;
    standardized10=((count10) / divider);
    standardized1=count1/divider;
    standardized2=count2/divider;
    standardized3=count3/divider;
    standardized4=count4/divider;
    standardized5=count5/divider;
    standardized6=count6/divider;
    standardized7=count7/divider;
    standardized8=count8/divider;
    standardized9=count9/divider;
    graph->array[0].bCentrality=standardized10;
    graph->array[1].bCentrality=standardized1;
    graph->array[2].bCentrality=standardized2;
    graph->array[3].bCentrality=standardized3;
    graph->array[4].bCentrality=standardized4;
    graph->array[5].bCentrality=standardized5;
    graph->array[6].bCentrality=standardized6;
    graph->array[7].bCentrality=standardized7;
    graph->array[8].bCentrality=standardized8;
    graph->array[9].bCentrality=standardized9;
    printf("\n");
}
//This function find the closeness centrality
void closenessCentrality(struct Graph *graph,int n,int startNode) {
    int i, y, nextNode = 0, k, b, c, s, u, o, minDistance, count;
    int pred[10];
    int distance[10];
    int cost[10][10];
    int visited[10];
    for (startNode = 0; startNode < n; startNode++) {
        for (s = 0; s < n; s++) {
            struct FriendListNode *temp = graph->array[s].head;
            while (temp != NULL) {
                for (u = 0; u < n; u++) {
                    if (strcasecmp(temp->relationship, graph->array[u].names) == 0) {
                        graph->array[u].cost = 1;
                    }
                }
                temp = temp->next;
            }
            for (k = 0; k < n; k++) {
                cost[s][k] = graph->array[k].cost;
            }
            for (c = 0; c < n; c++) {
                graph->array[c].cost = 0;
            }
        }
        for (i = 0; i < n; i++) {
            for (y = 0; y < graph->V; y++) {
                if (cost[i][y] == 0) {
                    cost[i][y] = 999;
                }
            }
        }
        for (b = 0; b < n; b++) {
            pred[b] = startNode;
            distance[b] = cost[startNode][b];
            visited[b] = 0;
        }
        distance[startNode] = 0;
        count = 1;
        visited[startNode] = 1;
        while (count < n - 1) {
            minDistance = 999;
            for (i = 0; i < n; i++)
                if (!visited[i]) {
                    if (distance[i] < minDistance) {
                        minDistance = distance[i];
                        nextNode = i;
                    }
                }
            visited[nextNode] = 1;
            for (i = 0; i < n; i++)
                if (!visited[i])
                    if (minDistance + cost[nextNode][i] < distance[i]) {
                        distance[i] = minDistance + cost[nextNode][i];
                        pred[i] = nextNode;
                    }
            count++;
        }
        int counter = 0;
        //This part calculate the distance of nodes
        for (i = 0; i < n; i++) {
            counter = counter + distance[i];
        }
        double standardizedScore;
        standardizedScore = ((double) (n - 1) / counter);
        graph->array[startNode].cCentrality=standardizedScore;

    }
}
//This function print the centrality's of nodes
void print(struct Graph* graph){
    int i;
    printf("Source     Degree Centrality   Closeness Centrality   Betweness Centrality\n");
    printf("------     -----------------   --------------------   --------------------\n");
    for(i=0;i<graph->V;i++){
        printf("%s         \t%.2f             \t%.2f            \t%.2f\n",graph->array[i].names,graph->array[i].dCentrality,graph->array[i].cCentrality,graph->array[i].bCentrality);
    }
}
    int main(){
    setlocale(LC_ALL,"Turkish");
    int V = 10;
    struct Graph* graph = createGraph(V);

    //Add people to graph
    addEdge(graph, "Cem", "Ayse",0);
    addEdge(graph, "Cem", "Ferit",0);
    addEdge(graph, "Cem", "Dundar",0);

    addEdge(graph, "Ayse", "Cem",1);
    addEdge(graph, "Ayse", "Ferit",1);
    addEdge(graph, "Ayse", "Dundar",1);
    addEdge(graph, "Ayse", "Belma",1);

    addEdge(graph, "Belma", "Ayse",2);
    addEdge(graph, "Belma", "Dundar",2);
    addEdge(graph, "Belma", "Edip",2);

    addEdge(graph, "Edip", "Belma",3);
    addEdge(graph, "Edip", "Dundar",3);
    addEdge(graph, "Edip", "Gamze",3);

    addEdge(graph, "Dundar", "Ayse",4);
    addEdge(graph, "Dundar", "Belma",4);
    addEdge(graph, "Dundar", "Cem",4);
    addEdge(graph, "Dundar", "Ferit",4);
    addEdge(graph, "Dundar", "Gamze",4);
    addEdge(graph, "Dundar", "Edip",4);

    addEdge(graph, "Gamze", "Dundar",5);
    addEdge(graph, "Gamze", "Edip",5);
    addEdge(graph, "Gamze", "Ferit",5);
    addEdge(graph, "Gamze", "Halit",5);

    addEdge(graph, "Ferit", "Ayse",6);
    addEdge(graph, "Ferit", "Cem",6);
    addEdge(graph, "Ferit", "Dundar",6);
    addEdge(graph, "Ferit", "Gamze",6);
    addEdge(graph, "Ferit", "Halit",6);

    addEdge(graph, "Halit", "Ferit",7);
    addEdge(graph, "Halit", "Gamze",7);
    addEdge(graph, "Halit", "Ilke",7);

    addEdge(graph, "Ilke", "Halit",8);
    addEdge(graph, "Ilke", "Jale",8);

    addEdge(graph, "Jale", "Ilke",9);

    printGraph(graph);
    degreeCenrality(graph);
    closenessCentrality(graph,graph->V,0);
    betwennessCentrality(graph, graph->V,0);
    print(graph);
    return 0;
}
