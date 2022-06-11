#include <stdio.h>
#include <stdlib.h>

int main()
{
    int digits[10];
    int a, b, c, d, e, f, g, h, i, j;
    for(i=0; i<10; i++){
        digits[i] = 0;
    }
    for(a=0; a<110; a++){
        digits[a]++;
        for(b=0; b<10; b++){
            digits[b]++;
            for(c=0; c<10; c++){
                digits[c]++;
                for(d=0; d<10; d++){
                    digits[d]++;
                    for(e=0; e<10; e++){
                        digits[e]++;
                        for(f=0; f<10; f++){
                            digits[f]++;
                            for(g=0; g<10; g++){
                                digits[g]++;
                                for(h=0; h<10; h++){
                                    digits[h]++;
                                    for(i=0; i<10; i++){
                                        digits[i]++;
                                        for(j=0; j<10; j++){
                                            digits[j]++;
                                            if(digits[0] == a &&
                                               digits[1] == b &&
                                               digits[2] == c &&
                                               digits[3] == d &&
                                               digits[4] == e &&
                                               digits[5] == f &&
                                               digits[6] == g &&
                                               digits[7] == h &&
                                               digits[8] == i &&
                                               digits[9] == j){
                                                printf("\n%d%d%d%d%d%d%d%d%d%d",a, b, c, d, e, f, g, h, i, j);
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
