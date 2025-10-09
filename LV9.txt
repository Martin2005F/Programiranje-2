ZADATAK 1. 

/*Rekurzija prima jednu cjelobrojnu vrijednost koja je visina piramide. 
U datoteku piramida.txt, koju ćete kreiratiiz programa,  „nacrtati“ piramidu od znakova '*' koja može imati maksimalnu visinu 30 redova. 
U main() dijelu učitati visinu piramide te pozvati rekurziju. Primjer piramide je prikazan niže.
n=5
     *
    *** 
   *****
  *******
 *********
 */
#include <stdio.h>
#include <stdlib.h>

char piramida(int visina, int red){
    if(red > visina){
        return 0;
    }
    
    for(int i=0; i < visina - red; i++){
        printf(" ");
    }
     
    for(int i=0; i < 2 * red -1; i++){
        printf("*");
    }
    printf("\n");
    return piramida(visina, red + 1);
}


int main(void){
    int n;
    
    char a;
    scanf("%d", &n);
    
    if(n<1 || n >30){
        return 0;
    }
    
    a = piramida(n, 1);
    FILE *p = fopen("piramida.txt", "w");
    
    if(p == NULL){
        exit(EXIT_FAILURE);
    }
}
 


ZADATAK 2.

main.c


/*Napisati C program koji će učitati cijeli broj te u datoteku naziva suma.txt te upisati sumu njegovih znamenaka.
Za traženje sume znamenaka broja koristiti rekurziju.
NAPOMENA: Zadatak pokazati nastavniku na satu, VPL nema testcase-ove.*/
#include "nekiheader.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a, zbroj=0;
    
    scanf("%d", &a);
    
    zbroj = suma(a);
    
    printf("%d", zbroj);
    
    FILE *p = fopen("suma.txt", "w");
    
    fprintf(p, "%d" , zbroj);
    fclose(p);
    
    return 0;
    
}

nekiheader.h

#ifndef MYHEADER_H
#define MYHEADER_H

int suma(int);

#endif


functions.c

#include <stdio.h>

int suma(int a){
int zbr= 0;
zbr = zbr + a%10;
if(a == 0)
    return 0;
else
    return zbr + suma(a/10);
}
