#include <stdio.h>
#include <stdlib.h>

void mat_in(int rows, int cols, int arr[rows][cols]){
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}

void mat_out(int rows, int cols, int arr[rows][cols]){
    printf("\n");
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            printf("%-5d ",  arr[i][j]); //width mod, - : left justify, 5 : Width
        }
        printf("\n");
    }
}

void mat_add(int dim, int a[dim][dim], int b[dim][dim], int res[dim][dim]){
    int i, j;
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++)
            res[i][j] = a[i][j] + b[i][j];
    }
}

void mat_sub(int dim, int a[dim][dim], int b[dim][dim], int res[dim][dim]){
    int i, j;
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++)
            res[i][j] = a[i][j] - b[i][j];
    }
}

void mat_equate(int dim, int a[dim][dim], int res[dim][dim]){
    int i, j;
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++)
            res[i][j] = a[i][j];
    }
}

void strassen_construct (int size, int dim, int A[size][size], int a11[dim][dim], int a12[dim][dim], int a21[dim][dim], int a22[dim][dim]){
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][dim+j];
            a21[i][j] = A[dim+i][j];
            a22[i][j] = A[dim+i][dim+j];
        }
    }
}

void strassen_two (int size, int A[size][size], int B[size][size], int C[size][size]){
    if (size == 2){
        int p, q, r, s, t, u, v;
        p = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
        q = (A[1][0] + A[1][1]) * B[0][0];
        r = A[0][0] * (B[0][1] - B[1][1]);
        s = A[1][1] * (B[1][0] - B[0][0]);
        t = (A[0][0] + A[0][1]) * B[1][1];
        u = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
        v = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
        C[0][0] = p + s - t + v;
        C[0][1] = r + t;
        C[1][0] = q + s;
        C[1][1] = p + r - q + u;
    }
}

void strassen (int size, int dim, int A[size][size], int B[size][size], int C[size][size]){
    if (dim == 2){
        strassen_two(dim, A, B, C);
        return;
    }
    else{
        dim = dim/2;
        int a11[dim][dim], a12[dim][dim], a21[dim][dim], a22[dim][dim];
        int b11[dim][dim], b12[dim][dim], b21[dim][dim], b22[dim][dim];
        int c11[dim][dim], c12[dim][dim], c21[dim][dim], c22[dim][dim];
        strassen_construct(size, dim, A, a11, a12, a21, a22);
        strassen_construct(size, dim, B, b11, b12, b21, b22);
        int p[dim][dim], q[dim][dim], r[dim][dim], s[dim][dim], t[dim][dim], u[dim][dim], v[dim][dim];
        int temp1[dim][dim], temp2[dim][dim]; 
        //p
        mat_add(dim, a11, a22, temp1);
        mat_add(dim, b11, b22, temp2);
        strassen(dim, dim, temp1, temp2, p);
        mat_out(dim, dim, p);
        //q
        mat_add(dim, a21, a22, temp1);
        strassen(dim, dim, temp1, b11, q);
        mat_out(dim, dim, q);
        //r
        mat_sub(dim, b12, b22, temp2);
        strassen(dim, dim, a11, temp2, r);
        mat_out(dim, dim, r);
        //s
        mat_sub(dim, b21, b11, temp2);
        strassen(dim, dim, a22, temp2, s);
        mat_out(dim, dim, s);
        //t
        mat_add(dim, a11, a12, temp1);
        strassen(dim, dim, temp1, b22, t);
        mat_out(dim, dim, t);
        //u
        mat_sub(dim, a21, a11, temp1);
        mat_add(dim, b11, b12, temp2);
        strassen(dim, dim, temp1, temp2, u);
        mat_out(dim, dim, u);
        //v
        mat_sub(dim, a12, a22, temp1);
        mat_add(dim, b21, b22, temp2);
        strassen(dim, dim, temp1, temp2, v);
        mat_out(dim, dim, v);
        //c11
        mat_add(dim, p, r, temp1);
        mat_sub(dim, temp1, t, temp2);
        mat_add(dim, temp2, v, c11); 
        mat_out(dim, dim, c11);
        //c12
        mat_add(dim, r, t, c12);
        mat_out(dim, dim, c12);
        //c21
        mat_add(dim, q, s, c21);
        mat_out(dim, dim, c21);
        //c22
        mat_add(dim, p, s, temp1);
        mat_sub(dim, temp1, q, temp2);
        mat_add(dim, temp2, u, c22);
        mat_out(dim, dim, c22);
        //pasting results on the resultant matrix
        for (int i=0l; i<dim; i++){
            for (int j=0; j<dim; j++){
                C[i][j] = c11[i][j];
                C[i][j+dim] = c12[i][j];
                C[i+dim][j] = c21[i][j];
                C[i+dim][j+dim] = c22[i][j];
            }
        }
    }
}

int main(){
    int size;
    printf("Enter the size of the Square Matrices : ");
    scanf("%d", &size);
    int A[size][size], B[size][size], C[size][size];
    printf("Enter the elements of matrix A : ");
    mat_in(size, size, A);
    printf("Enter the elements of matrix B : ");
    mat_in(size, size, B);
    strassen (size, size, A, B, C);
    printf("---Final Result---");
    mat_out(size, size, C);
    return 0; 
}