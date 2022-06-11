#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 99
void print(int board[max], int n)
{
    int i,j;

    for(i=1; i<=n; ++i)
        printf("\t%d",i);

    for(i=1; i<=n; ++i)
    {
        printf("\n\n%d",i);
        for(j=1; j<=n; ++j) //for nxn board
        {
            if(board[i]==j)
                printf("\tQ"); //queen at i,j position
            else
                printf("\t-"); //empty slot
        }
    }
}
int issafe(int board[max], int n, int row, int col)
{
    int i;
    for(i=1; i<=row-1; i++)
    {
        if(board[i] == col) return 0;
        else
        {
            if(abs(board[i]-col)==abs(i-row))
            {
                return 0;
            }
        }
    }
    return 1;
}

void solve(int board[max], int n, int row)
{
    int col;
    for(col=1; col<=n; col++)
    {
        if(issafe(board, n, row, col))
        {
            board[row] = col;
            if(row==n) print(board, n);
            else
            {
                solve(board, row-1, n);
            }
        }
    }
}

int main()
{
    printf("Enter N: ");
    int n;
    scanf("%d", &n);
    int b[max];
    int i, j;
    for(i=0; i<n; i++)
    {
        b[i] = 0;
    }
    solve(b, 1, n);
    return 0;
}
