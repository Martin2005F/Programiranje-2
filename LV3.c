ZADATAK 1.

#include<stdio.h>
int main(){

char *mjeseci[]={ "sijecanj", "veljaca", "ozujak", "travanj", "svibanj", "lipanj", "srpanj", "kolovoz", "rujan", "listopad", "studeni", "prosinac"};
int mjesec;

scanf("%d", &mjesec);

if(mjesec >= 1 && mjesec <=12){
    printf("REZULTATI:\n");
    printf("%s\n", *(mjeseci + mjesec-1)); 
}else{
    printf("REZULTATI:\n");
    printf("Nekorektan broj mjeseca");
}
return 0;
}


ZADATAK 2.

#include<stdio.h>
#include<stdlib.h>
int najveci (int **a, int n, int m);

int main(){
        // a je matrica, m i n su dimenzije matrice
        int **a, m, n;
        
        // zbog testinih slucajeva potrebno je prvo unijeti velicinu n, a tek zatim m
        do{
            scanf("%d", &n);
        }while(n < 2 || n>5);//uvjeti za n
        
        do{
            scanf("%d", &m);
            //upis i provjera scanf-a za m
        }while(m < 2 || m > 8);//uvjeti za m
        
        a = (int**)calloc(n, sizeof(int*));
        if(a == NULL){
            return 1;
        }
        for (int i=0; i<n; i++){
            *(a+i) = (int*)calloc(m,sizeof(int));
            if(*(a + i) == NULL){
                return 1;
            }
        }
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                scanf("%d", (*(a+i)+j));
            }
        }
        //ovdje ide vas kod za upis dimenzija matrice i elemenata u matricu
        //pogledajte primjer 3 u LV
        
        //Ispis rezultata
        printf("\nREZULTATI:\n");
        printf("%d", najveci (a,n,m));
        
        for(int i=0; i<n; i++){
            free(*(a +i ));
        }
        
        free(a);
        return 0;
}
int najveci (int **a, int n, int m){
       int max=0;
       for(int i=0; i<n;i++){
           for(int j=0; j<m; j++){
               if(*(*(a +i)+j) > max){
                   max = *(*(a + i ) +j);
               }
           }
       }
       return max;
}

