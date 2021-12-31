#include <stdio.h>  
void equal(int, int);
int main(){     
    int a = 1, b = 200;        
    equal(a, b);
}
void equal(int a, int b){
    for(int i=a; i<=b; i++){
        int num = i;
        int c = (i<10)?1:(i<100)?2:3, d=1;
        int arr[c];
        while(num>0){
            arr[d] = num%10;
            num/=10;
            d++;
        }
        for(int j=1; j<=(c-1); j++){
            if(arr[j]==arr[j+1]&&i<100){
                printf("%d\n", i);
                break;
            }
            else if((arr[j]==arr[j+1]||arr[j]==arr[j+2]||arr[j+1]==arr[j+2])&&i>100){
                printf("%d\n", i);
                break;
            }
        }
    }
}