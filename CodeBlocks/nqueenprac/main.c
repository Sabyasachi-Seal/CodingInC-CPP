#include <stdio.h>
#include <stdlib.h>
#define max 99
#include <stdbool.h>
void print(int b[max][max], int n){
    int i, j;
    printf("\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

bool issafe(int board[max][max], int row, int col, int n){
    int i, j;
    for(i=0; i<col; i++){
        if(board[row][i]==1) return false;
    }
    for(i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1) return false;
    }
    for(i=row, j=col; i<n && j>=0; i++, j--){
        if(board[i][j]==1) return false;
    }
    return true;
}

bool solve(int b[max][max], int row, int col, int n){
    if(col>=n){
        print(b, n);
        return true;
    }
    else{
        int i;
        for(i=0; i<n; i++){
            if(issafe(b, i, col, n)){
                b[i][col] = 1;
                if(solve(b, i, col+1, n)){
                    return true;
                }
                b[i][col] = 0;
            }
        }
        return false;
    }
}

int main()
{
    printf("Enter N: ");
    int n;
    scanf("%d" , &n);
    int b[max][max];
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            b[i][j] = 0;
        }
    }
    solve(b, 0, 0, n);
    //print(b, n);
    return 0;
}
