#include <stdio.h>
int main (){
    int i, j, m, n, sum2 = 0, sum = 0;
    printf("Enter the row and column size:- \n");
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    printf("Enter the matrix:-\n");
        for (i = 0; i < m; ++i){
            for (j = 0; j < n; ++j){
                scanf("%d", &matrix[i][j]);

            }
        }
    for (i = 0; i < m; i++) {
        sum += matrix[i][i];
        sum2 += matrix[i][m-i-1];
    }
    printf("Sum of the all diagonal elements = %d\n", sum+sum2);
    return 0;
}
