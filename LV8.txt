ZADATAK 1. (slucajno sam nesta zalijepio vamo ne znam što)

#include "nekiheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Kako bi autograder mogao uspjesno upisati strukturu u datoteku
morate koristiti ovako definirane strukture

struct podaci
{		
	char prezime[20];
	char ime[20];
	int sifra;
	char adresa[100];
	int br_tel;
};

*/

typedef struct podaci
{		
	char prezime[20];
	char ime[20];
	int sifra;
	char adresa[100];
	int br_tel;
}PODACI;

void kreiranjeDatoteke(char*);
void upisivanjeDatoteke(char*);
void citanjeDatoteke(char*);


int main(void){
    int a;
    char* ime = "clanovi.txt";
    

    
    do{
    printf("odaberite radnju:\n");
    printf("1 - Kreiranje datoteke %s\n", ime);
    printf("2 - Citanje iz datoteke %s\n", ime);
    printf("3 - Dodavanje novih clanova u %s\n", ime);
    printf("4 - Zavrsetak programa %s\n", ime);
    
    scanf("%d", &a);
    switch(a){
        case 1:
            kreiranjeDatoteke(ime);
            break;
        case 2:
            citanjeDatoteke(ime);
            break;
        case 3:
            upisivanjeDatoteke(ime);
            break;
        case 4:
            printf("Program se zatvara...\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Upisan je krivi broj\n");
    }
}while(a != 4);
    
return 0;
}


void kreiranjeDatoteke(char *file){
    FILE *c = NULL;
    c = fopen(file, "rb");
    if(c != NULL){
        printf("datoteka %s vec postoji\n", file);
        fclose(c);
        return;
    }
    
    c = fopen(file, "wb");
    if(c == NULL){
        fprintf(stderr,"Datoteka %s se ne moze kreirati\n", file);
        exit(EXIT_FAILURE);
    }
    printf("datoteka %s uspjesno kreirana\n", file);
    fclose(c);
    return;
}

void citanjeDatoteke(char* file){
    FILE *c = fopen(file, "rb");
    
    if(c == NULL){
        fprintf(stderr,"Datoteka %s se ne moze otvoriti", file);
        exit(EXIT_FAILURE);
    }
    PODACI podatak;
    int i=1;
    
    int br=0;
    while(fread(&podatak, sizeof(PODACI), 1, c) == 1){
        printf("Clan %d\n", i++);
        printf("Prezime:%s\n", podatak.prezime);
        printf("Ime:%s\n", podatak.ime);
        printf("Sifra:%d\n", podatak.sifra);
        printf("Adresa:%s\n", podatak.adresa);
        printf("Broj Telefona:%d\n", podatak.br_tel);
        br++;
    }
    
    if(br == 0){
        printf("Datoteka %s nema clanova", file);
    }
    fclose(c);
}

void upisivanjeDatoteke(char* file){
    FILE* c = fopen(file, "ab");
     
    

    
    if(c == NULL){
        printf("Datoteka %s se ne moze ucitati", file);
        fclose(c);
        exit(EXIT_FAILURE);
    }
    
    PODACI podatak = { 0 };
    printf("Upisite prezime:\n");
    scanf("%19s", podatak.prezime);
    printf("Upisite ime:\n");
    scanf("%19s", podatak.ime);
    printf("Upisite sifru:\n");
    scanf("%d", &podatak.sifra);
    
    while (getchar() != '\n');
    printf("Unesite adresu: \n");
    
    fgets(podatak.adresa, sizeof(podatak.adresa), stdin);
    podatak.adresa[strcspn(podatak.adresa, "\n")] = '\0';
    
    printf("Upisite broj telefona:\n");
    scanf("%d", &podatak.br_tel);
    
    fwrite(&podatak, sizeof(PODACI), 1, c);
    
    fclose(c);
}

