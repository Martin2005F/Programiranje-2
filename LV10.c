ZADATAK 1. 

main.c

#include "myheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
    TOCKA *tocke;
    TROKUT *trokuti;
    
    int n,m;
    
    float Najopseg = 0;
    
    FILE* p = fopen("model.txt","r");
    
    if(p == NULL){
        printf("greska");
    }
    
    fscanf(p,"%d", &n);
    tocke = (TOCKA*)malloc(n * sizeof(TOCKA));
    
    if(tocke == NULL){
        printf("greska");
        return 1;
    }
    
    fscanf(p,"%d",&m);
    
    trokuti = (TROKUT *) malloc ( m * sizeof(TROKUT));
    
    if(trokuti == NULL){
        printf("greska");
        return 1;
    }
    
    inputData(p, tocke, trokuti, n,m);
    
    Najopseg = opseg(trokuti, m);
    
    printf("REZULTATI:\n");
    printf("%.2f", Najopseg);
    
    free(tocke);
    free(trokuti);
    trokuti == NULL;
    tocke == NULL;
    fclose(p);
    return 0;
}



myheader.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

typedef struct tocka{
    float x;
    float y;
    float z;
}TOCKA;

typedef struct trokut{
    TOCKA *t1;
    TOCKA *t2;
    TOCKA *t3;
}TROKUT;

void inputData(FILE*, TOCKA*, TROKUT*,int, int);
float len3d(TOCKA*, TOCKA*);
float opseg(TROKUT*, int);


functions.c

#include "myheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inputData(FILE *fp, TOCKA *p, TROKUT *t, int n, int m){
    int ind1, ind2, ind3;
    
    for(int i=0; i<n; i++){
        fscanf(fp, "%f%f%f", &p[i].x, &p[i].y, &p[i].z);
    }
    
    for(int i=0; i<m; i++){
        fscanf(fp,"%d%d%d", &ind1, &ind2, &ind3);
        t[i].t1 = &p[ind1];
        t[i].t2 = &p[ind2];
        t[i].t3 = &p[ind3];
    }
}

float len3d(TOCKA *p1, TOCKA *p2){
     return sqrt( pow(p2->x - p1->x, 2) + pow(p2->y - p1->y,2) + pow(p2->z - p1->z, 2));
}

float opseg(TROKUT* t, int m){
    float najOpseg=0, opseg;
    
    for(int i=0; i<m; i++){
        float a = len3d(t[i].t1, t[i].t2);
        printf("%.2f\n",a);
        float b = len3d(t[i].t2, t[i].t3);
         printf("%.2f\n",b);
        float c = len3d(t[i].t3, t[i].t1);
         printf("%.2f\n", c);
        opseg = a+b+c;
        
        if(opseg>najOpseg){
            najOpseg = opseg;
        }
    }
    return najOpseg;
}





STUDENT *createSLList(int n){
    STUDENT *headNode = NULL;
    STUDENT *novi = NULL;
    
    for(int i=0; i<n; i++){
        novi = (STUDENT*)malloc(sizeof(STUDENT));
        if( novi == NULL){
            perror("GRESKA PRI ALOKACIJI");
            exit(EXIT_FAILURE);
        }
        unosPodataka(novi);
        novi->nextNode = headNode;
        headNode = novi;
    }
    return headNode;
}

float prosjekStudenata(STUDENT *head){
    int brojac=0;
    float zbroj=0;
        
    while(head != NULL){
        zbroj +=head->prosjek;
        brojac++;
        head = head->nextNode;
    }
    if(zbroj == 0) return 0.0f;
    return zbroj/brojac;
}

prosjekStudenata(head);
