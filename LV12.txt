ZADATAK 1. 

// ovo je main datoteka koja sadrži pozive svih potrebnih funkcija, nju ne trebate dirati

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
    cvor->ime = (char*)malloc(50*sizeof(char));
    cvor->prezime = (char*)malloc(50*sizeof(char));
    
    scanf("%d", &cvor->id);
    scanf("%s", cvor->ime);
    scanf("%s", cvor->prezime);
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
        inputNodeData(newHeadNode);
        newHeadNode->nextNode = headNode;
        return newHeadNode;
    }
}

void traverseSLList(STUDENT* traverseNode){
    if(traverseNode == NULL){
        exit(EXIT_FAILURE);
    }else{
        while(traverseNode){
            printf("ID: %d - %s %s, prosjek: %.2f\n", traverseNode->id, traverseNode->ime, traverseNode->prezime, traverseNode->prosjek);
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
    return NULL;
}

void deleteNodeSLList(STUDENT** headNode, STUDENT* targetNode){
    if(targetNode == NULL){
        return;
    }
    if(*headNode == targetNode){
        *headNode = (*headNode)->nextNode;
        free(targetNode->ime);
        free(targetNode->prezime);
        free(targetNode);
    }else{
        STUDENT* traverseNode = *headNode;
        while(traverseNode->nextNode){
            if(traverseNode->nextNode == targetNode){
                traverseNode->nextNode = targetNode->nextNode;
                free(targetNode->ime);
                free(targetNode->prezime);
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
        free(deleteNode->ime);
        free(deleteNode->prezime);
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
}


