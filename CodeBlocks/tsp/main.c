#include <stdio.h>
#include <stdlib.h>
#define max 99
#define inf 999
int tsp(int dist[max][max], int soc, int pos, int n){
    int res = inf;
    if(soc == (1<<n)-1){
        return dist[pos][0];
    }
    int i;
    for(i=0; i<n; i++){
        if((soc & (1<<i)) == 0){
            int temp = dist[pos][i] + tsp(dist, soc | (1<<i), i, n);
            if(temp<res){
                res = temp;
            }
        }
    }
    return res;
}
int main(){
    int res = tsp(dist, 1, 0, n);
}
