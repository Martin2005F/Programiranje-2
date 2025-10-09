ZADATAK 1.

main.c

#include "myheader.h"
#include <stdio.h>

#include<stdlib.h>

int main(void)
{
	int **M=NULL;
	int m, n, K;
	printf("Unesi n i m: ");
	//redoslijed unosa je n, m, K
	scanf("%d%d", &n, &m);

    printf("Unesi k: ");
    scanf("%d", &K);


	M = allocateMatrix(n, m);

	inputMatrix(M, n, m);

    matrixTimesK(M, n, m, K);

    printf("REZULTATI:\n");
    printMatrix(M, n, m);
    
    M = freeMemory(M, n);
    
	return 0;
}

myheader.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int** allocateMatrix(int, int);
void inputMatrix(int**, int, int);
void printMatrix(int**, int, int);
int  matrixTimesK(int**, int, int, int);
int** freeMemory(int**, int);

#endif


functions.c

#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int m, int n){
    int i;
    int** mat = NULL;
    
    mat = (int**)malloc(n * sizeof(int*));
    if(mat == NULL){
        return NULL;
    }
    
    for (i=0; i<n; i++){
        mat[i] = (int*)malloc(m * sizeof(int));
        if(mat[i] == NULL){
            return NULL;
        }
    }
    return mat;
}

void inputMatrix(int** mat, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", (*(mat + i)+j));
        }
    }
}

int** matrixTimesK(int **mat, int n, int m, int K){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            *(*(mat +i)+j) *= K;
        }
    }
    return mat;
}

void printMatrix(int** mat, int n, int m){
    for(int i=0; i<n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", *(*(mat +i)+j));
            
        }
        printf("\n");
    }
}

int** freeMemory(int** mat, int n){
    for(int i=0; i<n; i++){
        free(*(mat + i));
    }
    free(mat);
    
    return NULL;
}
