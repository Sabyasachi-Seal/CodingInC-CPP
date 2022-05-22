#include <stdbool.h>
#include <stdio.h>
int N = 0;
void printSolution(int board[N][N]){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
}
bool isSafe(int board[N][N], int row, int col){
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;
	return true;
}
bool solveNQUtil(int board[N][N], int col){
	if (col >= N)
		return true;
	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;
			if (solveNQUtil(board, col + 1))
				return true;
			board[i][col] = 0;
		}
	}
	return false;
}
bool solveNQ(){
	int board[N][N];
    for (int i = 0; i < N*N; i++){
        board[i/N][i%N] = 0;
    }
    for(int i=0; i<N; i++){
		printSolution(board);
        if (solveNQUtil(board, i)) {
            // printSolution(board);
			printf("\n");
        }
    }

	
	return true;
}
int main(){  
    printf("Enter the number of Queens: ");
    scanf("%d", &N);
	solveNQ();
	return 0;
}
