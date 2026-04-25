ZADATAK 1. 

main.c

#include <stdio.h>
#define N 500

int main(void){
    int A[N];
    int x, temp;
    int pronasli = 0, br = 0;
    
    FILE *c = fopen("in1.txt", "r");
    
    if(c == NULL){
        printf("Datoteka se ne moze otvoriti");
        return 1;
    }
    
    for(int i=0; i<N; i++){
        do{
            fscanf(c,"%d", &A[i]);
        }while(A[i]<0 || A[i]>1000);
    }
    fclose(c);
    
    
    scanf("%d",&x);
    
   if(x <0 || x >1000){
       printf("broj nije u intervalu\n");
       return 1;
   }
   
   for(int i=0; i<N; i++){
       
       if(A[i]==x){
           pronasli = 1;
           br++;
           break;
       }
       br++;
   }
   
   printf("REZULTATI:\n");
   if(pronasli){
       printf("Broj %d je pronadjen nakon %d koraka", x, br);
   } else{
       printf("Broj %d nije pronadjen", x);
   }
    return 0;
}



ZADATAK 2. (nije zavrsen do kraja)

main.c


#include <stdio.h>
#include <stdlib.h>
#define N 500
#define M 5
int sekvencijalno(int K[], int x){
    for(int i=0; i<N; i++){
        if(K[i] == x){
            return i+1;
        } 
    }
    return -1;
}

int binarno(int K[], int x){
    int dg, gg, s;
    int br=0;
    dg = 0;
    gg = N -1;
    
    while(dg <= gg){
        s = (dg +gg)/2;
        br++;
        if(x == K[s]){
            return br;
        }else if(x > K[s]){
            dg = s + 1;
        }else if(x < K[s]){
            gg = s -1;
        }
    }
    if(dg > gg){
        return -1;
    }
    
}

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main(void){
    int A[N];
    int x[M];
    int binBroj=0, binKo=0, svBroj=0, svKo=0;
    float srBin=0, srSv=0;
    
    FILE *c = fopen("in1.txt", "r");
    
    if(c == NULL){
        printf("datoteka se ne moze otvoriti");
        return 1;
    }
    for(int i=0; i<N; i++){
        do{
            fscanf(c,"%d", &A[i]);
        }while(A[i]<0 || A[i]>1000);
    }
    
    fclose(c);
    
    for(int i=0; i<M; i++){
        do{
            scanf("%d", &x[i]);
        }while(x[i] <= 0 || x[i] >=1000);
    }
    
    printf("REZULTATI:\n");
    printf("Sekvencijalno:\n");
    for(int i=0; i<M;i++){
        int koraci = sekvencijalno(A, x[i]);
        if(koraci == -1){
            printf("%d. broj %d nije pronadjen.\n",i+1, x[i]);
        }else{
            printf("%d. broj %d je pronadjen u %d koraka.\n", i +1, x[i], koraci);
            svBroj += 1;
            svKo +=koraci;
        }
    }
    printf("\n");
    printf("Binarno:\n");
    
    qsort(A, N, sizeof(int), compare);
    for(int i=0; i<M;i++){
        int koraci = binarno(A, x[i]);
        if(koraci == -1){
            printf("%d. broj %d nije pronadjen.\n", i+1,x[i]);
        }else{
            printf("%d. broj %d je pronadjen u %d koraka.\n", i +1, x[i], koraci);
            binKo +=koraci;
            binBroj += 1;
        }
    }
    
    
    printf("Srednji broj koraka za sekvencijalno pretrazivanje je: %.2f\n", (float)svKo/svBroj);
    printf("Srednji broj koraka za binarno pretrazivanje je: %.2f", (float)binKo/binBroj);
    
    return 0;
}



