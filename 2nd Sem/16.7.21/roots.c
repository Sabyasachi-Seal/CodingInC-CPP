
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void roots(int, int, int);
int main(){
    int a, b, c;
    printf("Enter the values of a, b and c in the quadratic equation:");
    scanf("%d%d%d", &a, &b, &c);
	roots(a, b, c);
	return 0;
}
void roots(int a, int b, int c){
	int d = b * b - 4 * a * c;
	double discriminant = sqrt(abs(d));
	if (d > 0) {
		printf("Roots are real and different \n");
		printf("%f & %f", (double)(-b + discriminant) / (2 * a),
			(double)(-b - discriminant) / (2 * a));
	}
	else if (d == 0) {
		printf("Roots are real and same \n");
		printf("%f", -(double)b / (2 * a));
	}
	else{
		printf("Roots are complex \n");
	}
}

