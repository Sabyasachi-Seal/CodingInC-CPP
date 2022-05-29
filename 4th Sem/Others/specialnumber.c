// Find the only 10 digit number where the digit at the ith position (i = 0, 1, 2, 3 etc.) from left specifies the number of occurrences of digit "i" in the given number.
// https://math.stackexchange.com/questions/1245953/a-10-digit-number-whose-nth-digit-gives-the-number-of-n-1s-in-it
#include <stdio.h>
int main(){
    int n = 10;
    int digits[n];
    for(int i=0; i<n; i++){
        digits[i] = 0;
    }
    for(int a=0; a<n; a++){
        digits[a]++;
        for(int b=0; b<n; b++){
            digits[b]++;
            for(int c=0; c<n; c++){
                digits[c]++;
                for(int d=0; d<n; d++){
                    digits[d]++;
                    for(int e=0; e<n; e++){
                        digits[e]++;
                        for(int f=0; f<n; f++){
                            digits[f]++;
                            for(int g=0; g<n; g++){
                                digits[g]++;
                                for(int h=0; h<n; h++){
                                    digits[h]++;
                                    for(int i=0; i<n; i++){
                                        digits[i]++;
                                        for(int j=0; j<n; j++){
                                            digits[j]++;
                                            if(a==digits[0] &&
                                                b==digits[1] &&
                                                c==digits[2] &&
                                                d==digits[3] &&
                                                e==digits[4] &&
                                                f==digits[5] &&
                                                g==digits[6] &&
                                                h==digits[7] &&
                                                i==digits[8] &&
                                                j==digits[9]){
                                                    printf("\n%d%d%d%d%d%d%d%d%d%d\n",a,b,c,d,e,f,g,h,i,j);
                                                }
                                            digits[j]--;
                                        }
                                        digits[i]--;
                                    }
                                    digits[h]--;
                                }
                                digits[g]--;
                            }
                            digits[f]--;
                        }
                        digits[e]--;
                    }
                    digits[d]--;
                }
                digits[c]--;
            }
            digits[b]--;
        }
        digits[a]--;
    }
    return 0;
}
void betterlooking(){
    int n = 10;
    int digits[n];
    for(int i=0; i<n; i++){
        digits[i] = 0;
    }

    for (int a = 0; a < n; a++)    {   digits[a]++;
    for (int b = 0; b < n; b++)    {   digits[b]++;
    for (int c = 0; c < n; c++)    {   digits[c]++;
    for (int d = 0; d < n; d++)    {   digits[d]++;
    for (int e = 0; e < n; e++)    {   digits[e]++;
    for (int f = 0; f < n; f++)    {   digits[f]++;
    for (int g = 0; g < n; g++)    {   digits[g]++;
    for (int h = 0; h < n; h++)    {   digits[h]++;
    for (int i = 0; i < n; i++)    {   digits[i]++;
    for (int j = 0; j < n; j++)    {   digits[j]++;

    if
    (
        (a == digits[0]) &&
        (b == digits[1]) &&
        (c == digits[2]) &&
        (d == digits[3]) &&
        (e == digits[4]) &&
        (f == digits[5]) &&
        (g == digits[6]) &&
        (h == digits[7]) &&
        (i == digits[8]) &&
        (j == digits[9])
    )

    printf("%d%d%d%d%d%d%d%d%d%d",a,b,c,d,e,f,g,h,i,j);

    digits[j]--;    }
    digits[i]--;    }
    digits[h]--;    }
    digits[g]--;    }
    digits[f]--;    }
    digits[e]--;    }
    digits[d]--;    }
    digits[c]--;    }
    digits[b]--;    }
    digits[a]--;    }
}
