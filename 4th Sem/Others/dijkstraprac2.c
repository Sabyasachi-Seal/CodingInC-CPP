#include <stdio.h> 
#define inf 9999
#define max 20
void dijkstra(int G[max][max], int n, int s){
    int distance[max], cost[max][max], visited[max];
    int count = 1;
    int mindis = inf;
    int next;
    int i, j;
    for(i = 0; i<n; i++){
        for(j=0; j<n; j++){
            if(G[i][j] == 0){
                cost[i][j] = inf;
            }
            else{
                cost[i][j] = G[i][j];
            }
        }
    }
    for(i=0; i<n; i++){
        distance[i] = cost[s][i];
        visited[i] = 0;
    }
    distance[s-1] = 0;
    visited[s-1]  = 1;
    while(count < n-1){
        mindis = inf;
        for(i=0; i<n; i++){
            if(!visited[i] && distance[i]<mindis){
                mindis = distance[i];
                next = i;
            }
        }
        visited[next] = 1;
        for(i=0; i<n; i++){
            if(!visited[i] && (distance[i] > mindis + cost[next][i]) ){
                distance[i] = mindis + cost[next][i];
            }
        }
        count++;
    }
    for(i = 0; i<n; i++){
        printf("\n Distance of %d from %d = %d", i+1, s, distance[i]);
    }

}
void main(){
    int G[max][max], i, j , n , s;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    FILE *file = fopen("matrixdijkstra.txt", "r");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            fscanf(file, "%d", &G[i][j]);
        }
    }
    printf("Enter source: ");
    scanf("%d", &s);
    dijkstra(G, n, s);
}