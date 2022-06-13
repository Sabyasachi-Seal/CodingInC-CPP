#include <stdio.h>
#include <stdlib.h>
#define max 99
#include <stdbool.h>
void print(int board[max][max],int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", board[n-1-i][j]);
        }
        printf("\n");
    }
}

bool issafe(int board[max][max],int n, int row, int col){
    int i, j;
    for(i=0; i<col; i++){
        if(board[row][i] == 1) return false;
    }
    for(i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1) return false;
    }
    for(i=row, j=col; i<n && j>=0; i++, j--){
        if(board[i][j] == 1) return false;
    }
    return true;
}

bool nqueen(int board[max][max], int n, int row, int col){
    if(col>=n){
        return true;
    }
    else{
        int r;
        for(r=0; r<n; r++){
            if(issafe(board, n, r, col)){
                board[r][col] = 1;
                if(nqueen(board, n, r, col+1)){
                    return true;
                }
                board[r][col] = 0;
            }
        }
        return false;
    }
}

int main()
{
    printf("Enter N: ");
    int n;
    scanf("%d", &n);
    int board[max][max];
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
    nqueen(board, n, 0, 0);
    print(board, n);
    return 0;
}
