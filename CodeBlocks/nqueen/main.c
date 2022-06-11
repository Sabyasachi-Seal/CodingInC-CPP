#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 99
void print(int board[max][max], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool issafe(int board[max][max], int row, int col, int n){
    int i, j;
    for(i=0; i<col; i++){// i<col since col is the place the last queen is placed
        if (board[row][i]==1) return false;
    }
    for(i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1) return false;
    }
    for(i=row, j=col; i<n && j>=0; i++, j--){
        if(board[i][j]==1) return false;
    }
    return true;

}
bool solve(int board[max][max], int col, int n){
    if(col>=n){
        return true;
    }
    int i;
    for(i=0; i<n; i++){
        if(issafe(board, i, col, n)){
            board[i][col] = 1;
            if(solve(board, col+1, n)){
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    printf("\nEnter N: ");
    int n;
    scanf("%d", &n);
    int board[max][max];
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
    solve(board, 0, n);
    print(board, n);
    return 0;
}
