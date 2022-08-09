#include <stdio.h>
#define max 30
void bfs(int v, int g[max][max], int visited[max], int queue[max], int front, int rear, int n){
    int i;
    for(i=1; i<=n; i++){
        if(visited[i]==0 && g[v][i] == 1){
            queue[rear] = i;
            rear++;
            visited[i] = 1;
            printf("%d ", i);
        }
    }
    front++;
    if(front<=rear){
        bfs(queue[front], g, visited, queue, front, rear, n);
    }
}
int main(){
    FILE *input = fopen("file1.txt", "r");
    int n;
    fscanf(input, "%d", &n);
    int g[max][max], visited[max], queue[max], front = -1, rear = -1;
    int i, j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            fscanf(input, "%d", &g[i][j]);
        }
    }
    for(i=1; i<=n; i++){
        visited[i] = 0;
    }
    int v;
    fscanf(input, "%d", &v);
    printf("%d ", v);


    queue[rear] = v;
    rear++;
    visited[v] = 1;
    bfs(v, g, visited, queue, front, rear, n);
    return 0;
}
