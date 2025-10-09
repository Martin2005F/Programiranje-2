ZADATAK 1. 

// 1.	Korisnik treba unijeti cjelobrojnu vrijednost u rasponu od 1 do 7, 
//pri čemu 1 predstavlja ponedjeljak, a 7 nedjelju. 
//Ispisati poruku „Vikeeeend!“ ako je unesen broj koji označava neradne dane ili
//poruku „Radis jos %d dana do vikenda.“ ako je unesen broj koji označava radne dane.
//Za dane u tjednu koristiti enumeraciju.
#include <stdio.h>
enum dani{pon=1,uto,sri,cet,pet,sub,ned
};

int main(void){
    
   enum dani x;
    
    do{
        scanf("%d",&x);
    }while(x<pon || x>ned);
    
    printf("REZULTATI:\n");
    if(x == sub || x==ned){
        printf("Vikeeeend!");
    }else{
        printf("Radis jos %d dana do vikenda.",5-x);
    }
    
    return 0;
}


/*// ovo je main datoteka koja sadrži pozive svih potrebnih funkcija, nju ne trebate dirati

#include <stdio.h>
#include <stdlib.h>


typedef struct student {
	char *ime;
	char *prezime;
	int id;
	float prosjek;
	struct student* nextNode;
}STUDENT;

void inputNodeData(STUDENT*);
float prosjekSvih(STUDENT *);
STUDENT* createSLList(void);
void traverseSLList(STUDENT*);
STUDENT* insertNewNodeSLList(STUDENT*);
STUDENT* searchSLList(STUDENT*, int);
void deleteNodeSLList(STUDENT**, STUDENT*);
STUDENT* deleteWholeSLList(STUDENT*);


void inputNodeData(STUDENT* cvor){
    cvor->ime = (char*)malloc(sizeof(char));
    cvor->prezime = (char*)malloc(sizeof(char));
    
    scanf("%s", cvor->ime);
    scanf("%s", cvor->prezime);
    scanf("%d", &cvor->id);
    scanf("%f", &cvor->prosjek);
}

STUDENT* createSLList(void){
    STUDENT *headNode = NULL;
    STUDENT *novi = NULL;
    
    
        novi = (STUDENT*)malloc(sizeof(STUDENT));
        if(novi == NULL){
           perror("kreiranje");
           return NULL;
        }
         inputNodeData(novi);
         novi->nextNode = headNode;
         headNode = novi;
    return headNode;
}

STUDENT* insertNewNodeSLList(STUDENT* headNode){
    STUDENT *newHeadNode = (STUDENT*)malloc(sizeof(STUDENT));
    
    if(newHeadNode == NULL){
        perror("Kreiranje");
        return headNode;
    }
    else{
        inputNodeData(headNode);
        newHeadNode->nextNode = headNode;
    }
}

void traverseSLList(STUDENT* traverseNode){
    if(traverseNode == NULL){
        exit(EXIT_FAILURE);
    }else{
        while(traverseNode){
            printf("ID:%d %s %s,prosjek:%.2f\n", traverseNode->id, traverseNode->ime, traverseNode->prezime, traverseNode->prosjek);
            traverseNode = traverseNode->nextNode;
        }
    }
}

STUDENT *searchSLList(STUDENT* traverseNode, int criteria){
    while(traverseNode){
        if(traverseNode->id == criteria){
            return traverseNode;
        }
        traverseNode = traverseNode ->nextNode;
    }
}

void deleteNodeSLList(STUDENT** headNode, STUDENT* targetNode){
    if(targetNode == NULL){
        return;
    }
    if(*headNode == targetNode){
        *headNode = (*headNode)->nextNode;
        free(targetNode);
    }else{
        STUDENT* traverseNode = *headNode;
        while(traverseNode->nextNode){
            if(traverseNode->nextNode == targetNode){
                traverseNode->nextNode = targetNode->nextNode;
                free(targetNode);
                break;
            }
            traverseNode = traverseNode->nextNode;
        }
    }
}

STUDENT* deleteWholeSLList(STUDENT* traverseNode){
    STUDENT* deleteNode = NULL;
    while(traverseNode){
        deleteNode = traverseNode;
        traverseNode = traverseNode->nextNode;
        free(deleteNode);
    }
    return NULL;
}


float prosjekSvih(STUDENT *head){
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

int  main() {
	int n, i, x;
	
	STUDENT *headNode = NULL;
	STUDENT *targetNode = NULL;
	
	printf("Koliko studenata zelis unijeti? ");
	scanf("%d", &n);

	headNode = createSLList();                      // kreiranje povezanog popisa i umetanje prvog člana

	for (i = 0; i < n-1; i++)
	{
		headNode = insertNewNodeSLList(headNode);   // umetanje sljedećih n-1 članova
	}

	printf("Unesite ID studenta kojeg trazite\n");  // unos ID-a studenta kojeg tražimo i brišemo
	scanf("%d", &x);
	
	printf("REZULTATI:\n");
	
	traverseSLList(headNode);                       // obilazak povezanog popisa i ispis svih članova
	printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvih(headNode)); // izračun prosjeka svih studenata

	targetNode = searchSLList(headNode, x);         // traženje studenta preko ID-a

	if (targetNode == NULL) {
		printf("Student s trazenim ID-em nije pronadjen!\n");   // ispis poruke ako nije pronadjen
	}
	else {                                                      // ako je pronadjen
		deleteNodeSLList(&headNode, targetNode);                // brisanje studenta
		traverseSLList(headNode);                               // ponovni obilazak povezanog popisa i ispis svih članova
		printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvih(headNode)); // ponovni izračun prosjeka svih preostalih studenata
	}
	headNode = deleteWholeSLList(headNode);                     // oslobađanje memorije za cijeli povezani popis

	return 0;
}*/



ZADATAK 2.


// Implementirati makro koji racuna  indeks s u binarnom pretrazivanju (s = (dg+gg)/2).
//U glavnoj funkciji ucitati 500 brojeva iz datoteke in.txt te s tipkovnice traziti unos
//broja koji trazimo u danom polju u intervalu [1, 1000].
//Ispisati poruku „Broj nije nadjen.“ ili „Broj je nadjen.“ s obzirom na rezultat pretrazivanja.

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define bin(dg,gg) (dg+gg)/2

void swap (int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void selectionSort (int a[], int n) {
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (a[j] < a[min]) 
                min = j;
        swap(&a[i], &a[min]);
    }
}





int  main() {
	
	int p[500], x;
	

	
    FILE* c =fopen("in.txt", "r");
    
    if(c==NULL){
        return 0;
    }
    
    for(int i=0; i<500; i++){
        fscanf(c,"%d",&p[i]);
    }
    
    
    do{
        
    scanf("%d",&x);
    }while(x>1000 || x<1);
    
    
    selectionSort(p,x);
    
    
    int dg=0, gg=499, s;
    
printf("REZULTATI:\n");
while (dg<=gg) {
    s = bin(dg,gg);
    if (x == p[s]) {
       printf("Broj je nadjen.");
       break;

    }else if (x>p[s]) {
        dg = s+1;
    }
    else if (x<p[s]) {
        gg = s-1;
    }
}
if (dg>gg) 
    printf ("Broj nije nadjen.");
    
    

	
	
	return 0;
}
