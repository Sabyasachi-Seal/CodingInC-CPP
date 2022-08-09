#include<stdio.h>

void bfs(int v, int a[][20],int q[],int visited[],int n,int f,int r)
{
       int i;
       for (i=1;i<=n;i++)
       {
            if(a[v][i] != 0 && visited[i] == 0)
            {
                q[r]=i;
                r++;
                visited[i]=1;
                printf("%d  ",i);
            }
      }
      f=f+1;
      if(f<=r)
        bfs(q[f],a,q,visited,n,f,r);
}
void main()
{
    int v,a[20][20],q[20],visited[20],n,f=-1,r=-1;
    FILE *ptr=fopen("bfsgraph.txt","r");
    fscanf(ptr,"%d",&n);
    for( int i=1; i<=n; i++)
        visited[i]=0;
    for (int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            fscanf(ptr,"%d",&a[i][j]);
    fscanf(ptr,"%d",&v);
    fclose(ptr);

    // f=r=0;
    q[r]=v;
    printf("\nBFS traversal is:\n");
    visited[v]=1;
    printf("%d   ",v);
    bfs(v,a,q,visited,n,f,r);
    if(r!=n-1)
        printf("\n BFS is not possible");
}