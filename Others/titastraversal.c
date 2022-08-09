#include<stdio.h>
#define max 9

int input[] = {-1, -1};

void getinput();
void initboard(int, int, int[max][max]);
void printboard(int, int, int[max][max]);
void findpath(int, int, int[max][max], int, int, int, int);

void main() {
    int m, n, sr, sc, er, ec;

    //get size
    printf("Enter row and column size (separated by a space):");
    getinput();
    m = input[0];
    n = input[1];

    //make board
    int a[m][n];
    initboard(m, n, a);
    printf("\n");
    printboard(m, n, a);


    printf("(Consider yourself to be initially standing at any point, looking towards the UPPER SIDE.)");
    printf("\n");
    
    //source input
    printf("Enter the row & column number of the Starting Point(1<=sr<=m;1<=sc<=n):");
    getinput();
    sr = input[0];
    sc = input[1];

    //destination input
    printf("Enter the row & column number of the Ending Point(1<=er<=m;1<=ec<=n):");
    getinput();
    er = input[0];
    ec = input[1];

    //findpath
    findpath(m, n, a, sr, sc, er, ec);
}

//takes inputs
void getinput(){
    scanf("%d",&input[0]);
    scanf("%d",&input[1]);
}

//prints board
void printboard(int m, int n, int a[m][n]){
    printf("The grid of checkpoints is as follows:");
    printf("\n");
    int i, j;
    printf("[UPPER SIDE]\n");
    for (i = m - 1; i >= 0; i--) {  
        for (j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("[LOWER SIDE]\n");
}

//initializes board
void initboard(int m, int n, int a[m][n]){
    int i, j;
    for (i = 0; i < m; i++) { // setting up the checkpoints
        for (j = 0; j < n; j++) {
            a[i][j] = (i + 1) * 10 + (j + 1);
        }
    }
}

//main algo
void findpath(int m, int n, int arr[m][n], int sr, int sc, int er, int ec){
    int x, y = 0;
    printf("\n");
    if ((sr * 10 + sc) < (er * 10 + ec)) { // forward traversal, i.e. from lower to higher point
        if (sr == er) { // increase column-wise only
            printf("The checkpoints to be passed during the desired FORWARD traversal are:");
            printf("\n");
            printf("(Taking right, start walking straight.)\n");
            for (y = sc; y <= ec; y++) {
                printf("%d\n", arr[sr - 1][y - 1]);
            }
        } else if (sr < er) { // increase row-wise &then, increase/decrease column-wise
            printf("The checkpoints to be passed during the desired FORWARD traversal are:\n");
            printf("\n");
            printf("(Looking towards the UPPER SIDE, start walking straight.)\n");
            for (x = sr; x <= er; x++) {
                printf("%d\n", arr[x - 1][sc - 1]);
            }
            if (sc < ec) {
                printf("(Taking right, start walking straight.)\n");
                for (y = sc + 1; y <= ec; y++) {
                    printf("%d\n", arr[er - 1][y - 1]);
                }
            } else if (sc > ec) {
                printf("(Taking left, start walking straight.)\n");
                for (y = sc - 1; y >= ec; y--) {
                    printf("%d\n", arr[er - 1][y - 1]);
                }
            }
        }
    } else if ((sr * 10 + sc) > (er * 10 + ec)) { // backward traversal, i.e. from higher to lower point
        if (sr == er) { // decrease column-wise only
            printf("The checkpoints to be passed during the desired BACKWARD traversal are:\n");
            printf("\n");
            printf("(Taking left, start walking straight.)\n");
            for (y = sc; y >= ec; y--) {
                printf("%d\n", arr[sr - 1][y - 1]);
            }
        } else if (sr > er) { // decrease row-wise &then, increase/decrease column-wise
            printf("The checkpoints to be passed during the desired BACKWARD traversal are:");
            printf("\n");
            printf("(Looking towards the LOWER SIDE, start walking straight.)\n");
            for (x = sr; x >= er; x--) {
                printf("%d\n", arr[x - 1][sc - 1]);
            }
            if (sc < ec) {
                printf("(Taking left, start walking straight.)\n");
                for (y = sc + 1; y <= ec; y++) {
                    printf("%d\n", arr[er - 1][y - 1]);
                }
            } else if (sc > ec) {
                printf("(Taking right, start walking straight.)\n");
                for (y = sc - 1; y >= ec; y--) {
                    printf("%d\n", arr[er - 1][y - 1]);
                }
            }
        }
    } else {
        printf("No Move\n");
    }
    printf("(End up, looking towards the UPPER SIDE.)\n");
}