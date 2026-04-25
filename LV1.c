ZADATAK 1.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void poz(int *a, int negativan){
    int dec=0;
    
    for(int i=0; i<32; i++){
        if(a[31-i]==1){
            dec +=pow(2,i);
        }
    }
    if(negativan == 1){
        printf("%d", -dec);
    }else{
        printf("%d", dec);
    }
}


void neg(int *a){
    for(int i=0; i<32; i++){
        a[i] = (a[i]==0) ? 1 : 0;
    }
    for (int i=0; i<32; i++){
        if(a[31-i] ==0){
            a[31-i] = 1;
        }else{
            a[31-i] = 0;
        }
    }
    poz(a,1);
}

int main(void){
    int a[32];
    
    
    srand(time(NULL));
    
    for(int i=0; i<32;i++){
        a[i]= 0 + (rand() % (2-1+1));
        printf("%d", a[i]);
    }
    printf("\n");
    
    if(a[0]==1){
        neg(a);
    }else{
        poz(a,0);
    }
    
    return 0;
}
